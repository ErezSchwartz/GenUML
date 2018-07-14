#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Function.h"
#include "Variable.h"
#define CLASS_LEN 5
//this is for a parsed class
class GenClass
{
public:
	//the string for GenClass is a string name of all of the file
	GenClass(std::string);
	~GenClass();
	//this function recieves the file name, parses it and returns true if successful or false if not
	bool ParseFile(std::string);
private:
	//these two are for the func tokens and var token
	/*
	Var seved-
	<Type of access level> <name of var> : <Type of var>
	function saved-
	<Type of access level> { <name of var> :<Type of var> ... }
	*/
	std::vector<Variable> _listOfVars;
	std::vector<Function> _listOfFuncs;
	//this is for inheritance
	std::vector<GenClass> _listOfSonClasses;
	std::string* _name;
	bool ValidFileName(std::string);
	//parses a line, and places it in its currect place
	void ParseLine(std::string);
	std::string trim(const std::string&);
	std::string GetClassName(const std::string);
};
