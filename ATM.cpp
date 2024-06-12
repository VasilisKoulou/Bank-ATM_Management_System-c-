#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class bank {
private:
    double balance;
    string id, pwd, fname, lname, address, phone, pin;

public:
    void menu();
    void bank_management();
    void atm();
    void new_user();
    void user_exists();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del();
    void show_records();
    void show_payments();
    void user_balance();
    void withdraw_atm();
    void details();
};

void bank::menu() {
p:
    system("cls");
    int choice = 0;
    char ch;
    string pwd, pin, email;
    cout << "\n\n\t\t\t\t\t Financial Management System Menu:" << endl;
    cout << "\n\n 1) Bank Management" << endl;
    cout << "\n 2) ATM Management" << endl;
    cout << "\n 3) Exit" << endl;
    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        system("cls");
        cout << "\n\n\t\t\t\t\t Login Account" << endl;
        cout << "\n\n\n Email: ";
        cin >> email;
        cout << "\n\n PIN: ";
        for (int i = 0; i <= 4; i++) {
            ch = _getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Password: ";
        for (int i = 0; i <= 4; i++) {
            ch = _getch();
            pwd += ch;
            cout << "*";
        }
        if (email == "vasiliskoul@gmail.com" && pin == "12345" && pwd == "54321") {
            bank_management();
        }
        else {
            cout << "Your Email, Password or PIN is Wrong!";
        }
        break;
    case 2:
        atm();
        break;
    case 3:
        exit(0);
    default:
        cout << "Invalid Value. Try Again!";
    }
    _getch();
    goto p;
}

void bank::bank_management() {
p:
    system("cls");
    int choice = 0;
    cout << "\n\n\t\t\t\t\t Bank Management System" << endl;
    cout << "\n\n 1) New User" << endl;
    cout << "\n 2) User" << endl;
    cout << "\n 3) Deposit" << endl;
    cout << "\n 4) Withdraw" << endl;
    cout << "\n 5) Transfer" << endl;
    cout << "\n 6) Payment" << endl;
    cout << "\n 7) Search User" << endl;
    cout << "\n 8) Edit User" << endl;
    cout << "\n 9) Delete User" << endl;
    cout << "\n 10) Show All" << endl;
    cout << "\n 11) All Payments" << endl;
    cout << "\n 12) Go To Main Menu!" << endl;
    cout << "\n\n Enter Your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        new_user();
        break;
    case 2:
        user_exists();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        transfer();
        break;
    case 6:
        payment();
        break;
    case 7:
        search();
        break;
    case 8:
        edit();
        break;
    case 9:
        del();
        break;
    case 10:
        show_records();
        break;
    case 11:
        show_payments();
        break;
    case 12:
        cout << "You are going to the main menu!" << endl;
        menu();
        break;
    default:
        cout << "Invalid Value. Try Again!";
    }
    _getch();
    goto p;
}

void bank::atm() {
p:
    system("cls");
    int choice = 0;
    cout << "\n\n\t\t\t\t\t ATM Management System" << endl;
    cout << "\n\n 1) Check Balance" << endl;
    cout << "\n 2) Withdraw Amount" << endl;
    cout << "\n 3) Account Details" << endl;
    cout << "\n 4) Go Back" << endl;
    cout << "\n\n Enter Your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        user_balance();
        break;
    case 2:
        withdraw_atm();
        break;
    case 3:
        details();
        break;
    case 4:
        cout << "You are going to the main menu!" << endl;
        menu();
        break;
    default:
        cout << "Invalid Value. Try Again!";
    }
    _getch();
    goto p;
}

void bank::new_user() {
p:
    system("cls");
    fstream file;
    int p;
    float b;
    string fn, ln, pa, ad, ph, i;
    cout << "\n\n\t\t\t\t\t Add New User";
    cout << "\n\n User ID: ";
    cin >> id;
    cout << "\n\n First Name: ";
    cin >> fname;
    cout << "\n\n Last Name: ";
    cin >> lname;
    cout << "\n\n Address: ";
    cin >> address;
    cout << "\n\n PIN: ";
    cin >> pin;
    cout << "\n\n Password: ";
    cin >> pwd;
    cout << "\n\n Phone Number: ";
    cin >> phone;
    cout << "\n\n Balance: ";
    cin >> balance;
    file.open("bank.txt", ios::in);
    if (!file) {
        file.open("bank.txt", ios::app | ios::out);
        file << "  " << id << "                   " << fname << "                   " << lname << "                   "
            << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
            << "\n";
        file.close();
    }
    else {
        bool found = false;
        while (file >> i >> fn >> ln >> ad >> p >> pa >> ph >> b) {
            if (i == id) {
                cout << "\n\n User ID Already Exists! ";
                found = true;
                break;
            }
        }
        file.close();
        if (!found) {
            file.open("bank.txt", ios::app);
            file << "  " << id << "                   " << fname << "                   " << lname << "                   "
                << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                << "\n";
            file.close();
            
        }
    }
    cout << "\n\n New User Account Created Successfully!";
}

