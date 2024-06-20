#include <iostream>
using namespace std;

double balance;
string transactions[100];
int transactionCount = 0;

void displayBalance() {
    cout << "\nCurrent Account Balance: $." << balance << endl;
}

void Deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions[transactionCount++] = "Deposit: $." + to_string(amount);
        cout << "\nDeposit successful your new balance: $." << balance << endl;
    } else {
        cout << "\nInvalid deposit amount. Please enter a positive amount." << endl;
    }
}

void Withdrawal(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactions[transactionCount++] = "Withdrawal: $." + to_string(amount);
        cout << "\nWithdrawal successful new balance: $." << balance << endl;
    } else {
        cout << "\nNot enough Balance. Choose from Current Balance = $." << balance << endl;
    }
}

void TransactionHistory() {
    cout << "\nTransaction History:\n" << endl;
    int n = 1; ;
    for (int i = 0; i < transactionCount; i++) {
        cout << n++ << ") " << transactions[i] + "\n" << endl;
    }
}

int main() {
    double amount;
    cout << "\nWelcome to Yashraj Bank" << endl;

    int option;
    do {
        cout << "\n 1. View Account Balance\n 2. Deposit Money\n 3. Withdraw Money\n 4. Show Past Transactions\n 5. Quit" << endl;
        cout << "\nSelect what to do: ";
        
        if (!(cin >> option)) {
            cout << "\nInvalid input. Please enter a Number." << endl;
            cin.clear();               
            cin.ignore();  
        }

        switch (option) {
            case 1:
                displayBalance();
                break;

            case 2:
                cout << "\nEnter Deposit amount: ";
                cin >> amount;
                Deposit(amount);
                break;

            case 3:
                cout << "\nEnter Withdrawal amount: ";
                cin >> amount;
                Withdrawal(amount);
                break;

            case 4:
                TransactionHistory();
                break;

            case 5:
                cout << "\nThank you Vist Again" << endl;
                break;

            default:
                cout << "\nChoose a valid option." << endl;
        }

    } while (option != 5);

    return 0;
}

// //another code


// #include <iostream>
// #include <cstring>
// using namespace std;

// struct Transaction {
//     char type[20];
//     double amount;

//     Transaction() : amount(0) {
//         type[0] = '\0';  
//     }

//     Transaction(const char* t, double a) : amount(a) {
//         strncpy(type, t, sizeof(type) - 1);
//         type[sizeof(type) - 1] = '\0';  
//     }
// };

// struct BankAccount {
//     char accountNumber[20];
//     double balance;
//     static const int MAX_HISTORY = 10;
//     Transaction transactionHistory[MAX_HISTORY];
//     int transactionCount = 0;

//     BankAccount(const char* accountNumber, double initialBalance) : balance(initialBalance) {
//         strncpy(this->accountNumber, accountNumber, sizeof(this->accountNumber) - 1);
//         this->accountNumber[sizeof(this->accountNumber) - 1] = '\0'; 
//         addTransaction("Account opened with initial balance", initialBalance);
//     }

//     void displayBalance() const {
//        cout << "Your account balance is: ₹" << balance <<endl;
//     }

//     void deposit() {
//         double amount;
//         bool validInput = false;

//         do {
//            cout << "Enter amount to deposit: ";
//             if (std::cin >> amount && amount > 0) {
//                 validInput = true;
//             } else {
//                cout << "Invalid deposit amount. Please enter a positive value.\n";
//                cin.clear();
//                cin.ignore();
//             }
//         } while (!validInput);

//         balance += amount;
//         addTransaction("Deposit", amount);
//        cout << "Deposit successful! New balance: ₹" << balance <<endl;
//     }

//     void withdraw() {
//         double amount;
//         bool validInput = false;

//         do {
//            cout << "Enter amount to withdraw: ";
//             if (std::cin >> amount && amount > 0 && amount <= balance) {
//                 validInput = true;
//             } else {
//                cout << "Invalid withdrawal amount. Please enter a valid value within your balance.\n";
//                cin.clear();
//                cin.ignore();
//             }
//         } while (!validInput);

//         balance -= amount;
//         addTransaction("Withdrawal", amount);
//        cout << "Withdrawal successful! New balance: ₹" << balance <<endl;
//     }

