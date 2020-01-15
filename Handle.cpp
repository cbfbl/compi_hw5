
#include "Handle.h"
#include "Scope.h"
#include "hw3_output.hpp"
#include "source.hpp"

vector<ScopeData> createFuncArgsVec2(TypeContainer* formals);
void notDefined2(Scope& table, TypeContainer* con);
string getActualType2(Scope& table, TypeContainer* some_data);
bool areTypesEqual(string type1, string type2);
void numCheck2(Scope& table, TypeContainer* con);
TypeContainer* binOpType2(RegisterManager& reg_manager, TypeContainer* lhs,
                          TypeContainer* rhs);
void enumTypeCheck2(Scope& table, TypeContainer* enumtype, TypeContainer* id,
                    TypeContainer* exp);
void notDefinedVariable2(Scope& table, TypeContainer* con);
void typeCheck2(Scope& table, TypeContainer* lhs, TypeContainer* rhs);

Handler::Handler(Scope& parser_table)
    : table(parser_table),
      last_function_ret_type(""),
      is_main_defined(false),
      printed_ret(false) {}

void Handler::flushCode() { llvm_handler.flushCodeBuffer(); }

void Handler::programStart() {
  table.insertScope();
  vector<string> print_func_args;
  vector<string> printi_func_args;
  print_func_args.push_back("STRING");
  printi_func_args.push_back("INT");
  string print_func_type = makeFunctionType("VOID", print_func_args);
  string printi_func_type = makeFunctionType("VOID", printi_func_args);
  table.addFuncData(
      ScopeData("print", 0, print_func_type, print_func_args, true, false));
  table.addFuncData(
      ScopeData("printi", 0, printi_func_type, printi_func_args, true, false));
  llvm_handler.printFunctionsDefinitions();
}

void Handler::defineMain() { this->is_main_defined = true; }

void Handler::mainDefined() {
  if (!is_main_defined) {
    errorMainMissing();
    exit(0);
  }
  ScopeData main_data = table.getDataCopy("main");
  if (main_data.getTypeCopy() != "()->VOID") {
    errorMainMissing();
    exit(0);
  }
}

void Handler::updateLastFunctionRetType(TypeContainer* ret) {
  this->last_function_ret_type = ret->getType();
}

void Handler::functionDeclaration(){};

void Handler::createAndInsertFunction(TypeContainer* ret, TypeContainer* id,
                                      TypeContainer* formals) {
  vector<string> formals_ids = ((FormalListClass*)formals)->getNames();
  // formals_ids can shadow others ??
  vector<string> formals_types = formals->getTypes();
  string func_type = makeFunctionType(ret->getType(), formals_types);
  vector<ScopeData> created_args = createFuncArgsVec2(formals);
  vector<string> WORKONTHIS;
  // ScopeData new_data = ScopeData(id->getName(), 0, func_type);
  ScopeData new_data =
      ScopeData(id->getName(), 0, func_type, formals_types, true, false);
  table.addFuncData(new_data);
  table.insertScope();
  table.insertFuncArgs(created_args);
  llvm_handler.insertFunction(ret, id, formals);
}

void Handler::finishInsertFunction() {
  if (!printed_ret) {
    llvm_handler.finishInsertFunction(!printed_ret);
  }
  printed_ret = false;
}

TypeContainer* Handler::enumDeclaration(TypeContainer* id,
                                        TypeContainer* enum_list) {
  vector<string> enum_names = ((FormalListClass*)enum_list)->getNames();
  int scope_level = 0;
  ScopeData new_data = ScopeData(id->getName(), scope_level, "ENUM_CONTAINER",
                                 enum_names, false, true);
  table.addScopeData(new_data);
  return new FormalListClass(id->getName(),
                             ((FormalListClass*)enum_list)->getIds());
}

TypeContainer* Handler::formalList(TypeContainer* formal_decl,
                                   TypeContainer* formal_list) {
  vector<string> vec1 = ((FormalListClass*)formal_decl)->getNames();
  vector<string> vec2 = ((FormalListClass*)formal_list)->getNames();
  string formal_id = vec1[0];
  ((FormalListClass*)formal_decl)
      ->addIds(((FormalListClass*)formal_list)->getIds());
  return formal_decl;
}

TypeContainer* Handler::enumratorList(TypeContainer* enum_list,
                                      TypeContainer* enumrator) {
  ((FormalListClass*)enumrator)
      ->addIds(((FormalListClass*)enum_list)->getIds());
  return enumrator;
}

void Handler::insertVariable() {}

