#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//**********************************************************

class MENU
{
private:
    void edit_menu(void);
    void edit_item(void);
    void edit_shop(void);

public:
    void main_menu();
    void introduction();
};

//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO BOOKS
//**********************************************************

class ITEM
{
protected:
    void add_new_item(int, string tname, string tbrand, float);
    void deletion(void);
    int item_found(int);
    int itemname_found(string);
    int recordno(int);
    string brandname(int);
    float itemprice(int);
    int itemcodeof(string);
    void display(int);
    int reccount(void);
    void delete_rec(int);

private:
    int itemcode;
    string name, brand;
    float price;

public:
    void list(void);
    string itemname(int);
};

//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO MEMBERS
//**********************************************************

class SHOP
{
protected:
    void add_shop(int, int, string, string, string);
    bool shop_found(int);
    string shopname(int);
    string shopphone(int);
    string shopaddress(int);
    int recordno(int);
    void display(int);
    void delete_rec(int);

public:
    int shopcode, itemcode;
    string name, phone, address;

    void list(void);
};

//**********************************************************
// FUNCTION TO DISPLAY MAIN MENU & CONTROL ALL THE FUNCTION
// IN THE MAIN MENU.
//**********************************************************

class WORKING : public ITEM, public SHOP
{
public:
    void add_item(void);
    void add_shop(void);
    void delete_item(void);
    void delete_shop(void);
};

//**********************************************************
// FUNCTION TO DISPLAY MAIN MENU & CONTROL ALL THE FUNCTION
// IN THE MAIN MENU.
//**********************************************************

void MENU::main_menu(void)
{
    char ch;
    while (1)
    {
        system("clear");
        cout << "S H O P P I N G M A L L" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. INTRODUCTION" << endl;
        cout << "2. ADD NEW ITEM" << endl;
        cout << "3. ADD NEW SHOP" << endl;
        cout << "4. LIST OF ITEMS" << endl;
        cout << "5. LIST OF SHOPS" << endl;
        cout << "6. EDIT" << endl;
        cout << "0. QUIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
        switch(ch)
        {
            case '1':
                introduction();
                break;
            case '2':
            {
                WORKING W;
                W.add_item();
                break;
            }
            case '3':
            {
                WORKING W;
                W.add_shop();
                break;
            }
            case '4':
            {
                ITEM I;
                I.list();
                break;
            }
            case '5':
            {
                SHOP S;
                S.list();
                break;
            }
            case '6':
                edit_menu();
                break;
            case '0':
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//**********************************************************
// FUNCTION TO DISPLAY EDIT MENU
//**********************************************************

void MENU::edit_menu(void)
{
    char ch;
    while (1)
    {
        system("clear");
        cout << "E D I T M E N U" << endl;
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "1. ITEMS" << endl;
        cout << "2. SHOPS" << endl;
        cout << "0. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
        switch(ch)
        {
            case '1':
                edit_item();
                break;
            case '2':
                edit_shop();
                break;
            case '0':
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//**********************************************************
// FUNCTION TO DISPLAY EDIT MENU FOR BOOK & CONTROL
// ALL THE FUNCTION IN THE EDIT MENU.
//**********************************************************

void MENU::edit_item(void)
{
    char ch;
    while (1)
    {
        system("clear"); // For Linux/OSX, use "cls" for Windows
        cout << "E D I T I T E M S" << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. DELETE" << endl;
        cout << "0. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
        switch(ch)
        {
            case '1':
            {
                WORKING W;
                W.delete_item();
                break;
            }
            case '0':
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//**********************************************************
// FUNCTION TO DISPLAY EDIT MENU FOR MEMBERS & CONTROL
// ALL THE FUNCTION IN THE EDIT MENU.
//**********************************************************

void MENU::edit_shop(void)
{
    char ch;
    while (1)
    {
        system("clear"); // For Linux/OSX, use "cls" for Windows
        cout << "E D I T S H O P S" << endl;
        cout << "------------------------" << endl;
        cout << "1. DELETE" << endl;
        cout << "0. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
        switch(ch)
        {
            case '1':
            {
                WORKING W;
                W.delete_shop();
                break;
            }
            case '0':
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//**********************************************************
// FUNCTION TO DISPLAY THE INTRODUCTION FOR THE PROJECT.
//**********************************************************

void MENU::introduction(void)
{
    system("clear"); // For Linux/OSX, use "cls" for Windows
    cout << "Welcome to Project" << endl;
    cout << " SHOPPING MALL " << endl;
    cout << "This project has facility of maintaining records" << endl;
    cout << "of SHOPS and their ITEMS." << endl;
    cout << "Press any key to continue" << endl;
    cin.get(); // wait for any key
}

//**********************************************************
// THIS FUNCTION RETURN 0 IF GIVEN BOOK CODE NOT FOUND
//**********************************************************

int ITEM::item_found(int tcode)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0;
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.itemcode == tcode)
        {
            file.close();
            return 1;
        }
    }

    file.close();
    return 0;
}

//**********************************************************
// THIS FUNCTION RETURN 0 IF GIVEN BOOK NAME NOT FOUND
//**********************************************************

int ITEM::itemname_found(string t1code)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0;
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.name == t1code)
        {
            file.close();
            return 1;
        }
    }

    file.close();
    return 0;
}

//**********************************************************
// THIS FUNCTION RETURN RECORD NO. FOR THE BOOK CODE
//**********************************************************

int ITEM::recordno(int tcode)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0;
    }

    ITEM temp;
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        count++;
        if (temp.itemcode == tcode)
        {
            file.close();
            return count;
        }
    }

    file.close();
    return 0;
}

//**********************************************************
// THIS FUNCTION RETURNS THE BOOK NAME OF THE GIVEN BOOK
// CODE.
//**********************************************************

string ITEM::itemname(int tcode)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return "";
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.itemcode == tcode)
        {
            file.close();
            return temp.name;
        }
    }

    file.close();
    return "";
}

