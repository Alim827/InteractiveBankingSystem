#include "bankSystem.h"

void welcomeMessage(){ //displays welcome message
    cout <<endl<<endl <<"-----------Welcome to the Bank of <ZUCKERBERG's LIL BROs>-----------" << endl<<endl;
}

bankSystem::bankSystem(){
    this->database.clear(); //clears the list database
}

bankSystem::bankSystem(string fileName){
    ifstream file; //creates an object of class ifstream to read from file
    
    file.open(fileName); //opens a file with the name which of was
    //given through argument of the constructor
    
    if(file.is_open()) database_open=true;
    //if file is found and opened database_open becomes true
    
    string a; // creates a string a
    string temp[6]; // creates an array of 6 strings
    
    getline(file,a); // reads the first line to skip it
    // because it is not neccessary
    
    while(getline(file,a)){
        //while the function getline reads the file and assigns the value to string a
        
        for(int i=0; i<5; i++){
            temp[i]=a.substr(0, a.find(','));
            //assigns to temp[i] the value of string a from the beginning until ','
            a=a.substr(a.find(',')+1);
            // a is assigned to part of a after the ',' till the end
        }
        //this loop assigns to temp[1], temp[2], temp[3], and temp[4] the Bank ID,
        //Name, Card Number, PIN, and Balance, respectively.
        
        temp[5]=a; //assignment of Last Transaction
        
        database.push_back(bankAccount(stoi(temp[0]), temp[1], temp[2], temp[3], stod(temp[4]), stod(temp[5])));
        //new object of class bankAccount is pushed to the back of the list
        //the object is given in the form of constructor with arguments of class bankAccount
        
        // in addition, functions stoi() and stod() were implemented to convert
        //strings to integers and doubles.
    }
    file.close(); // file is closed
}

bool bankSystem::database_is_open(){
    return database_open; // returns the bool variable database_open
}

bool bankSystem::login(string cardNumber, string PIN){
    for(it = database.begin(); it!=database.end(); it++){
        //iterator goes through list from the beginnig to the end
        if(cardNumber==it->get_cardNumber()&&PIN==it->get_PIN()){
            //if card number and PIN code matches with the one of the bank accounts
            //then object currentUser becomes the object found by iterator
            currentUser=(*it);
            return true; //returns true to the main function
        }
    }
    cout<< endl<<"Card number or PIN Code is incorrect!"<<endl;
    cout<< "Try again."<<endl;
    //this message appears if a user if this card number and PIN code
    //is not found
    return false; // returns false in this case
}

bankAccount bankSystem::get_currentUser(){
    return this->currentUser;    //returns currentUser
}

bool bankSystem::withDraw(){
    double amountWithdraw=0; //initializes amountWithdraw to 0
    bool valid=true; //initializes bool variable valid to true
    while(valid){ //loop works while valid is true
        welcomeMessage(); //displays welcome message
        cout <<"Current balance: "<< fixed << setprecision(2) << currentUser.get_balance()<<" KZT"<<endl<<endl;
        cout <<"Enter amount to withdraw: ";
        cin >> amountWithdraw; //user inputs amount to withdraw
        if(amountWithdraw<=0){
            cout<<"The amount to withdraw must be more than zero!"<<endl;
            continue; // if amount to withdraw less or equal to zero loop starts again
        }
        if(currentUser.get_balance()>=amountWithdraw) { // if current balance is not less than amount to withdraw
            
            currentUser.set_balance(currentUser.get_balance()-amountWithdraw); //sets the new balance
            currentUser.set_lastTransaction(-amountWithdraw); //sets new last transaction
            
            welcomeMessage();
            cout <<"Do not forget to take your cash!"<<endl;
            cout <<"The amount left: "<<currentUser.get_balance()<<" KZT"<<endl; //shows the remaining balance
            
            string c;//creates new string c
            while(valid){
                cout <<"Would you like to return to main menu? (y/n): ";
                cin>>c; //user inputs y or n
                if(c=="y") return true; //returns true, so users returns to main menu
                else if(c=="n") return false;//returns false, so user end session
                else { //if user enters something other than 'y' and 'n' loop starts again
                    cout<<"Enter 'y' to return or 'n' to end session!"<<endl;
                    continue;
                }
            }
        } else { //if amount to withdraw exceeds current balance
            cout <<endl<<"You don't have enough money on your balance!"<<endl;
            cout <<"Try again."<<endl;
        }
    }
    return true;
}

