#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <graphics.h>

using namespace std;


class Account {

    int accNo;
    char name[50];
    double deposit;
    char type;
public:
    void createAccount();
    void showAccount() const;
    void modify();
    void dep(double x);
    void draw(double x);
    void report() const;
    int returnAcNo() const;
    double returnDeposit() const;
    char returnType() const;

}; ///end of class

void Account::createAccount() {

    cout << "********************************\n" << endl;
    cout << "\tAccount Creation " << endl << endl;
    cout << "********************************\n" << endl;

    cout << "\n\n Enter the new account number: ";
    cin >> accNo;
    cout << "\n Enter the name of the holder on account #" << accNo << ": ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n Enter the type of account (C/S): ";
    cin >> type;
    if(type != 'C' && type != 'S') {
        cout << "\n Enter the type of account (C/S): ";
        cin >> type;
    }
    type = toupper(type);
    cout << "\n Enter initial amount (>=500 for Savings, >=1000 for checking): ";
    cin >> deposit;
    cout << "\n\n Account Created..." << endl;

}
///================================================
void Account::showAccount() const {

    cout << "********************************\n" << endl;
    cout << "\tAccount #" << accNo << endl << endl;
    cout << "********************************\n" << endl;

    cout << "\n\n Account Holder Name: " << name << endl;
    cout << " Type of Account: ";
    if(type == 'C')
        cout << "Checking" << endl;
    else if(type == 'S')
        cout << "Savings" << endl;
    cout << "\n\t Balance: $" << setprecision(2) << fixed << deposit;

}
///================================================
void Account::modify() {

    cout << "********************************\n" << endl;
    cout << "\tModify" << endl << endl;
    cout << "********************************\n" << endl;

    cout << "\n Account #" << accNo << endl;
    cout << "\n Enter new Account Holder Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n Enter type of account (C/S): ";
    cin >> type;
    if(type != 'C' && type != 'S') {
        cout << "\n Enter type of account (C/S): ";
        cin >> type;
    }
    type = toupper(type);
    cout << "\n Enter new balance: ";
    cin >> deposit;
    cout << "\n\n Account Successfully Modified..." << endl;

}
///================================================
void Account::dep(double x) {

    deposit+=x;

}
///================================================
void Account::draw(double x) {

    deposit-=x;

}
///================================================
void Account::report() const {

    cout << accNo << setw(10) << " " << name << setw(10) << " ";
    cout << type << setw(6) << "$" << setprecision(2) << fixed << deposit << endl;

}
///================================================
int Account::returnAcNo() const {

    return accNo;

}
///================================================
double Account::returnDeposit() const {

    return deposit;

}
///================================================
char Account::returnType() const {

    return type;

}
///================================================
///********************************************************
///         function declaration
///********************************************************

void writeAccount();       //write record in binary file
void displaySP(int);       //display account details
void modifyAccount(int);   //modify account
void deleteAccount(int);  //delete account
void displayAll();     //display all account details
void depositWithdraw(int, int);  //deposit/withdraw
void intro();  //intro screen

///********************************************************

