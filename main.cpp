#include <iostream>
#include "bankSystem.h" //includes "bankSystem" header



int main() {
    bankSystem mybank("database.csv"); //operation to open the file "database.csv"
    if(!(mybank.database_is_open())) {
        cout<<"CRITICAL ERROR"<<endl;
        cout<<"Database is not found!"<<endl;
        //Program prints out this message if file cannot be opened
        return 0;
    }
    string cardNumber;
    string PIN;
    bool login=true; //adding a boolean login for entering the system
    while(login){
        
        cout <<endl<< "-----------Welcome to the Bank of <ZUCKERBERG's LIL BROs>-----------" << endl<<endl;
        cout <<"Card number(6 digits): ";
        cin>>cardNumber;
        cout <<"PIN code (4 digits): ";
        cin>>PIN;
        //input of PIN and cardNumber
        
        if(mybank.login(cardNumber, PIN))  {
            
            if(!mybank.get_currentUser().PIN_is_valid()) { //checks if the PIN code contains only numbers
                //If PIN of user is not valid, the program will ask to set new PIN code
                cout <<endl<< "Your account is not activated."<<endl;
                cout <<"Please, activate your account by changing your PIN."<<endl;
                
                if(!mybank.modifyPIN()) { // if user chooses not to return to main menu
                    mybank.refresh_database(); // database is updated
                    continue; //cycle of the loop starts again
                    
                }
            }
            
            
            bool valid=true;
            while(valid){
                cout <<endl<< "-----------Welcome to the Bank of <ZUCKERBERG's LIL BROs>-----------" << endl<<endl;
                cout <<fixed<<setiosflags(ios::left)<<setw(40)<<"1. Withdraw Cash" << "2. Deposit Cash"<<endl;
                cout <<fixed<<setiosflags(ios::left)<<setw(40)<<"3. Modify PIN Code" << "4. Show Balance"<<endl;
                cout <<fixed<<setiosflags(ios::left)<<setw(40)<<"5. Transfer Between Accounts" << "6. End Session"<<endl;
                int n;
                cout <<endl <<"Enter option number (1-6): ";
                cin >> n; //input of choice of user
                switch (n) {
                    case 1: //withDraw funtion is called
                        if(mybank.withDraw()) break; //if the withDraw() method returns true
                        //we break from the switch cycle and
                        //return to main menu
                        else {
                            valid=false; //valid is assigned to false
                            break; //we break from the switch and loop of while
                            //does not continue because valid is false
                            
                        }
                    case 2://depostiCash function is called
                        if(mybank.depositCash()) break; //if the depositCash() method returns true
                        //we break from the switch cycle and
                        //return to main menu
                        else {
                            valid=false; //valid is assigned to false
                            break; //we break from the switch and loop of while
                            //does not continue because valid is false
                        }
                    case 3://modifyPIN function is called
                        if(mybank.modifyPIN()) break; //if the modifyPIN() method returns true
                        //we break from the switch cycle and
                        //return to main menu
                        else {
                            valid=false; //valid is assigned to false
                            break; //we break from the switch and loop of while
                            //does not continue because valid is false
                        }
                    case 4://showBalance function is called
                        if(mybank.showBalance()) break; //if the showBalance() method returns true
                        //we break from the switch cycle and
                        //return to main menu
                        else {
                            valid=false; //valid is assigned to false
                            break; //we break from the switch and loop of while
                            //does not continue because valid is false
                        }
                    case 5:
                        if(mybank.transfer()) break; //if the transfer() method returns true
                        //we break from the switch cycle and
                        //return to main menu
                        
                        else {
                            valid=false; //valid is assigned to false
                            break; //we break from the switch and loop of while
                            //does not continue because valid is false
                        }
                    case 6:
                        mybank.refresh_database();  //This method refreshes the database and adds changes in it
                        valid=false; //valid is assigned to false
                        break; //we break from the switch and loop of while
                        //does not continue because valid is false
                    default:
                        cout<<endl<<"No such a choice!"<<endl;
                        cout<<"Try again!"<<endl;
                        break;
                        //In default case, the following message is showed and user returns to main menu
                }
            }
            mybank.refresh_database(); //refreshes database in case user chose to not return to main menu
        }
    }
    return 0;
    
}
