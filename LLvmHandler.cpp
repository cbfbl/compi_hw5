
#include "LLvmHandler.h"

static string getLLvmType(string type);

LLvmHandler::LLvmHandler()
    : code_buffer(CodeBuffer::instance()), ident_level(0){};

void LLvmHandler::binOpHandler(TypeContainer* action, string target_reg,
                               string lhs_reg, string rhs_reg) {
  string action_type = action->getName();
  string command = target_reg + " = ";
  if (action_type == "*") {
    command += "mul ";
  } else if (action_type == "+") {
    command += "add ";
  } else if (action_type == "-") {
    command += "sub ";
  } else if (action_type == "/") {
    command += "sdiv ";
  }
  command += "i32 " + lhs_reg + ", " + rhs_reg;
  code_buffer.emit(command);
}


void LLvmHandler::flushCodeBuffer() {
  code_buffer.printGlobalBuffer();
  code_buffer.printCodeBuffer();
};

void LLvmHandler::insertFunction(TypeContainer* ret, TypeContainer* id,
                                 TypeContainer* formals) {
  string command =
      "define " + getLLvmType(ret->getType()) + " @" + id->getName() + "(";
  vector<Id> formal_ids = ((FormalListClass*)formals)->getIds();
  auto it = formal_ids.begin();
  while (it != formal_ids.end()) {
    command += "i32 %" + it->getName();
    it++;
    if (it != formal_ids.end()) {
      command += ", ";
    }
  }
  command += ") {";
  code_buffer.emit(tabs() + command);
}
void LLvmHandler::finishInsertFunction(bool no_void) {
  string command = "";
  if (no_void) {
    command += "ret void";
  }
  command += "\n}";
  code_buffer.emit(tabs() + command);
}

void LLvmHandler::insertReturn(TypeContainer* ret) {
  string type = getLLvmType(ret->getType());
  code_buffer.emit("ret " + type + "\n");
}

void LLvmHandler::printFunctionsDefinitions() {
  string command = "declare i32 @printf(i8*, ...)\n";
  command += "declare void @exit(i32)\n";
  command += "@.int_specifier = constant [4 x i8] c\"%d\\0A\\00\"\n";
  command += "@.str_specifier = constant [4 x i8] c\"%s\\0A\\00\"\n";
  command += "define void @printi(i32) {\n";
  command +=
      "\tcall i32 (i8*, ...)* @printf(i8* getelementptr( [4 x i8]* "
      "@.int_specifier, i32 0, i32 0), i32 %0)\n";
  command += "\tret void\n}\n";
  command += "define void @print(i8*) {\n";
  command +=
      "\tcall i32 (i8*, ...)* @printf(i8* getelementptr( [4 x i8]* "
      "@.str_specifier, i32 0, i32 0), i8* %0)\n";
  command += "\tret void\n}";
  code_buffer.emitGlobal(command);
}

void LLvmHandler::functionCall(string ret_type, TypeContainer* id,
                               TypeContainer* exp_list) {
  string command = "";
  command +=
      "call " + getLLvmType(ret_type) + " @" + id->getName() + "(PARAMS)";
  code_buffer.emit(command);
}

void LLvmHandler::increaseIdent() { ident_level++; }
void LLvmHandler::decreaseIdent() { ident_level--; }

string LLvmHandler::tabs() {
  string tabs = "";
  for (int i = 0; i < ident_level; i++) {
    tabs += "\t";
  }
  return tabs;
}

void LLvmHandler::allocStackSpace(TypeContainer* type, TypeContainer* id) {
  string command = "";
  command += "%" + id->getName() + " = alloca i32, align 4";
  code_buffer.emit(command);
}

static string getLLvmType(string type) {
  if (type == "INT" || type == "BYTE") {
    return "i32";
  }
  if (type == "VOID") {
    return "void";
  }
  if (type == "BOOL") {
    return "i1";
  }
  throw exception();
}
