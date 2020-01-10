
#include "RegisterManager.h"

RegisterManager::RegisterManager(){};

string RegisterManager::getRegister() {
  if (free_regs.size() != 0) {
    string ret_reg = free_regs.back();
    free_regs.pop_back();
    return ret_reg;
  }
  string reg = "%t" + std::to_string(allocated_regs.size() + 1);
  allocated_regs[reg] = reg;
  return reg;
}

void RegisterManager::removeRegister(string reg) {
  if (allocated_regs.find(reg) == allocated_regs.end()) {
    return;
  }
  allocated_regs.erase(reg);
  free_regs.push_back(reg);
}