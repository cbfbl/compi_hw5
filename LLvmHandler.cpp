
#include "LLvmHandler.h"

static string getLLvmType(TypeContainer* type_con);

LLvmHandler::LLvmHandler() : code_buffer(CodeBuffer::instance()){};

void LLvmHandler::binOpHandler(TypeContainer* action, TypeContainer* lhs,
                               TypeContainer* rhs) {
  string action_type = action->getName();
  string command = "";
  if (action_type == "*") {
    command += "mul ";
  } else if (action_type == "+") {
    command += "add ";
  } else if (action_type == "-") {
    command += "sub ";
  } else if (action_type == "/") {
    command += "sdiv ";
  }
  command += "i32 " + lhs->getRegister() + ", " + rhs->getRegister();
  code_buffer.emit(command);
}

void LLvmHandler::flushCodeBuffer() {
  code_buffer.printGlobalBuffer();
  code_buffer.printCodeBuffer();
};

void LLvmHandler::insertFunction(TypeContainer* ret, TypeContainer* id,
                                 TypeContainer* formals) {
  string command = "define " + getLLvmType(ret) + " @" + id->getName() + "(";
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
  code_buffer.emit(command);
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
  string type = getLLvmType(ret);
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

void LLvmHandler::setIdentLevel(unsigned int level) { ident_level = level; }

string LLvmHandler::tabs() {
  string tabs = "";
  for (int i = 0; i < ident_level; i++) {
    tabs += "\t";
  }
  return tabs;
}

static string getLLvmType(TypeContainer* type_con) {
  string type = type_con->getType();
  if (type == "INT" || type == "BYTE") {
    return "i32";
  }
  if (type == "VOID") {
    return "void";
  }
  if (type == "BOOL") {
    return "i1";
  }
}