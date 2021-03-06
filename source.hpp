#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

class TypeContainer {
 public:
  string type;
  string reg;
  string getRegister() { return reg; };
  void setRegister(string _reg) { reg = _reg; };
  TypeContainer(string some_type) : type(some_type), reg(""){};
  TypeContainer() : type("NO_TYPE"), reg(""){};
  void printData() { std::cout << type << endl; }
  string getType() { return type; };
  vector<string> virtual getTypes(){};
  void virtual printContent(){};
  int virtual getVal(){};
  bool virtual getValue(){};
  string virtual getName(){};
  void virtual addType(string some_type){};
  void virtual addTypes(vector<string> to_add_types){};
};

class Int : public TypeContainer {
  int val;

 public:
  Int(char* yytext, string type) : val(atoi(yytext)), TypeContainer(type){};
  Int(int in_val, string type) : val(in_val), TypeContainer(type){};
  int getVal() { return val; };
};

class Byte : public TypeContainer {
  int byt;

 public:
  Byte(char* yytext, string type) : byt(atoi(yytext)), TypeContainer(type){};
  Byte(int val, string type) : byt(val), TypeContainer(type){};
};

class Id : public TypeContainer {
  string name;

 public:
  Id(char* yytext, string type) : name(yytext), TypeContainer(type){};
  Id(string yytext, string type) : name(yytext), TypeContainer(type){};
  string getName() { return name; };
};

class Bool : public TypeContainer {
  bool val;

 public:
  Bool(char* yytext, string type) : TypeContainer(type) {
    string current_str(yytext);
    if (current_str == "true") {
      val = true;
    } else if (current_str == "false") {
      val = false;
    }
    val = false;
  }
  Bool(bool in_val, string type) : val(in_val), TypeContainer(type){};
  bool getValue() { return val; };
};

class Void : public TypeContainer {
 public:
  Void(string type) : TypeContainer(type){};
};

class String : public TypeContainer {
  string my_str;

 public:
  String(char* yytext, string type) : my_str(yytext), TypeContainer(type) {}
  void printContent() { cout << my_str << endl; }
};

class Enum : public TypeContainer {
  string id;

 public:
  vector<string> enum_types;
  Enum(char* yytext, string type) : id(yytext), TypeContainer(type){};
  Enum(string given_id, string type) : id(given_id), TypeContainer(type){};
  void addTypes(vector<string> to_add) { enum_types = to_add; }
  string getName() { return id; }
};

class ExpList : public TypeContainer {
  vector<string> types;

 public:
  ExpList(string type) : TypeContainer(type) { types.push_back(type); }
  void addType(string type) { types.push_back(type); }
  vector<string> getTypes() { return types; }
  void addTypes(vector<string> to_add_types) {
    for (string type : to_add_types) {
      types.push_back(type);
    }
  }
  void printContent() {
    for (string i : types) {
      cout << "Exp type is : " << i << " ";
    }
  }
};

class FormalListClass : public TypeContainer {
  vector<Id> formals;
  string name = "";

 public:
  FormalListClass() : TypeContainer(){};
  FormalListClass(Id id) : TypeContainer(id.getType()) {
    formals.emplace_back(id);
  }
  FormalListClass(string got_id, vector<Id> form)
      : name(got_id), TypeContainer() {
    for (Id id : form) {
      formals.push_back(id);
    }
  };
  string getName() { return name; }
  void addId(Id id) { formals.emplace_back(id); }
  vector<Id> getIds() { return formals; }
  void addIds(vector<Id> id_list) {
    for (Id id : id_list) {
      formals.emplace_back(id);
    }
  }
  vector<string> getTypes() {
    vector<string> output_vec;
    for (Id id : formals) {
      output_vec.push_back(id.getType());
    }
    return output_vec;
  }
  vector<string> getNames() {
    vector<string> output_vec;
    for (Id id : formals) {
      output_vec.push_back(id.getName());
    }
    return output_vec;
  }
};

class BinOp : public TypeContainer {
  string action;

 public:
  BinOp(string _action, string type) : action(_action), TypeContainer(type) {}
  string getName() { return action; }
};

class LogicalOp : public TypeContainer {
  string action;

 public:
  LogicalOp(string _action, string type)
      : action(_action), TypeContainer(type) {}
  string getName() { return action; }
};

class RelOp : public TypeContainer {
  string action;

 public:
  RelOp(string _action, string type) : action(_action), TypeContainer(type) {}
  string getName() { return action; }
};

#define YYSTYPE TypeContainer*

#endif /* SOURCE_HPP */
