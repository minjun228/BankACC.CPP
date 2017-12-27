#include "head.h"

using namespace std;

vector <Account> banks;
int main() {
    int userinput;
    srand(time(0));
do{
        int *pointer = &userinput;
        menu(pointer);

        switch (userinput) {
            case 1:
                makeAccount(banks);
                sortAccounts(banks);
                break;
            case 2:
                printAllAccount();
                break;
            case 3:
                depositAccount(banks);
                break;
            case 4:
                withdrawAccount(banks);
                break;
            case 5:
                printAccount(banks);
                break;
            case 6:
                deleteAccount(banks);
                break;
            case 7:
                cout << "\nProgram terminated.\n\n\n";
                break;
        }
    }while (userinput != 7); //The following do-while loop with switch cases implemented will execute until 7 is inputted, and end with the message.
}