void bank::user_exists()
{
    system("cls");
    fstream file;
    string t_id;
    bool found = false;
    cout << "\n\n\t\t\t\t\t User Account Exists" << endl;
    file.open("bank.txt", ios::in);
    if (!file) 
    {
        cout << "\n\n File Opening Error!";
    }
    else
    {
        cout << "\n\n User ID:";
        cin >> t_id;
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {

            if (t_id == id)
            {
                system("cls");
                cout << "\n\n\t\t\t User Account Already Exists!";
                cout << "\n\n User ID: " << id << "\n\n PIN: " << pin << "\n\n Password: " << pwd << endl;
                found++;
            }
         file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        if (found == false) {
            cout << "User ID Can't Be Found";
        }
    }
}

void bank::deposit()
{
    fstream file, file1;
    string t_id;
    double dep;
    bool found = false;
    system("cls");
    cout << "\n\n\t\t\t\t\t Deposit Amount" << endl;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error!";
    }
    else
    {
        cout << "\n\n User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {

            if (t_id == id)
            {
                cout << "\n\n Amount for Deposit: ";
                cin >> dep;
                balance += dep;
                file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                    << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                    << "\n";
                found++;
                cout << "\n\n\t\t\t\t Your Amount " << dep << " Successfully Deposit!";
            }
            else
            {
                file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                    << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                    << "\n";
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == false) {
            cout << "User ID Can't Be Found";
        }
    }
}

