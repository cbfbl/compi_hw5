#include <list>
#include <map>
#include <string>
using std::list;
using std::map;
using std::string;

class RegisterManager {
  list<string> free_regs;
  map<string, string> allocated_regs;

 public:
  RegisterManager();
  string getRegister();
  void removeRegister(string reg);
};