//**********************************************************
// THIS FUNCTION RETURNS THE AUTHOR NAME OF THE GIVEN BOOK
// CODE.
//**********************************************************

string ITEM::brandname(int tcode)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return "";
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.itemcode == tcode)
        {
            file.close();
            return temp.brand;
        }
    }

    file.close();
    return "";
}

//**********************************************************
// THIS FUNCTION RETURNS THE BOOK PRICE OF THE GIVEN BOOK
// CODE.
//**********************************************************

float ITEM::itemprice(int tcode)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0.0;
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.itemcode == tcode)
        {
            file.close();
            return temp.price;
        }
    }

    file.close();
    return 0.0;
}

//**********************************************************
// THIS FUNCTION RETURNS THE BOOK CODE OF THE GIVEN BOOK
// NAME.
//**********************************************************

int ITEM::itemcodeof(string t1code)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0;
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.name == t1code)
        {
            file.close();
            return temp.itemcode;
        }
    }

    file.close();
    return 0;
}

//**********************************************************
// THIS FUNCTION RETURNS THE NO. OF THE RECORDS IN THE BOOK
// FILE.
//**********************************************************

int ITEM::reccount(void)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0;
    }

    ITEM temp;
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        count++;
    }

    file.close();
    return count;
}

//**********************************************************
// THIS FUNCTION DELETES THE RECORD OF THE GIVEN BOOK CODE.
//**********************************************************

void ITEM::delete_rec(int tcode)
{
    ifstream inFile("ITEM.DAT", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    if (!inFile || !outFile)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }

    ITEM temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.itemcode != tcode)
        {
            outFile.write(reinterpret_cast<const char*>(&temp), sizeof(ITEM));
        }
    }

    inFile.close();
    outFile.close();

    // Overwrite the original file with the temporary file
    remove("ITEM.DAT");
    rename("temp.dat", "ITEM.DAT");
}

//**********************************************************
// THIS FUNCTION ADD THE RECORD IN THE BOOK FILE
//**********************************************************

void ITEM::add_new_item(int tcode, string tname, string tbrand, float tprice)
{
    ofstream file("ITEM.DAT", ios::binary | ios::app);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }

    itemcode = tcode;
    name = tname;
    brand = tbrand;
    price = tprice;
    file.write(reinterpret_cast<const char*>(this), sizeof(ITEM));

    file.close();
}

//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD FROM THE BOOK FILE
// FOR THE GIVEN BOOK CODE
//**********************************************************

void ITEM::display(int tcode)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }

    ITEM temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        if (temp.itemcode == tcode)
        {
            cout << "item Code : " << temp.itemcode << "\n";
            cout << "item Name : " << temp.name << "\n";
            cout << "brand Name : " << temp.brand << "\n";
            cout << "Price : Rs." << temp.price << "\n";
            break;
        }
    }

    file.close();
}

