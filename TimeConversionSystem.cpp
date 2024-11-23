#include<iostream>

using namespace std;

int AmConversion(int hour) {
    if (hour == 0) return 12; // Midnight
    if (hour <= 12) return hour; // AM time
    return hour - 12; // PM time
}


int PmConversion(int hour) {
    if (hour == 12) return hour; // Noon remains 12
    return (hour % 12) + 12; // Convert to PM
}


void choice()                /*A function to display the choices.*/
{
    cout<<"Enter 'A' for conversion from 24 hours to 12 hours notation. \nEnter 'B' for conversion from 12 hours to 24 hours notation. \nEnter your choice:";

}


char UserChoice()               /*A function to get the choice.*/
{
    char yourChoice;
    cin >> yourChoice ;

    return yourChoice;
}

void TimeInput(int &hour, int &minutes) {
    do {
        cout << "Enter hour: ";
        cin >> hour;
        if (hour < 0 || hour > 23) cout << "Invalid hour! Please enter a value between 0 and 23.\n";
    } while (hour < 0 || hour > 23);

    do {
        cout << "Enter minutes: ";
        cin >> minutes;
        if (minutes < 0 || minutes > 59) cout << "Invalid minutes! Please enter a value between 0 and 59.\n";
    } while (minutes < 0 || minutes > 59);
}


char ContinueFunction()
{
    char x;
    cout<< "Do you want to perform another conversion, enter 'Y', (Enter 'N' for quit):",
    cin >> x;


    return x;
}







int main() {
    cout << "********************************************" << endl;
    cout << "***                                      ***" << endl;
    cout << "***       TIME CONVERSION SYSTEM         ***" << endl;
    cout << "***                                      ***" << endl;
    cout << "***                                      ***" << endl;
    cout << "********************************************" << endl;

    char continueChoice;
    do {
        choice();
        char z = UserChoice();
        if (z == 'A' || z == 'a') {
            cout << "You have chosen the conversion from 24 hours to 12 hours notation.\n";
            int hour, minutes;
            TimeInput(hour, minutes);

            cout << AmConversion(hour) << ":" << (minutes < 10 ? "0" : "") << minutes
                 << " " << (hour >= 12 ? "PM" : "AM") << endl;
        } else if (z == 'B' || z == 'b') {
            cout << "You have chosen the conversion from 12 hours to 24 hours notation.\n";
            int hour, minutes;
            TimeInput(hour, minutes);

            cout << PmConversion(hour) << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
        } else {
            cout << "Invalid choice.\n";
        }

        continueChoice = ContinueFunction();
        if (continueChoice == 'N' || continueChoice == 'n') {
            cout << "Thank you for using the time conversion program. Goodbye!\n";
        }
    } while (continueChoice == 'Y' || continueChoice == 'y');

    return 0;
}

