#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;

// This struct groups all related bank information.

struct account {
    string card_number;
    string cvv;
    string bank_name;
    double balance;

};

// Making sure every card number entered is unique.

bool isDuplicate(account all_users[], int count, string search_card) {

    for (int i = 0; i < count; i++) {
        if (all_users[i].card_number == search_card) {
           
            return true; // Found a duplicate.
        }
    }

    return false; // Did not find a duplicate.
}

// Using a pointer here is efficient because it passes the memory address.

void printAccount(account* a) {
    cout << "--------------------------" << endl;
    cout << "BANK:" << a->bank_name << endl;
    cout << "CARD NO:" << a->card_number << endl;
    cout << "BALANCE $:" << a->balance << endl;
    cout << "--------------------------" << endl;


}



int main()
{
    srand(time(0));

    account users[5];

    int current_index = 0;
    char choice;


    do {

    bool isInvalid;
    do {
        isInvalid = false;

        cout << "Enter Bank Name: " << endl;
        getline(cin >> ws, users[current_index].bank_name);
        if (users[current_index].bank_name.empty()) {
            cout << "Error! You did not type anything." << endl;
            isInvalid = true;
        }

        else {

            for (char c : users[current_index].bank_name) {

                if (isdigit(c)) {

                    cout << "Error! No numbers allowed in bank names." << endl;
                    isInvalid = true;
                    break;

                }
            }

        }


    } while (isInvalid == true);


    bool cardExists;
    do {
        cardExists = false;
        cout << "Enter Card Number (16 digits): " << endl;
        cin >> users[current_index].card_number;
        if (users[current_index].card_number.length() != 16) {
            cout << "Error! Card Number must be exactly 16 digits." << endl;
        }
        else {
            cardExists = isDuplicate(users, current_index, users[current_index].card_number);
            if (cardExists) {
                cout << "Error! This card number is already registered." << endl;
            }
        }

    } while (users[current_index].card_number.length() != 16 || cardExists==true);

    do {
        cout << "Enter CVV (3 digits): " << endl;
        cin >> users[current_index].cvv;

        if (users[current_index].cvv.length() != 3) {
            cout << "Error! CVV must be exactly 3 digits." << endl;
        }


    } while (users[current_index].cvv.length() != 3);


    users[current_index].balance = 1000 + (rand() % 50001); // Getting a number from 0 to 50000 and adding 1000 to ensure enough balance in the account.

    cout << "--- Account Created! ---" << endl;
    cout << "Bank name : " << users[current_index].bank_name << endl;
    cout << "Balance $ : " << users[current_index].balance << endl;

    printAccount(&users[current_index]);

    current_index++; // Adding another account.
    
        if (current_index < 5) {
            cout << "Do you want to add another account? (y/n):" << endl;
            cin >> choice;
        }
        else {
            cout << "Memory full!" << endl;
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
