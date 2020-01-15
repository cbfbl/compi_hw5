#ifndef _LLVM_HNDL
#define _LLVM_HNDL

#include "bp.hpp"
#include "source.hpp"

class LLvmHandler {
  CodeBuffer& code_buffer;
  unsigned int ident_level = 0;
  string tabs();

 public:
  LLvmHandler();
  void binOpHandler(TypeContainer* action, TypeContainer* lhs,
                    TypeContainer* rhs);
  void flushCodeBuffer();

  void insertFunction(TypeContainer* ret, TypeContainer* id,
                      TypeContainer* formals);
  void finishInsertFunction(bool no_void);

  void printFunctionsDefinitions();

  void setIdentLevel(unsigned int level);

  void insertReturn(TypeContainer* ret);
};

#endif