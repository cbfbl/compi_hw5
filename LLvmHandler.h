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
  void binOpHandler(TypeContainer* action, string target_reg,
                    string lhs_reg, string rhs_reg);
  
  void relOpHandler(TypeContainer* action, string target_reg,
                    string lhs_reg, string rhs_reg);
  
  void flushCodeBuffer();

  void insertFunction(TypeContainer* ret, TypeContainer* id,
                      TypeContainer* formals);
  void finishInsertFunction(bool no_void);

  void printFunctionsDefinitions();

  void functionCall(string ret_type, TypeContainer* id,
                    TypeContainer* exp_list);

  void increaseIdent();

  void decreaseIdent();

  void insertReturn(TypeContainer* ret);

  void allocStackSpace(TypeContainer* type, TypeContainer* id);

  void storeValue(string value, string target);
  
  void load(string out,string in);

  void store(string out,string in);

  void zext(string out,string in,string out_type,string in_type);

  void brWithCond(string cond_loc,string true_label, string false_label);

  void trunc(string out, string in, string type_to);

  void br(string jump_label);

  void magicalPhi(string type,string out ,string label1,string in1,string label2,string in2);

  void cmp(string out , string cond , string type,string in1,string in2 );

  void call(string out,string ret_type,string name, vector<string> types,vector<string> ins);

  void bit_and(string type,string out, string in1,string in2);

  void bit_or(string type,string out, string in1, string in2);

};

#endif
