#ifndef bankAccount_h
#define bankAccount_h
#include <string>
#include <iomanip> //for the setw(), setiosflags(), fixed, and setprecision().


using namespace std;

class bankAccount {
    //creates private data members
    int bankID;
    string name;
    string cardNumber;
    string PIN;
    double balance;
    double lastTransaction;

public:                     //public methods
    
    bankAccount(); //constructor with no argument
    bankAccount(int bankID, string name, string cardNumber, string PIN, double balance, double lastTransaction);
    //constructor that takes all arguments to assign to data members
    
    void clear(); //clears all data members
    bool PIN_is_valid(); // checks if the PIN code contains only numbers
    
    //getters
    int get_BankID();
    //returns the value of the bankID of this bankAccount
    string get_name();
    //returns the name of this bankAccount
    string get_cardNumber();
    //returns the cardNumber of this bankAccount
    string get_PIN();
    //returns the PIN of this bankAccount
    double get_balance();
    //returns the balance of this bankAccount
    double get_lastTransaction();
    //returns the value of the lastTransaction of this bankAccount
    
    //setters
    void set_BankID(int BankID);
    //sets the bankID of this bankAccount to the bankID given through the argument
    void set_name(string name);
    //sets the name of this bankAccount to the name given through the argument
    void set_cardNumber(string cardNumber);
    //sets the cardNumber of this bankAccount to the cardNumber given through the argument
    void set_PIN(string PIN);
    //sets the PIN of this bankAccount to the PIN given through the argument
    void set_balance(double balance);
    //sets the balance of this bankAccount to the balance given through the argument
    void set_lastTransaction(double lastTransaction);
    //sets the lastTransaction value of this bankAccount
    //to the lastTransaction value given through the argument
};

#endif /* bankAccount_h */
