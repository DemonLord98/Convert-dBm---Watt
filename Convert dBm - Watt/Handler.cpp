#include <iostream>
#include <string>

#include "Handler.h"


Handler::Handler()
{
}

int Handler::ConvertType()
{
	std::cout << "What do you want to convert? \n1) dBm to Watts \n2) Watts to dBm\n" << "Choose: ";
	std::cin >> choice;
	// While loop to check validity of choice.
	while (choice != 1 && choice != 2)
	{
		std::cout << "\nPlease choose a valid answer (1 ,2): ";
		std::cin >> choice;
	}
	return choice;
}

void Handler::GetValue()
{
	if (choice == 1)
	{
		std::cout << "\nYou choice was from dBm to Watts.\n" << "Now enter the dBm value: ";
		std::cin >> X;
		std::cout << "............................\n";
	}

	else if (choice == 2)
	{
		std::cout << "\nYou choice was from Watts to dBm.\n" << "Now enter the Power(unit:watt) value: ";
		std::cin >> Power;
	}
}

void Handler::Converter()
{
	if (choice == 1)
	{
		Power = 1/*watt*/ * pow(10, (X - 30) / 10);
		// Convert the value from watts to another convenient equivalent like Kilowatt or milliwatt as necessary.
		if (Power >= pow(10, 3) && Power < pow(10, 6)) std::cout << "The value in Kilowatt is: " << Power / pow(10, 3) << " Kilowatt\n";
		else if (Power >= pow(10, 6) && Power < pow(10, 9)) std::cout << "The value in Megawatt is: " << Power / pow(10, 6) << " Megawatt\n";
		else if (Power <= pow(10, -3) && Power > pow(10, -6)) std::cout << "The value in milliwatt is: " << Power / pow(10, -3) << "milliwatt\n";
		else if (Power <= pow(10, -6) && Power > pow(10, -9)) std::cout << "The value in micro-watt is: " << Power / pow(10, -6) << "micro-watt\n";
		else if (Power <= pow(10, -9) && Power > pow(10, -12)) std::cout << "The value in nano-watt is: " << Power / pow(10, -9) << "nano-watt\n";
	}

	else if (choice == 2)
	{
		X = 30 + (10 * log10(Power / 1/*watt*/));
	}
}

void Handler::PrintOut()
{
	if (choice == 1)
	{
		std::cout << "\nThe value in Watts is: " << Power << " watt\n";
	}

	else if (choice == 2)
	{
		std::cout << "\nThe value in dBm is: " << X << "\n";
	}
}

bool Handler::Repeat()
{
	std::cout << "Do you want another conversion? (yes ,no)"; // ask repeat.
	std::cin >> response;
	std::cout << "\n____________________________________________________________\n";
	return (response[0] == 'y' || response[0] == 'Y');
}

void Handler::Outro()
{
	std::cout << "<-Thanks for using this program->\n____________________________________________________________\n";
}


Handler::~Handler()
{
}
