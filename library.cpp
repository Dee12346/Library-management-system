#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    int bookID;
    string title;
    string author;
    string publisher;
    int year;
    int copies;

    Book(int id, string t, string a, string p, int y, int c)
        : bookID(id), title(t), author(a), publisher(p), year(y), copies(c) {}

    void displayBookInfo() {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year: " << year << endl;
        cout << "Copies: " << copies << endl;
    }

    void updateCopies(int newCopies) {
        copies = newCopies;
    }
};

class User {
public:
    int userID;
    string name;
    string email;
    string address;

    User(int id, string n, string e, string a)
        : userID(id), name(n), email(e), address(a) {}

    void displayUserInfo() {
        cout << "User ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }

    void updateUserInfo(string newName, string newEmail, string newAddress) {
        name = newName;
        email = newEmail;
        address = newAddress;
    }
};

class Transaction {
public:
    int transactionID;
    int userID;
    int bookID;
    string issueDate;
    string returnDate;
    string status;

    Transaction(int tid, int uid, int bid, string issue, string ret, string s)
        : transactionID(tid), userID(uid), bookID(bid), issueDate(issue), returnDate(ret), status(s) {}

    void displayTransactionInfo() {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "User ID: " << userID << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Issue Date: " << issueDate << endl;
        cout << "Return Date: " << returnDate << endl;
        cout << "Status: " << status << endl;
    }
};

void displayMenu() {
    cout << "Library Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Register User" << endl;
    cout << "3. Borrow Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Display Books" << endl;
    cout << "6. Display Users" << endl;
    cout << "7. Display Transactions" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<Book> books;
    vector<User> users;
    vector<Transaction> transactions;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                int id, year, copies;
                string title, author, publisher;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Publisher: ";
                getline(cin, publisher);
                cout << "Enter Year: ";
                cin >> year;
                cout << "Enter Copies: ";
                cin >> copies;
                books.push_back(Book(id, title, author, publisher, year, copies));
                break;
            }
            case 2: {
                int id;
                string name, email, address;
                cout << "Enter User ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Address: ";
                getline(cin, address);
                users.push_back(User(id, name, email, address));
                break;
            }
            case 3: {
                int tid, uid, bid;
                string issueDate, returnDate;
                cout << "Enter Transaction ID: ";
                cin >> tid;
                cout << "Enter User ID: ";
                cin >> uid;
                cout << "Enter Book ID: ";
                cin >> bid;
                cout << "Enter Issue Date: ";
                cin >> issueDate;
                cout << "Enter Return Date: ";
                cin >> returnDate;
                transactions.push_back(Transaction(tid, uid, bid, issueDate, returnDate, "Borrowed"));
                break;
            }
            case 4: {
                int tid;
                cout << "Enter Transaction ID: ";
                cin >> tid;
                for (auto &trans : transactions) {
                    if (trans.transactionID == tid) {
                        trans.status = "Returned";
                        break;
                    }
                }
                break;
            }
            case 5: {
                for (auto &book : books) {
                    book.displayBookInfo();
                }
                break;
            }
            case 6: {
                for (auto &user : users) {
                    user.displayUserInfo();
                }
                break;
            }
            case 7: {
                for (auto &trans : transactions) {
                    trans.displayTransactionInfo();
                }
                break;
            }
            case 8: {
                cout << " Welcome Deepak Exiting the program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    } while (choice != 8);

    return 0;
}