void bank::withdraw()
{
    fstream file, file1;
    string t_id;
    double wdr;
    bool found = false;
    system("cls");
    cout << "\n\n\t\t\t\t\t Withdraw Amount" << endl;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error!";
    }
    else
    {
        cout << "\n\n User ID:";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {

            if (t_id == id)
            {
                cout << "\n\n Amount for Withdraw: ";
                cin >> wdr;
                if (wdr <= balance) 
                {
                    balance -= wdr;
                    file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                        << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                        << "\n";
                    cout << "\n\n\t\t\t\t Your Amount " << wdr << " Successfully Withdraw!";
                }
                else
                {
                    cout << "\n\n\t\t\t\t Your current balance " << balance << " is not Sufficient";
                }
                found++;
            }
            else
            {
                file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                    << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                    << "\n";
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == false) {
            cout << "User ID Can't Be Found";
        }
    }
}
void bank::transfer()
{
    fstream file, file1;
    string r_id, s_id;
    int found = 0;
    double amount;
    system("cls");
    cout << "\n\n\t\t\t\t\t Transfer";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error!";
        return;  
    }

    cout << "\n\n Sender User ID For Transaction: ";
    cin >> s_id;
    cout << "\n\n Receiver User ID For Transaction: ";
    cin >> r_id;
    cout << "\n\n Enter Transaction Amount: ";
    cin >> amount;

    file1.open("bank1.txt", ios::app | ios::out);
    if (!file1)
    {
        cout << "\n\n File Opening Error!";
        file.close();  
        return;  
    }

    string id, fname, lname, address, pin, pwd, phone;
    double balance;
    file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;

    while (file)
    {
        if (s_id == id && amount <= balance)
            found++;
        else if (r_id == id)
            found++;

        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
    }

    if (found == 2)
    {
        file.clear();  // Clear EOF flag to enable re-reading the file
        file.seekg(0);  // Go back to the beginning of the file
        file1.seekp(0, ios::end);  // Move to the end of the file to append data
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;

        while (file)
        {
            if (s_id == id && amount <= balance)
            {
                balance -= amount;
            }
            else if (r_id == id)
            {
                balance += amount;
            }

            file1 << id << " " << fname << " " << lname << " " << address << " " << pin << " " << pwd << " " << phone << " " << balance << "\n";
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }

        file.close();
        file1.close();

        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        cout << "\n\n\t\t\t\t\t Transaction Successfully Completed!";
    }
    else
    {
        cout << "\n\n\t\t\t\t\t Both Transaction IDs Not Valid!";
        file.close();
        file1.close();
        remove("bank1.txt");
    }
}
void bank::payment() 
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string t_id, b_name;
    double amount;
    SYSTEMTIME x;
    cout << "\n\n\t\t\t Bill Payment" << endl;
    file.open("bank.txt", ios::in);
    if (!file) 
    {
        cout << "\n\n File Opening Error";
    }
    else 
    {
        cout << "\n\n Enter User ID : ";
        cin >> t_id;
        cout << "\n\n Bill Name: ";
        cin >> b_name;
        cout << "\n\n Bill Amount: ";
        cin >> amount;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;

        while (!file.eof())
        {
            if (t_id == id && amount <= balance)
            {
                balance -= amount;
                file1 << id << " " << fname << " " << lname << " " << address << " " << pin << " " << pwd << " " << phone << " " << balance << "\n";
                found++;
            }
            else
            {
                file1 << id << " " << fname << " " << lname << " " << address << " " << pin << " " << pwd << " " << phone << " " << balance << "\n";
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        file1.close();

        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 1)
        {
            GetSystemTime(&x);
            file.open("bill.txt", ios::app | ios::out);
            file << t_id << " " << b_name << " " << amount << " " << x.wDay << "/" << x.wMonth << "/" << x.wYear << "\n";
            file.close();
            cout << "\n\n\t\t\t " << b_name << "Bill Pay Successfull";
        }
        else
        {
            cout << "\n\n\t\t\t User ID or Amount Invalid";
        }

    }
}
void bank::search()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n\t\t\t Seach User" << endl;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                system("cls");
                cout << "\n\n\t\t\t Search User";
                cout << "\n\n\n " << id << " Surname: " << lname << " First Name: " << fname << endl;
                cout << " Address: " << address << " PIN: " << pin << " Password: " << pwd << endl;
                cout << " Phone Number: " << phone << " Current Balance: " << balance;
                found++;
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n User ID Can't Be Found!";
        }
    }
}
void bank::edit()
{
    system("cls");
    fstream file, file1;
    string t_id, ps, fn,ln,ad,ph;
    int found = 0, p;
    cout << "\n\n\t\t\t Edit User";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                cout << "\n\n First Name: ";
                cin >> fn;
                cout << "\n\n Last Name: ";
                cin >> ln;
                cout << "\n\n Address: ";
                cin >> ad;
                cout << "\n\n PIN: ";
                cin >> p;
                cout << "\n\n Password: ";
                cin >> ps;
                cout << "\n\n Phone Number: ";
                cin >> ph;
                file1 << id << " " << fn << " " << ln << " " << ad << " " << p << " " << ps << " " << ph << " " << balance << "\n";
                cout << "\n\n\n\t\t Update Successful";
                found++;
            }
            else
            {
                file1 << id << " " << fname << " " << lname << " " << address << " " << pin << " " << pwd << " " << phone << " " << balance << "\n";
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");

        if (found == 0)
        {
            cout << "\n\n User ID Can't Be Found!";
        }
    }    
}

