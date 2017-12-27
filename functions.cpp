
#include "head.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void menu(int *pointer) { int num = 0;
    cout << "\n\nWelcome to MadeUp Banking. Select options below:" << endl; cout << "\t1. Make new account." << "\n\t2. Display all accounts."
                                                                             << "\n\t3. Deposit to an account." << "\n\t4. Withdraw from an account." << "\n\t5. Print account." << "\n\t6. Delete an account."
                                                                             << "\n\t7. Quit." << endl;
    cout << "Selection:\t";
    cin >> num;
    *pointer = num; }

void makeAccount(vector <Account>& banks) { //creates bank account for users

    int number=0;
    Account temp;

    number = rand() % 9000 + 1000; //random 4-digit number is generated

    for (int i = 0; i < banks.size(); i++) {
        if (banks[i].acNo == number) //stores in array
            number = rand() % 9000 + 1000;
    }

    temp.acNo = number;

    cout << "\nCreating bank account number " << temp.acNo << endl;
    cout << "\nEnter first name: ";
    cin >> temp.FirstName;
    cout << "Enter last name: ";
    cin >> temp.LastName;
    cout << "Enter starting balance: ";
    cin >> temp.acBal;

    validAmt(temp.acBal);
    banks.push_back(temp);
    return;
}

void printAccount(vector <Account>& banks) {//displays a specific account
    int acctNum = 0;

    cout << "\nEnter account number to print: ";
    cin >> acctNum;

    for (int i = 0; i < banks.size(); i++) {
        if (banks[i].acNo == acctNum) {
            cout << "\nAccount Number: " << banks[i].acNo;
            cout << "\t\tBalance: " << banks[i].acBal << endl;
            cout << "     Last name: " << banks[i].LastName;
            cout << "\t\tFirst name: " << banks[i].FirstName << endl;
            goto valid;
        }
    }
    cout << "Account number does not exist!";
    valid:
    cout << endl;
}

void printAllAccount() { //prints all stored account

    for (int i = 0; i < banks.size(); i++) {
        cout << "\nAccount Number: " << banks[i].acNo;
        cout << "\t\tBalance: " << banks[i].acBal << endl;
        cout << "     Last name: " << banks[i].LastName;
        cout << "\t\tFirst name: " << banks[i].FirstName << endl;
    }
    return;
}

void depositAccount(vector <Account>& banks) { // allows user to deposit into a specific account.

    int acctNum=0;
    double money=0;

    cout << "\nEnter account number for deposit: ";
    cin >> acctNum;

    cout << "Enter amount to be deposit: ";
    cin >> money;
    validAmt(money);

    for (int j = 0; j < banks.size(); j++) {
        if (banks[j].acNo == acctNum) {
        banks[j].acBal = banks[j].acBal + money;
            goto valid;
        }
        else {
            continue;
        }
    }
    cout << "Account number does not exist!";
    valid:
    cout << endl;}

void withdrawAccount(vector <Account>& banks) { //withdraw from a specific account.

    int acctNum = 0;
    double money = 0;

    cout << "\nEnter account number for withdraw: ";
    cin >> acctNum;

    cout << "Enter amount to be withdraw: ";
    cin >> money;
    validAmt(money);

    for (int j = 0; j < banks.size(); j++) {
        if (banks[j].acNo == acctNum) {
            banks[j].acBal = banks[j].acBal - money;
            goto valid;
        } else {
            continue;
        }
    }
    cout << "Account number does not exist";
    valid:
    cout << endl;
}

void sortAccounts(vector <Account>& banks) {//sorts the accounts to be displayed
    for(int i=0; i<banks.size();i++){
        for(int j=0; j<(banks.size()-1);j++) {
            if(banks[j].acNo > banks[j+1].acNo){
                iter_swap(banks.begin()+j, banks.begin()+j+1);
}}}}

void deleteAccount(vector <Account>& banks) { //delete a specific account.

    int acctNum=0;

    cout << "\nEnter account number to be deleted: ";
    cin >> acctNum;

    for (unsigned i = 0; i < banks.size(); i++) {
        if (banks[i].acNo == acctNum) {
            banks.erase(banks.begin() + i);
            goto valid;
        }
    }
    cout << "Account number does not exist!";
        valid:
    cout << endl;
    }

void validAmt(double &money) {//Only allows positive deposits.
    if (money < 0) {
        cout << "\nInvalid input.";
        cout << "\nEnter positive number: ";
        cin >> money;
    }}