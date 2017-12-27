#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Account {
    int acNo;
    string FirstName;
    string LastName;
    double acBal;
};

void menu(int*);
void makeAccount(vector <Account>&);
void printAllAccount();
void printAccount(vector <Account>&);
void depositAccount(vector <Account>&);
void withdrawAccount(vector <Account>&);
void deleteAccount(vector <Account>&);
void sortAccounts(vector <Account>&);
void validAmt(double&);
extern vector <Account> banks;
//header file with all the functions declared