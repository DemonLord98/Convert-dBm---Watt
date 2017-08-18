#include <iostream>
#include <math.h>

int main()
{
    int choice;
    double X ,Power;
    std::string response;
    // A do-while loop if the user user want another conversion
    do{
        std::cout << "What do you want to convert? \n1) dBm to Watts \n2) Watts to dBm\n" << "Choose: ";
        std::cin >> choice;
        if (choice == 1){
            std::cout << "\nYou choice was from dBm to Watts.\n" << "Now enter the dBm value: ";
            std::cin >> X;
            std::cout << "............................\n";
            Power = 1/*Watt*/ * pow(10 ,(X - 30) / 10);
            // Convert the value from watts to another convenient equivalent like Kilowatt or milliwatt as necessary.
            if (Power >= pow (10, 3) && Power < pow (10, 6)) std::cout << "The value in Kilowatt is: " << Power / pow (10, 3) << " Kilowatt\n";
            else if (Power >= pow (10, 6) && Power < pow(10, 9)) std::cout << "The value in Megawatt is: " << Power / pow (10, 6) << " Megawatt\n";
            else if (Power >= pow (10, 9) && Power < pow(10, 12)) std::cout << "The value in Terawatt is: " << Power / pow (10, 9) << " Terawatt\n";
            else if (Power <= pow (10, -3) && Power > pow (10, -6)) std::cout << "The value in milliwatt is: " << Power / pow (10, -3) << "milliwatt\n";
            else if (Power <= pow (10, -6) && Power > pow (10, -9)) std::cout << "The value in microwatt is: " << Power / pow (10, -6) << "microwatt\n";
            else if (Power <= pow (10, -9) && Power > pow (10, -12)) std::cout << "The value in nanowatt is: " << Power / pow (10, -9) << "nanowatt\n";
            else std::cout << "\nThe value in Watts is: " << Power << " watt\n";
        }

        if(choice == 2){
            std::cout << "\nYou choice was from Watts to dBm.\n" << "Now enter the Power(unit:watt) value: ";
            std::cin >> Power;

            X = 30 + (10 * log10(Power / 1/*watt*/));
            std::cout << "\nThe value in dBm is: " << X << std::endl;
        }
        std::cout << "Do you want another conversion? (yes ,no)";
        std::cin >> response;
        std::cout << "\n____________________________________________________________\n";
    }
    while(response[0] == 'y' || response[0] == 'Y');

    std::cout << "<-Thanks for using this program->\n____________________________________________________________\n";

    return 0;
}