int main() {

    char ch;
    int num;
    intro();

    do {

        system("cls");
        cout << "\n********************************\n" << endl;
        cout << "\tMAIN MENU" << endl << endl;
        cout << "********************************\n" << endl;
        cout << "\n\t1) NEW ACCOUNT" << endl;
        cout << "\t2) DEPOSIT AMOUNT" << endl;
        cout << "\t3) WITHDRAW AMOUNT" << endl;
        cout << "\t4) BALANCE ENQUIRY" << endl;
        cout << "\t5) ALL ACCOUNT HOLDER LIST" << endl;
        cout << "\t6) CLOSE AN ACCOUNT" << endl;
        cout << "\t7) MODIFY AN ACCOUNT" << endl;
        cout << "\t8) EXIT" << endl;
        cout << "\n\t Select an option (1-8): ";
        cin >> ch;
        while(ch != '1' && ch != '2' && ch != '3' && ch != '4' &&ch != '5'
              && ch != '6' && ch != '7' &&ch != '8') {
            cout << "\nINVALID RESPONSE..." << endl;
            cout << "\n\t Select an option (1-8): ";
            cin >> ch;
        }

        system("cls");
        switch(ch) {

            case '1':
                writeAccount();
                break;
            case '2':
                cout << "\n\n\tEnter the account number: ";
                cin >> num;
                depositWithdraw(num, 1);
                break;
            case '3':
                cout << "\n\n\tEnter the account number: ";
                cin >> num;
                depositWithdraw(num, 2);
                break;
            case '4':
                cout << "\n\n\tEnter the account number: ";
                cin >> num;
                displaySP(num);
                break;
            case '5':
                displayAll();
                break;
            case '6':
                cout << "\n\n\tEnter the account number: ";
                cin >> num;
                deleteAccount(num);
                break;
            case '7':
                cout << "\n\n\tEnter the account number: ";
                cin >> num;
                modifyAccount(num);
                break;
            case '8':
                cout << "\n\n\tNOW EXITTING..." << endl;
                break;

        } //end switch

        cin.ignore();
        cin.get();

    }while(ch != '8');

    return 0;

} //end main
///==============================================================
void writeAccount() {

    Account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary|ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
    outFile.close();

    //intro();

}
///===========================================================
void displaySP(int n) {

    Account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile) {
        cout << "\nFILE NOT FOUND... Press any key";
        return;
    }

    cout << "\n********************************\n" << endl;
    cout << "\tBALANCE DETAILS" << endl << endl;
    cout << "********************************\n" << endl;

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        if(ac.returnAcNo() == n) {
            ac.showAccount();
            flag = true;
        } //end if
    } //end while

    inFile.close();
    if(flag == false) {
        cout << "\nAccount number does NOT EXIST" << endl;
    }

    //intro();

}
///===========================================================
void modifyAccount(int n) {

    bool found = false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File) {
        cout << "FILE COULD NOT OPEN... Press any key";
        return;
    }

    while(!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.returnAcNo() == n) {
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout << "\n\tRecord updated..." << endl;
            found = true;
        } //end if
    } //end while

    File.close();
    if(found == false) {
        cout << "\n\tRecord not found..." << endl;
    }

    //intro();

}
///===========================================================
void deleteAccount(int n) {

    Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile) {
        cout << "\nFILE ERROR... Press any key";
        return;
    }
    outFile.open("temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
            if(ac.returnAcNo() != n) {
                outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            } //end if
    } //end while

    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("temp.dat", "account.dat");
    cout << "\n\n\tRecord Deleted Successfully..." << endl;

}
///===========================================================
void displayAll() {

    Account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile) {
        cout << "\nFILE ERROR... Press any key";
        return;
    }

    cout << "\n\n********************************\n" << endl;
    cout << "\tACCOUNT HOLDER LIST" << endl << endl;
    cout << "********************************\n" << endl;
    cout << "=====================================================" << endl;
    cout << "Account #       NAME               TYPE      BALANCE    " << endl;
    cout << "=====================================================" << endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        ac.report();
    }
    inFile.close();

}
///===========================================================
void depositWithdraw(int n, int option) {

    double amount;
    bool found = false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File) {
        cout << "\nFILE ERROR... Press any key";
        return;
    }
    while(!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.returnAcNo() == n) {
            ac.showAccount();
            if(option == 1) {
                cout << "\n\n********************************\n" << endl;
                cout << "\tMAKE DEPOSIT" << endl << endl;
                cout << "********************************\n" << endl;
                cout << "\n\tEnter amount to deposit: $";
                cin >> amount;
                ac.dep(amount);
            }
            if(option == 2) {
                cout << "\n\n********************************\n" << endl;
                cout << "\tMAKE WITHDRAWL" << endl << endl;
                cout << "********************************\n" << endl;
                cout << "\n\tEnter amount to withdraw: $";
                cin >> amount;
                int bal = ac.returnDeposit() - amount;
                if((bal<500 && ac.returnType() == 'S') || (bal<1000 && ac.returnType() == 'C')) {
                   cout << "\n\tInsufficient Funds..." << endl;
                }
                else
                    ac.draw(amount);
            } //end if

            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout << "\n\n\tRecord Updated Successfully..." << endl;
            found = true;

        } //end if
    } //end while

    File.close();
    if(found == false) {
        cout << "\n\nRecord Not Found..." << endl;
    }

}
///===========================================================
void intro() {

    cout << "\n\n\n\t  BANK";
    cout << "\n\n\tMANAGEMENT";
    cout << "\n\n\t  SYSTEM";
    cout << "\n\n\t  v1.04";
    cout << "\n\n\n\n  PROGRAMMER: Jared Stevens";
    cin.get();

}
///===========================================================
