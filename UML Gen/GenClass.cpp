#include "GenClass.h"

GenClass::GenClass(std::string toParse)
{
	ParseFile(toParse);
}

GenClass::~GenClass()
{
	free(this->_name);
}
bool GenClass::ParseFile(std::string fileName)
{
	std::fstream f;
	std::string line;
	//check that the file is a .h file
	if (ValidFileName(fileName))
	{
		f.open(fileName, std::fstream::in);
		//loop over all of the lines
		while (std::getline(f, line))
		{
			ParseLine(line);
		}
	}
	else 
	{
		std::cout << "Bad File type not a header file" << std::endl;
	}
	return true;
}

bool GenClass::ValidFileName(std::string name)
{
	if (name[name.length() - 1] == 'h')
	{
		return true;
	}
}

void GenClass::ParseLine(std::string line)
{
	line = trim(line);
	if (line != "")
	{
		if (line.compare(0, CLASS_LEN, "class")==0)
		{
			std::cout << GetClassName(line) << std::endl;
			this->_name = new std::string(GetClassName(line));
		}
	}
}
//function taken from https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string GenClass::trim(const std::string& str)
{
	const std::string& whitespace = " \t";
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

std::string GenClass::GetClassName(const std::string line)
{
	std::size_t startOfName =line.find_first_not_of("\t",CLASS_LEN);
	std::size_t endOfName = line.find_first_of("\t", startOfName);
	return line.substr(startOfName+1, endOfName);
}