void Handler::insertEnum(TypeContainer* enumtype, TypeContainer* id,
                         TypeContainer* exp) {
  enumTypeCheck2(table, enumtype, id, exp);
  table.addScopeData(ScopeData(id->getName(), table.getNextOffset(),
                               "enum " + enumtype->getName()));
}

void Handler::assignWithoutDecl(TypeContainer* id, TypeContainer* exp) {
  notDefinedVariable2(table, id);
  typeCheck2(table, id, exp);
}

TypeContainer* Handler::functionCall(TypeContainer* func_id,
                                     TypeContainer* exp_list) {
  ScopeData func_data = table.getDataCopy(func_id->getName());
  vector<string> func_def_types = func_data.getEnumValues();
  vector<string> explist_params = exp_list->getTypes();
  if (func_def_types.size() != explist_params.size()) {
    errorPrototypeMismatch(yylineno, func_id->getName(), func_def_types);
    exit(0);
  }
  for (int i = 0; i < func_def_types.size(); i++) {
    bool res = areTypesEqual(func_def_types[i], explist_params[i]);
    if (!res) {
      errorPrototypeMismatch(yylineno, func_id->getName(), func_def_types);
      exit(0);
    }
  }
  string call_type = getActualType2(table, func_id);
  if (call_type == "INT") {
    return new Int(0, call_type);
  } else if (call_type == "BOOL") {
    return new Bool(true, call_type);
  } else if (call_type == "BYTE") {
    return new Byte(0, call_type);
  } else {
    string no_str = "";
    return new Enum(no_str, call_type);
  }
}

TypeContainer* Handler::functionCallNoParams(TypeContainer* func_id) {
  ScopeData func_data = table.getDataCopy(func_id->getName());
  vector<string> func_params = func_data.getEnumValues();
  if (func_params.size() != 0) {
    errorPrototypeMismatch(yylineno, func_id->getName(), func_params);
    exit(0);
  }
  string call_type = getActualType2(table, func_id);
  if (call_type == "INT") {
    return new Int(0, call_type);
  } else if (call_type == "BOOL") {
    return new Bool(true, call_type);
  } else if (call_type == "BYTE") {
    return new Byte(0, call_type);
  } else {
    string no_str = "";
    return new Enum(no_str, call_type);
  }
}

TypeContainer* Handler::typeInt(TypeContainer* int_type) {
  int_type->setRegister(reg_manager.getRegister());
  return int_type;
}

TypeContainer* Handler::typeByte(TypeContainer* byte_type) {
  byte_type->setRegister(reg_manager.getRegister());
  return byte_type;
}

TypeContainer* Handler::typeBool(TypeContainer* bool_type) {
  bool_type->setRegister(reg_manager.getRegister());
  return bool_type;
}

TypeContainer* Handler::expBinopH(TypeContainer* action, TypeContainer* lhs,
                                  TypeContainer* rhs) {
  numCheck2(table, lhs);
  numCheck2(table, rhs);
  llvm_handler.binOpHandler(action, lhs, rhs);
  TypeContainer* ret_val = binOpType2(reg_manager, lhs, rhs);
  reg_manager.removeRegister(lhs->getRegister());
  reg_manager.removeRegister(rhs->getRegister());
  return ret_val;
}

TypeContainer* Handler::expBinopL(TypeContainer* action, TypeContainer* lhs,
                                  TypeContainer* rhs) {
  numCheck2(table, lhs);
  numCheck2(table, rhs);
  llvm_handler.binOpHandler(action, lhs, rhs);
  TypeContainer* ret_val = binOpType2(reg_manager, lhs, rhs);
  reg_manager.removeRegister(lhs->getRegister());
  reg_manager.removeRegister(rhs->getRegister());
  return ret_val;
}

void Handler::returnStatement(TypeContainer* exp) {
  llvm_handler.insertReturn(exp);
  printed_ret = true;
  if (exp == NULL) {
    if (last_function_ret_type != "VOID") {
      errorMismatch(yylineno);
      exit(0);
    }
    return;
  }
  if (last_function_ret_type == "VOID") {
    errorMismatch(yylineno);
    exit(0);
  }
  string exp_type = getActualType2(table, exp);
  if (!(last_function_ret_type == "INT" && exp_type == "BYTE")) {
    if (exp_type != last_function_ret_type) {
      errorMismatch(yylineno);
      exit(0);
    }
  }
}

TypeContainer* Handler::expId(TypeContainer* id) {
  id->setRegister(reg_manager.getRegister());
  return id;
}

void Handler::expCall() {}

