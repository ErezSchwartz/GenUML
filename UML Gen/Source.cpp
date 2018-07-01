#include <iostream>
#include "GenClass.h"
void main() {
	GenClass g=GenClass();
	g.ParseFile("one");
	g.ParseFile("one.h");
	system("PAUSE");
}