bool bankSystem::depositCash(){
    double amountDeposit=0;//initializes amountDeposit to 0
    bool valid=true;//initializes bool variable valid to true
    while(valid){
        welcomeMessage(); //welcom message
        cout <<"Current balance: "<< fixed << setprecision(2) << currentUser.get_balance()<<" KZT"<<endl<<endl;
        cout <<"Enter amount to deposit: ";
        cin >> amountDeposit; //user inputs amount to deposit
        
        if(amountDeposit<=0){ //if amoint to deposit is less than or equal to zero
            cout<<endl<<"The amount to deposit must be more than zero!"<<endl;
            continue;
        }
        
        currentUser.set_balance(currentUser.get_balance()+amountDeposit);
        //top ups balance
        
        currentUser.set_lastTransaction(amountDeposit);
        //changes the last transaction
        
        welcomeMessage();
        cout <<"The new balance: "<<currentUser.get_balance()<<" KZT"<<endl;
        //shows new balance
        
        string c; //creates new string c
        while(valid){
            cout <<"Would you like to return to main menu? (y/n): ";
            cin>>c; //user inputs y or n
            if(c=="y") return true; //returns true, so users returns to main menu
            else if(c=="n") return false;//returns false, so user end session
            else { //if user enters something other than 'y' and 'n' loop starts again
                cout<<"Enter 'y' to return or 'n' to end session!"<<endl;
                continue;
            }
        }
    }
    return true;
}

bool bankSystem::modifyPIN(){
    string PIN,newPIN, newPIN2; //creates new strings
    bool valid=false; //bool operators for the loops
    
    
    int n=0; //helping integer
    
    while(n==0){
        welcomeMessage();
        cout <<"Enter current PIN code (4 digit): ";
        cin >> PIN; //user enters current PIN
        
        if(PIN==currentUser.get_PIN()){ // in case PIN is correct
            while(!valid){
                
                welcomeMessage();
                cout <<"Enter new PIN code(4 digit number): ";
                cin >> newPIN; //user enters new PIN
                if(newPIN==PIN) { //if user enters the old PIN, loop starts again
                    cout<<endl<<"You entered your old PIN code!"<<endl;
                    cout<<"Enter a new one."<<endl;
                    continue;
                }
                
                for(int i=0; i<4; i++){ //this for loop checks the PIN code for several charactheristics
                    if(!(newPIN[i]>=48 && newPIN[i]<=57)) { //to check if PIN code contains only numbers
                        valid=false;
                        cout << endl<<"PIN code must contain only numbers!"<<endl;
                        break;
                    } else valid=true;
                    if(newPIN.size()!=4) {//to check if PIN is 4-digit
                        valid=false;
                        cout << endl <<"PIN code must be 4-digit!"<<endl;
                        break;
                    } else valid=true;
                }
                
                if(!valid) continue;
                
                
                cout <<endl<<"Repeat new PIN code (4 digit number): ";
                cin >> newPIN2; //repeats new PIN code
                if(newPIN==newPIN2) { //if new PIN codes match
                    currentUser.set_PIN(newPIN); //sets the new PIN code
                    cout <<endl<< "PIN code was successfuly modified!"<<endl;
                    n++; // so that the first loop is not repeated
                    
                    
                    string c; //creates new string c
                    while(valid){
                        cout <<"Would you like to return to main menu? (y/n): ";
                        cin>>c; //user inputs y or n
                        if(c=="y") return true; //returns true, so users returns to main menu
                        else if(c=="n") return false;//returns false, so user end session
                        else { //if user enters something other than 'y' and 'n' loop starts again
                            cout<<"Enter 'y' to return or 'n' to end session!"<<endl;
                            continue;
                        }
                    }
                }
                else { //if PIN codes do not match
                    valid=false; //so that the loop is started again
                    cout<<endl<<"PIN codes do not match!"<<endl;
                    cout<<"Please, Try again."<<endl;
                    continue; // loop started again
                }
            }
        }
        else { //in case if the first PIN code is not correct
            cout<<endl<<"Wrong PIN code!"<<endl;
            cout<<"Please, Try again."<<endl;
            continue; //loop is started again
        }
    }
    return true;
}