TypeContainer* Handler::expNum(TypeContainer* num) {
  num->setRegister(reg_manager.getRegister());
  return num;
}

void Handler::expNumB() {}

void Handler::expNot() {}

void Handler::expAnd() {}

void Handler::expOr() {}

TypeContainer* Handler::expRelop(TypeContainer* lhs, TypeContainer* rhs) {
  numCheck2(table, lhs);
  numCheck2(table, rhs);
  return new Bool(true, "BOOL");
}

TypeContainer* Handler::expReleq(TypeContainer* lhs, TypeContainer* rhs) {
  return expRelop(lhs, rhs);
}

void Handler::casting() {}

void Handler::insertScope() {
  table.insertScope();
  llvm_handler.increaseIdent();
}

void Handler::removeScope() {
  table.removeScope();
  llvm_handler.decreaseIdent();
}

/*

problems : $1->getName() does return error if called again

*/

void numCheck2(Scope& table, TypeContainer* con) {
  string type = getActualType2(table, con);
  if (type != "INT" && type != "BYTE") {
    errorMismatch(yylineno);
    exit(0);
  }
}

bool areTypesEqual(string type1, string type2) {
  if (type1 == type2) {
    return true;
  }
  if (type1 == "INT" && type2 == "BYTE") {
    return true;
  }
  return false;
}

TypeContainer* binOpType2(RegisterManager& reg_manager, TypeContainer* lhs,
                          TypeContainer* rhs) {
  string type_one = lhs->getType();
  string type_two = rhs->getType();
  TypeContainer* ret = NULL;
  if (type_one == "INT" || type_two == "INT") {
    ret = new Int(lhs->getVal() + rhs->getVal(), "INT");
  } else {
    ret = new Int(lhs->getVal() + rhs->getVal(), "BYTE");
  }
  ret->setRegister(reg_manager.getRegister());
  return ret;
}

vector<ScopeData> createFuncArgsVec2(TypeContainer* formals) {
  vector<Id> id_vec = ((FormalListClass*)formals)->getIds();
  vector<ScopeData> output_vec;
  int i = -1;
  for (Id id : id_vec) {
    output_vec.push_back(ScopeData(id.getName(), i, id.getType()));
    i--;
  }
  return output_vec;
}

string getActualType2(Scope& table, TypeContainer* some_data) {
  string type = some_data->getType();
  if (type == "ID") {
    notDefined2(table, some_data);
    type = table.getDataCopy(some_data->getName()).getTypeCopy();
    std::size_t location = type.find("->");
    if (location == std::string::npos) {
      return type;
    }
    type = type.substr(location + 2);
  }
  return type;
}

void notDefined2(Scope& table, TypeContainer* con) {
  if (table.exist(con->getName()) == false ||
      table.getDataCopy(con->getName()).isEnum()) {
    errorUndef(yylineno, con->getName());
    exit(0);
  }
}

void enumTypeCheck2(Scope& table, TypeContainer* enumtype, TypeContainer* id,
                    TypeContainer* exp) {
  if (!table.exist(enumtype->getName())) {
    errorUndefEnum(yylineno, enumtype->getName());
    exit(0);
    return;  // no enum
  }
  string exp_type = getActualType2(table, exp);
  size_t space_pos = exp_type.find(" ");
  if (space_pos != string::npos) {
    if (exp_type.substr(space_pos + 1) != enumtype->getName()) {
      errorUndefEnumValue(yylineno, id->getName());
      exit(0);
      return;  // unmatch enum
    } else {
      return;  // good
    }
  } else {
    errorUndefEnumValue(yylineno, id->getName());
    exit(0);
    return;  // unmatch enum
  }
}

void notDefinedVariable2(Scope& table, TypeContainer* con) {
  if (table.exist(con->getName()) == false ||
      table.getDataCopy(con->getName()).isEnum()) {
    errorUndef(yylineno, con->getName());
    exit(0);
  }
  if (table.getDataCopy(con->getName()).isFunction()) {
    errorUndef(yylineno, con->getName());
    exit(0);
  }
}

void typeCheck2(Scope& table, TypeContainer* lhs, TypeContainer* rhs) {
  string type_lhs = getActualType2(table, lhs);
  string type_rhs = getActualType2(table, rhs);
  if (type_lhs == type_rhs || type_lhs == "INT" && type_rhs == "BYTE") {
    return;
  }
  if (type_lhs.find(" ") != string::npos) {
    errorUndefEnumValue(yylineno, lhs->getName());
    exit(0);
  }
  errorMismatch(yylineno);
  exit(0);
}