
#include "LLvmHandler.h"

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
  string command = "define i32 @" + id->getName() + "(";
  vector<Id> formal_ids = ((FormalListClass*)formals)->getIds();
  auto it = formal_ids.begin();
  while (it != formal_ids.end()) {
    command += "i32 " + it->getName();
    it++;
    if (it != formal_ids.end()) {
      command += ", ";
    }
  }
  command += ") {";
  code_buffer.emit(command);
}
void LLvmHandler::finishInsertFunction() { code_buffer.emit("}"); }

void LLvmHandler::printFunctionsDefinitions() {
  string command = "declare i32 @printf(i8*, ...)\n";
  command += "declare void @exit(i32)\n";
  command += "@.int_specifier = constant [4 x i8] c\"%d\\0A\\00\"\n";
  command += "@.str_specifier = constant [4 x i8] c\"%s\\0A\\00\"\n";
  command += "define void @printi(i32) {\n";
  command +=
      "\tcall i32 (i8*, ...) printf(i8* getelementptr([4 x i8], [4 x i8]* "
      "@.int_specifier, i32 0, i32 0), i32 %0)\n";
  command += "\tret void\n}\n";
  command += "define void @print(i8*) {\n";
  command +=
      "\tcall i32 (i8*, ...) printf(i8* getelementptr([4 x i8], [4 x i8]* "
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