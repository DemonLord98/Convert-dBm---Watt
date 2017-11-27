#include <iostream>
#include <math.h>
#include <string>

#include "Handler.h"


int main()
{
	Handler obj;
	do
	{
		obj.ConvertType();
		obj.GetValue();
		obj.Converter();
		obj.PrintOut();
		
	} while (obj.Repeat());

	obj.Outro();

	return 0;
}
