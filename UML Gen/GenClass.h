#pragma once
#include<iostream>
#include<vector>
#include<fstream>

//this is for a parsed class  
class GenClass
{
public:
	GenClass();
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
	std::vector<std::string> ListOfVars;
	std::vector<std::string> ListOfFuncs;
	//this is for inheritance
	std::vector<GenClass> ListOfSonClasses;
	bool ValidString(std::string);
};
