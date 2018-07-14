#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Variable.h"


class Function{
public:
  Function(std::vector<Variable>,Variable,std::string,std::string);

private:
  std::vector<Variable> _ListOfVars;
  Variable _retVal;
  std::string _accessLevel;
  std::string name;
};
