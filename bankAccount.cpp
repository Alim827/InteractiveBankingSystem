#include "bankAccount.h"

//constructor
bankAccount::bankAccount(){         //this points to data member of class
    this->bankID=0;                 //0 because bankID contains only numbers
    this->name.clear();             //clear because data contains symbols/characters
    this->cardNumber.clear();       //clear because data contains symbols/characters
    this->PIN.clear();              //clear because data contains symbols/characters
    this->balance=0;                //0 because balance contains only numbers
    this->lastTransaction=0;        //0 because lastTransaction contains only numbers
}
//constructor with arguments
bankAccount::bankAccount(int bankID, string name, string cardNumber, string PIN, double balance, double lastTransaction){
    this->bankID=bankID;            //here bankID of class equals to the bankID from the constructors arguments
    this->name=name;                //name of class equals to the name from the constructors arguments
    this->cardNumber=cardNumber;    //cardNumber of class equals to the cardNumber from the constructors arguments
    this->PIN=PIN;                  //PIN of class equals to the PIN from the constructors arguments
    this->balance=balance;          //balance of class equals to the balance from the constructors arguments
    this->lastTransaction=lastTransaction; //lastTransaction of class equals to the lastTransaction from the constructors arguments
}

void bankAccount::clear(){          //to clear all data of the bankAccount and equal to zero
    this->bankID=0;
    this->name.clear();
    this->cardNumber.clear();
    this->PIN.clear();
    this->balance=0;
    this->lastTransaction=0;
}

bool bankAccount::PIN_is_valid(){       //to check if PIN contains only numbers
    bool is_valid = true;
    for(int i=0; i<4; i++){             //loop goes through every digit of PIN code
        if(!(this->PIN[i]>=48 && this->PIN[i]<=57)) is_valid=false;
        //in ASCII 48 and 57 is the range of digits between 0 and 9
    }   //the above line means that if PIN does not(!) contain only numbers then is_valid is false
    return is_valid;
}
//getters
int bankAccount::get_BankID(){
    //get BankID returns the value of the bankID of this bankAccount
    return this->bankID;
}

string bankAccount::get_name(){
    //get name returns the value of the name of this bankAccount
    return this->name;
}

string bankAccount::get_cardNumber(){
    //get cardNumber returns the value of the cardNumber of this bankAccount
    return this->cardNumber;
}

string bankAccount::get_PIN(){
    //get PIN returns the value of the PIN of this bankAccount
    return this->PIN;
}

double bankAccount::get_balance(){
    //get balance returns the value of the balance of this bankAccount
    return this->balance;
}

double bankAccount::get_lastTransaction(){
    //get lastTransaction returns the value of the lastTransaction of this bankAccount
    return this->lastTransaction;
}

//setters
void bankAccount::set_BankID(int bankID){
    //sets the bankID of this bankAccount to the bankID given through the argument
    this->bankID=bankID;
}

void bankAccount::set_name(string name){
    //sets the name of this bankAccount to the name given through the argument
    this->name=name;
}

void bankAccount::set_cardNumber(string cardNumber){
    //sets the cardNumber of this bankAccount to the cardNumber given through the argument
    this->cardNumber=cardNumber;
}

void bankAccount::set_PIN(string PIN){
    //sets the PIN of this bankAccount to the PIN given through the argument
    this->PIN=PIN;
}

void bankAccount::set_balance(double balance){
    //sets the balance of this bankAccount to the balance given through the argument
    this->balance=balance;
}

void bankAccount::set_lastTransaction(double lastTransaction){
    //sets the lastTransaction value of this bankAccount to the lastTransaction value given through the argument
    this->lastTransaction=lastTransaction;
}