bool bankSystem::showBalance(){
    welcomeMessage();
    cout << "Card owner: "<< currentUser.get_name()<<endl; //shows name
    cout << "Card number: "<<currentUser.get_cardNumber()<<endl; //show card number
    cout << "Current balance: "<<fixed<<setprecision(2)<<currentUser.get_balance()<<" KZT"<<endl;
    //shows balance in kzt
    cout << "Current balance: "<<currentUser.get_balance()/450<<" USD"<<endl; //shows balance in usd
    cout << "Last transaction: "<<currentUser.get_lastTransaction()<<" KZT"<<endl; //shows last transaction
    
    bool valid=true; //bool for loop
    string c; //creates new string c
    while(valid){
        cout <<"Would you like to return to main menu? (y/n): ";
        cin>>c; //user inputs y or n
        if(c=="y") return true; //returns true, so users returns to main menu
        else if(c=="n") return false;//returns false, so user end session
        else { //if user enters something other than 'y' and 'n' loop starts again
            cout<<"Enter 'y' to return or 'n' to end session!"<<endl;
            continue;
        }
    }
    return true;
}


bool bankSystem::transfer(){
    bankAccount whereToTransfer; //new object for the beneficary's bank account
    int n=0; //new integer for loop
    string cardNumber; //string to hold card number
    while(n==0){
        welcomeMessage(); // welcome message and info about commision
        cout<<"Commission for fund transfers over 20,000 KZT is 500 KZT."<<endl;
        cout<<"Commission for fund transfers between banks is 200 KZT."<<endl;
        
        cout << "Enter Beneficary's card number: ";
        cin >> cardNumber; //user inputs the beneficary's card number
        for(it = database.begin(); it!=database.end(); it++){
            //loop finds the bank account with this card number
            if(it->get_cardNumber()==cardNumber){
                whereToTransfer=(*it); //Beneficary's bank account is assigned to found in list
                n++; //to stop the loop
                break; //stops searching
            }
        }
        if(n==0) { //if user is not found n is still zero. Thus, output:
            cout<<endl<<"No account with such a card number!"<<endl;
            cout<<"Try again!"<<endl;
        }
    }
    
    double transferAmount=0; //double transfer amount is created
    bool valid=true; //bool for loop is created
    
    while(valid){
        cout <<endl<<"Current balance: "<< fixed << setprecision(2) << currentUser.get_balance()<<" KZT"<<endl<<endl;
        cout<<"Enter transfer amount (KZT): ";
        cin>>transferAmount; //input of transfer amount
        
        if(transferAmount<=0){
            //checks if the transfer amount is greater than zero
            cout << endl<<"Transfer amount must be more than zero!"<<endl;
            cout<<"Try again!"<<endl;
            continue; //loop starts again
        }
        
        if(transferAmount>currentUser.get_balance()){
            //checks if transfer amount does not exceed balance
            cout << endl<<"Transfer amount cannot exceed your balance!"<<endl;
            cout<<"Try again!"<<endl;
            continue; //loop starts again
        }
        
        bool different_bank = true; //auxilary bool is created and initilized to true
        
        //in the following if we compare Bank IDs of current user and beneficary
        if(currentUser.get_BankID()!=whereToTransfer.get_BankID()) different_bank=true;
        else different_bank=false;
        
        double comission=0; //double for commision is initialized to zero
        
        
        //in the following cylce of IFs programm checks if the user has enough money(including commission)
        //to make transfer. Also, it assignes an appropriate value to commission.
        if(transferAmount>20000 && different_bank){ //if transfer more than 20000 and different banks
            comission=700;
            if(!(currentUser.get_balance()-transferAmount>=700)) {
                cout<<endl<<"You must have at least 700 KZT after transfer is made!"<<endl;
                continue; //not enough money, loop starts again
            }
        } else if (transferAmount<=20000 && different_bank) {//if transfer less or equal to 20000 and different bank
            comission=200;
            if(!(currentUser.get_balance()-transferAmount>=200)) {
                cout<<endl<<"You must have at least 200 KZT after transfer is made!"<<endl;
                continue;//not enough money, loop starts again
            }
        } else if (transferAmount>20000 && !different_bank) {//if transfer more than 20000 and same banks
            comission=500;
            if(!(currentUser.get_balance()-transferAmount>=500)) {
                cout<<endl<<"You must have at least 500 KZT after transfer is made!"<<endl;
                continue;//not enough money, loop starts again
            }
        } // if transfer is less than 20000 and same banks, then commission stays to be zero
        
        cout<<endl<<"Beneficary's name: " << whereToTransfer.get_name()<<endl;
        //displays the beneificary's name
        
        string c; //string for confirmation of transfer
        
        while(valid){
            cout<<"Confirm? (Enter y/n): ";
            cin>>c; // user confirms or declines
            
            if(c=="y"){ //if user confirms
                currentUser.set_balance(currentUser.get_balance()-transferAmount-comission);
                //current user's balance updated
                currentUser.set_lastTransaction(-transferAmount-comission);
                //current user's last transaction updated
                //notice that commision is included here
                
                whereToTransfer.set_balance(whereToTransfer.get_balance()+transferAmount);//beneficary's balance updated
                whereToTransfer.set_lastTransaction(transferAmount);//beneficary's last transaction updated
                
                
                cout<<endl<<"Transfer made succesfully!"<<endl;
                cout <<"The amount left: "<<currentUser.get_balance()<<" KZT"<<endl; //remaining balance displayed
                
                
                //this loop finds the beneficary's account in the list
                //and substitutes it with the new beneficary's account
                for(it = database.begin(); it!=database.end(); it++){
                    if(whereToTransfer.get_cardNumber()==it->get_cardNumber()) {
                        (*it)=whereToTransfer;//assignment of a new account
                        break; //to stop the for loop from searching
                    }
                }
                
                
                valid=false;//to stop the confirmation loop
                
            } else if (c=="n"){
                return true; //transfer is not made. User returns to main menu
            } else {
                //if the user enters something except 'y' and 'n' loop of confirmation starts again
                cout<<endl<<"Enter 'y' to confirm and 'n' to return to main menu."<<endl;
                continue;
            }
        }
        
        bool valid=true; // to start the next loop
        string k; //creates new string c
        while(valid){
            cout <<"Would you like to return to main menu? (y/n): ";
            cin>>k; //user inputs y or n
            if(k=="y") return true; //returns true, so users returns to main menu
            else if(k=="n") return false;//returns false, so user end session
            else { //if user enters something other than 'y' and 'n' loop starts again
                cout<<"Enter 'y' to return or 'n' to end session!"<<endl;
                continue;
            }
        }
    }
    return true;
}
void bankSystem::refresh_database(){
    //The following for loop finds the account in the list by the unique card number
    //and substituites it with the new current user's account.
    //In simple words, it updates the logged in user's account info
    for(it = database.begin(); it!=database.end(); it++){
        if(currentUser.get_cardNumber()==it->get_cardNumber()) {
            (*it)=currentUser;
            break;
        }
    }
    ofstream newDatabase; //object newDatabase of class ofstream to write on files is created
    newDatabase.open("database.csv", ios::trunc); //database file is opened and truncated
    newDatabase<<"Bank ID,Name,Card Number,PIN,Balance,Last Transaction"<<endl;
    //first line is written
    //the following for loop line by line, object by object writes the information of every bank account
    //using getter functions
    for(it = database.begin(); it!=database.end(); it++){
        newDatabase<<it->get_BankID()<<","+it->get_name()+","+it->get_cardNumber()+",";
        newDatabase<<it->get_PIN()+","<<fixed<<setprecision(2)<<it->get_balance()<<","<<it->get_lastTransaction()<<endl;
    }
    currentUser.clear(); //current user bankAccount is cleared
    newDatabase.close(); //file is closed
}