//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF BOOKS.
//**********************************************************

void ITEM::list(void)
{
    ifstream file("ITEM.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }

    cout << "LIST OF ITEMS\n";
    cout << "~~~~~~~~~~~~~~~\n";
    cout << "CODE ITEM NAME BRAND PRICE\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    ITEM temp;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(ITEM)))
    {
        found = true;
        this_thread::sleep_for(chrono::milliseconds(20)); // delay for 20 milliseconds
        cout << temp.itemcode << " " << temp.name << " " << temp.brand << " " << temp.price << "\n";
    }

    if (!found)
    {
        cout << "\7Records not found\n";
    }

    cout << "Press any key to continue...";
    cin.get();

    file.close();
}

//**********************************************************
// THIS FUNCTION RETURN 0 IF THE GIVEN MEMBER CODE NOT FOUND
//**********************************************************

bool SHOP::shop_found(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return false;
    }

    SHOP temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        if (temp.shopcode == mcode)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

//**********************************************************
// THIS FUNCTION RETURNS MEMBER NAME OF THE GIVEN MEMBER
// CODE.
//**********************************************************

#include <fstream>
#include <string>

using namespace std;

string SHOP::shopname(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return "";
    }

    SHOP temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        if (temp.shopcode == mcode)
        {
            file.close();
            return temp.name;
        }
    }

    file.close();
    return "";
}

//**********************************************************
// THIS FUNCTION RETURNS MEMBER PHONE OF THE GIVEN MEMBER
// CODE.
//**********************************************************

string SHOP::shopphone(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return "";
    }

    SHOP temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        if (temp.shopcode == mcode)
        {
            file.close();
            return temp.phone;
        }
    }

    file.close();
    return "";
}

//**********************************************************
// THIS FUNCTION RETURNS MEMBER ADDRESS OF THE GIVEN MEMBER
// CODE.
//**********************************************************

string SHOP::shopaddress(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return "";
    }

    SHOP temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        if (temp.shopcode == mcode)
        {
            file.close();
            return temp.address;
        }
    }

    file.close();
    return "";
}

//**********************************************************
// THIS FUNCTION RETURNS RECORD NO. OF THE GIVEN MEMBER
// CODE.
//**********************************************************

int SHOP::recordno(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 0;
    }

    SHOP temp;
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        count++;
        if (temp.shopcode == mcode)
        {
            file.close();
            return count;
        }
    }

    file.close();
    return 0;
}

//**********************************************************
// THIS FUNCTION DELETE RECORD FOR THE GIVEN MEMBER CODE.
//**********************************************************

void SHOP::delete_rec(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    SHOP shop;
    while (file.read(reinterpret_cast<char*>(&shop), sizeof(SHOP)))
    {
        if (shop.shopcode != mcode)
        {
            temp.write(reinterpret_cast<const char*>(&shop), sizeof(SHOP));
        }
    }
    file.close();
    temp.close();

    remove("SHOP.DAT");
    rename("temp.dat", "SHOP.DAT");
}

//**********************************************************
// THIS FUNCTION ADD RECORD IN THE FILE FOR THE GIVEN
// MEMBER CODE.
//**********************************************************

void add_shop(int mcode, int bcode, string mname, string maddress, string mphone) {
        ofstream file("SHOP.DAT", ios::binary | ios::app);
        SHOP shop;
        shop.shopcode = mcode;
        shop.shopcode = bcode;
        shop.name = mname;
        shop.address = maddress;
        shop.phone = mphone;
        file.write(reinterpret_cast<const char*>(&shop), sizeof(SHOP));
        file.close();
    }

//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD FOR THE GIVEN MEMBER
// CODE.
//**********************************************************

void SHOP::display(int mcode)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }

    SHOP temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        if (temp.shopcode == mcode)
        {
            cout << "shop Code # " << mcode << "\n";
            cout << "~~~~~~~~~~~~~~~~~\n";
            cout << "Name : " << temp.name << "\n";
            cout << "Phone : " << temp.phone << "\n";
            cout << "Address : " << temp.address << "\n";
            break;
        }
    }

    file.close();
}

//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE MEMBERS
//**********************************************************

