

#include "Scope.h"
#include <algorithm>
#include <stdexcept>

bool Scope::exist(string id) {
  for (auto const& current_scope : symbol_table) {
    if (current_scope.find(id) != current_scope.end()) {
      return true;
    }
  }
  for (vector<pair<string, string>> curr_vec : enum_ids) {
    for (pair<string, string> enum_id : curr_vec) {
      if (id == enum_id.first || id == enum_id.second) {
        return true;
      }
    }
  }
  return false;
}

void Scope::insertScope() {
  if (offsetStack.size() == 0) {
    offsetStack.push(0);
  } else {
    offsetStack.push(offsetStack.top());
  }
  symbol_table.push_back(unordered_map<string, ScopeData>());
  insertion_order.push_back(vector<string>());
  enum_ids.push_back(vector<pair<string, string>>());
  func_args_vec.push_back(vector<string>());
}

void Scope::removeScope() {
  offsetStack.pop();
  symbol_table.pop_back();
  insertion_order.pop_back();
  enum_ids.pop_back();
  func_args_vec.pop_back();
}

void Scope::addScopeData(ScopeData scope_data) {
  (symbol_table.back())[scope_data.getNameCopy()] = scope_data;
  insertion_order.back().push_back(scope_data.getNameCopy());
  vector<string> enum_values = scope_data.getEnumValues();
  if (enum_values.size() == 0) offsetStack.top() += 1;
  for (string enum_id : enum_values) {
    enum_ids.back().push_back(make_pair(scope_data.getNameCopy(), enum_id));
  }
}

void Scope::addFuncData(ScopeData scope_data) {
  (symbol_table.back())[scope_data.getNameCopy()] = scope_data;
  insertion_order.back().push_back(scope_data.getNameCopy());
}

void Scope::printData() {
  int i = (int)insertion_order.size() - 1;
  if (i < 0) return;
  for (vector<vector<string>>::reverse_iterator l_scope =
           insertion_order.rbegin();
       l_scope != insertion_order.rend(); l_scope++) {
    vector<string>& curr = *l_scope;
    vector<ScopeData> enums_to_print;
    for (auto it = curr.begin(); it != curr.end(); it++) {
      string symbol = *it;
      ScopeData& to_print = symbol_table[i][symbol];
      if (to_print.getEnumValues().size() != 0 && to_print.isEnum()) {
        enums_to_print.push_back(to_print);
      } else {
        printID(to_print.getNameCopy(), to_print.getRelLocationCopy(),
                to_print.getTypeCopy());
      }
    }
    /* print ScopeDatas of enums */
    if (enums_to_print.size() > 0) {
      for (auto enum_to_print : enums_to_print) {
        vector<string> temp = enum_to_print.getEnumValues();
        std::reverse(temp.begin(), temp.end());
        printEnumType(enum_to_print.getNameCopy(), temp);
      }
    }
    i--;
  }
}

void Scope::printLastScopeData() {
  int i = (int)symbol_table.size() - 1;
  if (i < 0) return;
  vector<string>& last = insertion_order.back();
  last.insert(last.begin(), func_args_vec.back().begin(),
              func_args_vec.back().end());
  vector<ScopeData> enums_to_print;
  for (auto it = last.begin(); it != last.end(); it++) {
    string symbol = *it;
    ScopeData& to_print = symbol_table[i][symbol];
    if (to_print.getEnumValues().size() != 0 && to_print.isEnum()) {
      enums_to_print.push_back(to_print);
    } else {
      printID(to_print.getNameCopy(), to_print.getRelLocationCopy(),
              to_print.getTypeCopy());
    }
  }
  /* print ScopeDatas of enums */
  if (enums_to_print.size() > 0) {
    for (auto enum_to_print : enums_to_print) {
      vector<string> temp = enum_to_print.getEnumValues();
      std::reverse(temp.begin(), temp.end());
      printEnumType(enum_to_print.getNameCopy(), temp);
    }
  }
}

void Scope::printTable() {
  for (auto scope : symbol_table) {
    for (auto symbol : scope) {
      std::cout << "name is - " << symbol.first;
      std::cout << " and the type is - " << symbol.second.getTypeCopy()
                << std::endl;
    }
  }
}

int Scope::getNextOffset() { return offsetStack.top(); }

ScopeData Scope::getDataCopy(string id) {
  for (unordered_map<string, ScopeData> curr_scope : symbol_table) {
    if (curr_scope.find(id) != curr_scope.end()) {
      return (curr_scope.find(id))->second;
    }
  }
  for (vector<pair<string, string>> curr_vec : enum_ids) {
    for (pair<string, string> curr_id : curr_vec) {
      if (curr_id.second == id) {
        return ScopeData(id, 0, "enum " + curr_id.first);
      }
    }
  }
  //  printTable();
  throw std::exception();
}

void Scope::insertFuncArgs(vector<ScopeData> func_args) {
  for (ScopeData data : func_args) {
    //    std::cout << "inserting - " << data.getNameCopy() << " of type " <<
    //    data.getTypeCopy() << std::endl;;
    symbol_table.back()[data.getNameCopy()] = data;
    func_args_vec.back().push_back(data.getNameCopy());
  }
}

string Scope::getParentEnumId(string enum_id) {
  for (unordered_map<string, ScopeData> curr_scope : symbol_table) {
    for (auto data : curr_scope) {
      if (data.second.getEnumValues().size() != 0 && data.second.isEnum()) {
        for (string curr_enum_id : data.second.getEnumValues()) {
          if (enum_id == curr_enum_id) {
            return data.second.getNameCopy();
          }
        }
      }
    }
  }
  throw std::exception();
}

bool Scope::findGlobalEnum(string glob_enum) {
  for (string curr_glob : global_enums) {
    if (curr_glob == glob_enum) {
      return true;
    }
  }
  return false;
}

void Scope::insertGlobalEnum(string glob_enum) {
  global_enums.push_back(glob_enum);
}

// void Scope::insertIdentifiers(string ids){
//  identifiers.push_back(ids);
//}
//
//
//
// bool Scope::IdOnly(string id){
//  for (string curr : identifiers){
//    if (curr == id){
//      return true;
//    }
//  }
//  return false;
//}

void discoveringYYSTYPE(int yy) { cout << "YYstype is : " << yy << endl; }

// bool Scope::isEnumContainer(string id){
//  for (unordered_map<string,ScopeData> curr_scope : symbol_table ){
//    for (auto data : curr_scope){
//      if (data.second.getEnumValues().size() != 0 &&
//      data.second.getNameCopy()==id){
//            return true;
//          }
//        }
//      }
//  return false;
//}
