#include "GenClass.h"

GenClass::GenClass()
{
}

GenClass::~GenClass()
{
}
bool GenClass::ParseFile(std::string fileName)
{
	std::fstream f;
	if (ValidString(fileName))
	{
		f.open(fileName, std::fstream::in);
	}
	return true;
}

bool GenClass::ValidString(std::string name)
{
	if (name[name.length() - 1] == 'h')
	{
		return true;
	}
}