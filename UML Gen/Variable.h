#pragma once
#include<iostream>



class Variable{
public:
  Variable(std::string,std::string);
  
private:
  std::string _name;
  std::string _type;
};