void SHOP::list(void)
{
    ifstream file("SHOP.DAT", ios::binary);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }

    cout << "LIST OF SHOPS\n";
    cout << "~~~~~~~~~~~~~~~~~\n";
    cout << "CODE SHOP CODE NAME PHONE\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    SHOP temp;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(SHOP)))
    {
        found = true;
        this_thread::sleep_for(chrono::milliseconds(20)); // delay for 20 milliseconds
        cout << temp.shopcode << " " << temp.shopcode << " " << temp.name << " " << temp.phone << "\n";
    }

    if (!found)
    {
        cout << "\nRecords not found\n";
    }

    cout << "Press any key to continue...";
    cin.get();

    file.close();
}

//**********************************************************
// THIS FUNCTION GIVES DATA TO ADD RECORD IN THE BOOK FILE.
//**********************************************************

void WORKING::add_item()
{
    if (!reccount()) // MEMBER FUNCTION OF BOOK
    {
        add_new_item(0, "null", "null", 0.0);
        ITEM::delete_rec(0);
    }

    char ch;
    int tcode;
    string tname, tbrand;
    float tprice = 0.0;

    do
    {
        int found = 0, valid = 0;
        int tc;
        float t2 = 0.0;
        string t, t1;

        cout << "ADDITION OF THE ITEMS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "<0>=Exit\n";
        cout << "Enter code no. of the item\n";
        cout << "Code no. ";
        getline(cin, t);
        tc = stoi(t);
        tcode = tc;

        if (tcode == 0)
            return;

        if (item_found(tcode))
        {
            found = 1;
            cout << itemname(tcode) << "\n";
            cout << brandname(tcode) << "\n";
            cout << itemprice(tcode) << "\n";
        }

        cout << "item Name : ";
        cout << "brand Name : ";
        cout << "Price : Rs.";

        while (!valid && !found)
        {
            valid = 1;
            cout << "Enter the name of the item\n";
            getline(cin, tname);
            if (tname[0] == '0')
                return;
            if (tname.length() < 1 || tname.length() > 32)
            {
                valid = 0;
                cout << "\nEnter correctly (Range: 1..32)\n";
                cin.get();
            }
        }

        while (!valid && !found)
        {
            valid = 1;
            cout << "Enter the brand`s name of the book\n";
            getline(cin, tbrand);
            if (tbrand[0] == '0')
                return;
            if (tbrand.length() < 1 || tbrand.length() > 25)
            {
                valid = 0;
                cout << "\7Enter correctly (Range: 1..25)\n";
                cin.get();
            }
        }

        while (!valid && !found)
        {
            valid = 1;
            cout << "Enter the price of the item\n";
            getline(cin, t1);
            t2 = stof(t1);
            tprice = t2;
            if (t1[0] == '0')
                return;
            if (tprice < 1 || tprice > 9999)
            {
                valid = 0;
                cout << "\7Enter correctly\n";
                cin.get();
            }
        }

        do
        {
            cout << "Do you want to save (y/n) : ";
            cin >> ch;
            ch = toupper(ch);
        } while (ch != 'Y' && ch != 'N');

        if (ch == 'Y')
        {
            add_new_item(tcode, tname.c_str(), tbrand.c_str(), tprice);
        }

        do
        {
            cout << "Do you want to add more (y/n) : ";
            cin >> ch;
            ch = toupper(ch);
        } while (ch != 'Y' && ch != 'N');

    } while (ch == 'Y');
}

//**********************************************************
// THIS FUNCTION GIVES DATA TO ADD RECORD IN THE MEMBER FILE
//**********************************************************

