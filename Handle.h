#ifndef _HANDLE_
#define _HANDLE_

#include "LLvmHandler.h"
#include "RegisterManager.h"
#include "Scope.h"
#include "source.hpp"

extern int yylineno;

class Handler {
  bool is_main_defined;
  string last_function_ret_type;
  Scope& table;
  LLvmHandler llvm_handler;
  RegisterManager reg_manager;
  bool printed_ret = false;

 public:
  Handler(Scope& parser_table);

  void flushCode();

  void programStart();

  void defineMain();
  void mainDefined();

  void updateLastFunctionRetType(TypeContainer* ret);

  void functionDeclaration();

  void createAndInsertFunction(TypeContainer* ret, TypeContainer* id,
                               TypeContainer* formals);
  void finishInsertFunction();

  TypeContainer* enumDeclaration(TypeContainer* id, TypeContainer* enum_list);

  TypeContainer* formalList(TypeContainer* formal_decl,
                            TypeContainer* formal_list);

  TypeContainer* enumratorList(TypeContainer* enum_list,
                               TypeContainer* enumrator);

  void insertVariable();
  


  void insertEnum(TypeContainer* enumtype, TypeContainer* id,
                  TypeContainer* exp);

  void AssignWithoutDec(TypeContainer* id, TypeContainer* exp);
  
  void decWithoutAssign(TypeContainer* type, TypeContainer* id);
  
  void decWithAssign(TypeContainer* type, TypeContainer* id, TypeContainer* exp);

  TypeContainer* functionCall(TypeContainer* func_id, TypeContainer* exp_list);

  TypeContainer* functionCallNoParams(TypeContainer* func_id);

  TypeContainer* typeInt(TypeContainer* int_type);

  TypeContainer* typeByte(TypeContainer* byte_type);

  TypeContainer* typeBool(TypeContainer* bool_type);

  TypeContainer* expBinop(TypeContainer* action, TypeContainer* lhs,
                           TypeContainer* rhs);

  void returnStatement(TypeContainer* exp);
  
  string getRegOrValue(TypeContainer* temp);

  TypeContainer* expId(TypeContainer* id);

  void expCall();

  TypeContainer* expNum(TypeContainer* num);

  void expNumB();

  void expNot();

  TypeContainer* expAnd(TypeContainer* lhs,TypeContainer* rhs);
  void andStart(TypeContainer* lhs);
  void andAfter(TypeContainer* lhs,TypeContainer* rhs);

  void expOr();

  TypeContainer* expRelop(TypeContainer* action,
                          TypeContainer* lhs, TypeContainer* rhs);


  TypeContainer* expLogop(TypeContainer* action,
                          TypeContainer* lhs, TypeContainer* rhs);

  TypeContainer* expReleq(TypeContainer* action, TypeContainer* lhs, TypeContainer* rhs);

  void casting();

  void insertScope();
  void removeScope();

  void allocStackSpace(TypeContainer* type, TypeContainer* id);
};

#endif
