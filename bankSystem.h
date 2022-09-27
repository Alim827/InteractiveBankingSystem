#ifndef bankSystem_h
#define bankSystem_h
#include <list>
#include "bankAccount.h"
#include <fstream>
#include <iostream>

using namespace std;

class bankSystem {
    list<bankAccount> database;
    // creates a list of objects of class bankAccount
    
    list<bankAccount>::iterator it;
    //creates an iterator for the previously mentioned list
    
    bankAccount currentUser; // creates an object of class bankAccount
    bool database_open=false; //bool variable
public:
    bankSystem(); // no argument construtor
    bankSystem(string fileName);
    //constructor with argument that takes the name of File
    bool login(string cardNumber, string PIN);
    //login funtion returns true if cardNumber and PIN code matches
    //and false if no such a user found
    bool database_is_open();
    // returns the bool variable database_open
    bankAccount get_currentUser(); // returns object currentUser
    bool withDraw(); // function to withdraw money
    bool depositCash();// function to deposit money
    bool modifyPIN();// function to modify PIN code
    bool showBalance();// function to display the information
    bool transfer();// function to transfer money to different account
    void refresh_database();//function to update database
};


#endif /* bankSystem_h */