void bank::del()
{
    system("cls");
    fstream file, file1;
    string t_id;
    int found = 0;
    cout << "\n\n\t\t\t Edit User";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {               
                cout << "\n\n\n\t\t Delete is Successful";
                found++;
            }
            else
            {
                file1 << id << " " << fname << " " << lname << " " << address << " " << pin << " " << pwd << " " << phone << " " << balance << "\n";
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0)
        {
            cout << "\n\n User ID Can't Be Found!";
        }
    }
}
void bank::show_records()
{
    system("cls");
    fstream file;
    int found = 0;
    cout << "\n\n\t\t\t Show All User Records";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error";
    }
    else
    {    
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {
            cout << "\n\n\n User ID: " << id;
            cout << "\n\n\n Last Name: " << lname;
            cout << "\n\n\n First Name: " << fname;
            cout << "\n\n\n Address: " << address;
            cout << "\n\n\n PIN: " << pin;
            cout << "\n\n\n Password: " << pwd;
            cout << "\n\n\n Phone Number: " << phone;
            cout << "\n\n\n Current Balance: " << balance;
            cout << "\n\n----------------------------------------";
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
            found++;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Data Base is Empty";
        }
    }
}
void bank::show_payments()
{
    system("cls");
    fstream file;
    int found = 0;
    double amount;
    string c_date;
    cout << "\n\n\t\t\t Show All Bill Records";
    file.open("bill.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error";
    }
    else
    {
        file >> id >> lname >> amount >> c_date;
        while (!file.eof())
        {
            cout << "\n\n\n User ID: " << id;
            cout << "\n\n\n Bill Name: " << lname;
            cout << "\n\n\n Bill Amount: " << amount;
            cout << "\n\n\n Date: " << c_date;
            cout << "\n\n----------------------------------------";
            file >> id >> lname >> amount >> c_date;
            found++;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Data Base is Empty";
        }
    }
}
void bank::user_balance()
{
    system("cls");
    fstream file;
    string t_id, t_pin, t_pwd;
    int found = 0;
    char ch;
    cout << "\n\n\t\t\t\t Login & Check Balance";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        cout << "\n PIN: ";
        for (int i = 1; i <= 5; i++)
        {
            ch = _getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password: ";
        for (int i = 1; i <= 5; i++)
        {
            ch = _getch();
            t_pwd += ch;
            cout << "*";
        }
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id && t_pin == pin && t_pwd == pwd)
            {
                cout << "\n\n\t\t\t Your Current Balance is: " << balance;
                found++;
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n\t\t\t User ID, PIN or Password is Invalid";
        }
    }
}
void bank::withdraw_atm()
{
    system("cls");
    cout << "\n\n\t\t\t WithDraw";
    fstream file, file1;
    string t_id, t_pwd, t_pin;
    char ch;
    double wdr;
    bool found = false;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error!";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        cout << "\n PIN: ";
        for (int i = 1; i <= 5; i++)
        {
            ch = _getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password: ";
        for (int i = 1; i <= 5; i++)
        {
            ch = _getch();
            t_pwd += ch;
            cout << "*";
        }
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {

            if (t_id == id && t_pin == pin && t_pwd == pwd)
            {
                cout << "\n\n Amount for Withdraw: ";
                cin >> wdr;
                if (wdr <= balance)
                {
                    balance -= wdr;
                    file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                        << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                        << "\n";
                    cout << "\n\n\t\t\t\t Your Amount: " << wdr << " Successfully Withdraw!";
                    cout << "\n\n\t\t\t\t Your current balance: " << balance;
                }
                else
                {
                    file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                        << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                        << "\n";
                    cout << "\n\n\t\t\t\t Your current balance: " << balance << " is not Sufficient";
                }
                found++;
            }
            else
            {
                file1 << "  " << id << "                   " << fname << "                   " << lname << "                   "
                    << address << "                   " << pin << "    " << pwd << "         " << phone << "         " << balance
                    << "\n";
            }
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == false) {
            cout << "User ID Can't Be Found";
        }
    }
}
void bank::details()
{
    system("cls");
    cout << "\n\n\t\t\t Account Details";
    fstream file;
    string t_id, t_pwd, t_pin;
    char ch;
    bool found = false;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error!";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        cout << "\n PIN: ";
        for (int i = 1; i <= 5; i++)
        {
            ch = _getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password: ";
        for (int i = 1; i <= 5; i++)
        {
            ch = _getch();
            t_pwd += ch;
            cout << "*";
        }
        file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        while (!file.eof())
        {

            if (t_id == id && t_pin == pin && t_pwd == pwd)
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t Details";
                cout << "\n\n\n User ID: " << id;
                cout << "\n\n\n Last Name: " << lname;
                cout << "\n\n\n First Name: " << fname;
                cout << "\n\n\n Address: " << address;
                cout << "\n\n\n PIN: " << pin;
                cout << "\n\n\n Password: " << pwd;
                cout << "\n\n\n Phone Number: " << phone;
                cout << "\n\n\n Current Balance: " << balance;
                found++;
            }
           
            file >> id >> fname >> lname >> address >> pin >> pwd >> phone >> balance;
        }
        file.close();
        if (found == false) {
            cout << "User ID Can't Be Found";
        }
    }
}
int main() {
	bank obj;
	obj.menu();
}