void WORKING::add_shop()
{
    char ch;
    int mcode, bcode;
    string mname, mphone, maddress;

    do
    {
        int valid = 0;

        cout << "ADDITION OF THE SHOPS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "<0>=Exit\n";
        cout << "SHOP Code # " << mcode << "\n";
        cout << "~~~~~~~~~~~~~~~~~\n";
        cout << "Name : \n";
        cout << "Phone : \n";
        cout << "Address : \n";

        do
        {
            valid = 1;
            cout << "Enter the name of the New Shop\n";
            getline(cin, mname);
            if (mname[0] == '0')
                return;
            if (mname.length() < 1 || mname.length() > 25)
            {
                valid = 0;
                cout << "\7Enter correctly (Range: 1..25)\n";
                cin.get();
            }
        } while (!valid);

        do
        {
            valid = 1;
            cout << "Enter Phone no. of the Member or Press <ENTER> for none\n";
            getline(cin, mphone);
            if (mphone[0] == '0')
                return;
            if ((mphone.length() < 7 && mphone.length() > 0) || (mphone.length() > 9))
            {
                valid = 0;
                cout << "\7Enter correctly\n";
                cin.get();
            }
        } while (!valid);

        if (mphone.length() == 0)
            mphone = "-";

        do
        {
            valid = 1;
            cout << "Enter the address of the New Shop\n";
            getline(cin, maddress);
            if (maddress[0] == '0')
                return;
            if (maddress.length() < 1 || maddress.length() > 32)
            {
                valid = 0;
                cout << "\7Enter correctly (Range: 1..32)\n";
                cin.get();
            }
        } while (!valid);

        do
        {
            cout << "Do you want to save (y/n) : ";
            cin >> ch;
            ch = toupper(ch);
            if (ch == '0')
                return;
        } while (ch != 'Y' && ch != 'N');

        if (ch == 'Y')
        {
            add_shop();
            mcode++;
        }

        do
        {
            cout << "Do you want to add more (y/n) : ";
            cin >> ch;
            ch = toupper(ch);
            if (ch == '0')
                return;
        } while (ch != 'Y' && ch != 'N');

    } while (ch == 'Y');
}

//**********************************************************
// THIS FUNCTION GIVES BOOK CODE TO DELETE THE BOOK RECORD
//**********************************************************

void WORKING::delete_item()
{
    ITEM I;
    string t1code;
    char ch;
    int tcode = 0;
    int valid;

    do
    {
        valid = 1;
        while (1)
        {
            cout << "<0>=Exit\n";
            cout << "Enter Code or Name of the Item to be Deleted\n";
            cout << " or \n";
            cout << "Press <ENTER> for help \n";
            getline(cin, t1code);
            if (t1code[0] == '0')
                return;
            if (t1code.length() == 0)
                I.list();
            else
                break;
        }
        tcode = stoi(t1code);
        if ((tcode == 0 && !itemname_found(t1code)) || (tcode != 0 && !item_found(tcode)))
        {
            valid = 0;
            cout << " Record not found\n";
            cout << "Press <ESC> to exit or any other key to continue...\n";
            cin >> ch;
            if (ch == 27)
                return;
        }
    } while (!valid);

    if (tcode == 0)
        tcode = itemcodeof(t1code);

    cout << "<0>=Exit\n";
    ITEM::display(tcode);

    do
    {
        cout << "Do you want to delete this record (y/n) : ";
        cin >> ch;
        ch = toupper(ch);
        if (ch == '0')
            return;
    } while (ch != 'Y' && ch != 'N');

    if (ch == 'N')
        return;

    ITEM::delete_rec(tcode);
    cout << " Record Deleted\n";
    cin.get();
}

//**********************************************************
// THIS FUNCTION GIVES MEMBER CODE TO DELETE THE MEMBER
// RECORD
//**********************************************************

void WORKING::delete_shop()
{
    SHOP S;
    string m1code;
    char ch;
    int mcode = 0;
    int valid;

    do
    {
        valid = 1;
        while (1)
        {
            cout << "<0>=Exit\n";
            cout << "Enter Code no. of the Shop to be Deleted\n";
            cout << " or \n";
            cout << "Press <ENTER> for help \n";
            getline(cin, m1code);
            mcode = stoi(m1code);
            if (m1code[0] == '0')
                return;
            if (m1code.length() == 0)
                S.list();
            else
                break;
        }
        if (mcode == 0)
        {
            valid = 0;
            cout << "\7Enter Correctly\n";
            cin.get();
        }
        if (valid && !shop_found(mcode))
        {
            valid = 0;
            cout << "\7Record not found\n";
            cout << "Press <ESC> to exit or any other key to continue...\n";
            cin >> ch;
            if (ch == 27)
                return;
        }
    } while (!valid);

    cout << "<0>=Exit\n";
    SHOP::display(mcode);

    do
    {
        cout << "Do you want to Delete this record (y/n) : ";
        cin >> ch;
        ch = toupper(ch);
        if (ch == '0')
            return;
    } while (ch != 'Y' && ch != 'N');

    if (ch == 'N')
        return;

    SHOP::delete_rec(mcode);
    cout << "\7Record deleted\n";
    cin.get();
}

//**********************************************************
// MAIN FUNCTION CALLING INTRODUCTION AND MAIN MENU
//**********************************************************

int main()
{
    MENU menu;
    menu.introduction();
    menu.main_menu();

    return 0;
}