//     void displayTransactionHistory() const {
//        cout << "Transaction history:\n";
//         for (int i = 0; i < transactionCount; ++i) {
//            cout << transactionHistory[i].type << ":₹ " << transactionHistory[i].amount <<endl;
//         }
//     }

// private:
//     void addTransaction(const char* type, double amount) {
//         if (transactionCount < MAX_HISTORY) {
//             transactionHistory[transactionCount++] = Transaction(type, amount);
//         } else {
            
//             for (int i = 1; i < MAX_HISTORY; ++i) {
//                 transactionHistory[i - 1] = transactionHistory[i];
//             }
//             transactionHistory[MAX_HISTORY - 1] = Transaction(type, amount);
//         }
//     }
// };

// int main() {
//     char userAccountNumber[20];
//     double initialBalance;

//    cout << "Enter your account number: ";
//    cin >> userAccountNumber;

//    cout << "Enter initial deposit balance: ";
//     while (!(std::cin >> initialBalance) || initialBalance < 0) {
//        cout << "Invalid initial balance. Please enter a non-negative value: ";
//        cin.clear();
//        cin.ignore();
//     }

//     BankAccount account(userAccountNumber, initialBalance);

//     int choice;

//     do {
//        cout << "\nWelcome. Choose From Below\n";
//        cout << "1. Display balance\n";
//        cout << "2. Deposit\n";
//        cout << "3. Withdraw\n";
//        cout << "4. Display transaction history\n";
//        cout << "5. Exit\n";
//        cout << "Enter your choice: ";

//         while (!(std::cin >> choice) || choice < 1 || choice > 5) {
//            cout << "Invalid choice. Please enter a number between 1 and 5: ";
//            cin.clear();
//            cin.ignore();
//         }

//         switch (choice) {
//             case 1:
//                 account.displayBalance();
//                 break;
//             case 2:
//                 account.deposit();
//                 break;
//             case 3:
//                 account.withdraw();
//                 break;
//             case 4:
//                 account.displayTransactionHistory();
//                 break;
//             case 5:
//                cout << "Exited\n";
//                 break;
//             default:
//                cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 5);

//     return 0;
// }

// another code

// #include <iostream>
// #include <string>

// using namespace std;


// struct BankAccount {
//     double balance;
//     string transactionHistory;
// };


// void displayBalance(const BankAccount& account) {
//     cout << "Your Account Balance: $" << account.balance << "\n";
// }


// void makeDeposit(BankAccount& account, double amount) {
//     if (amount > 0) {
//         account.balance += amount;
//         account.transactionHistory += "Deposit: $" + to_string(amount) + "\n";
//         cout << "Deposit successful! New balance: $" << account.balance << "\n";
//     } else {
//         cout << "Invalid amount. Deposit must be greater than zero.\n";
//     }
// }


// void makeWithdrawal(BankAccount& account, double amount) {
//     if (amount > 0 && amount <= account.balance) {
//         account.balance -= amount;
//         account.transactionHistory += "Withdrawal: $" + to_string(amount) + "\n";
//         cout << "Withdrawal successful! New balance: $" << account.balance << "\n";
//     } else {
//         cout << "Invalid amount. Withdrawal must not exceed the current balance.\n";
//     }
// }


// void displayTransactionHistory(const BankAccount& account) {
//     cout << "Transaction History:\n" << account.transactionHistory;
// }

// int main() {
   
//     BankAccount account ;

//     int choice;
//     double amount;

//     do {
        
//         cout << "\nWelcome to Your Bank!\n";
//         cout << "1. Display Account Balance\n";
//         cout << "2. Make a Deposit\n";
//         cout << "3. Make a Withdrawal\n";
//         cout << "4. Display Transaction History\n";
//         cout << "5. Exit\n";
//         cout << "\nEnter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 displayBalance(account);
//                 break;
//             case 2:
//                 cout << "Enter the deposit amount: ";
//                 cin >> amount;
//                 makeDeposit(account, amount);
//                 break;
//             case 3:
//                 cout << "Enter the withdrawal amount: ";
//                 cin >> amount;
//                 makeWithdrawal(account, amount);
//                 break;
//             case 4:
//                 displayTransactionHistory(account);
//                 break;
//             case 5:
//                 cout << "Thank you for using Your Bank!\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 5);

//     return 0;
// }



