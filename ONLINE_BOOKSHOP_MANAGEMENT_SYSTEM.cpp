#include<bits/stdc++.h>
#include"program.cpp"
using namespace std;

void admin();
void user();
void admin_control_system();
void user_control_system();

class OnlineBookShop {
public :
    virtual void login() = 0;
    virtual void logout() = 0;
    virtual void registration() {
        cout << "\n~~~~~~~~~~REGISTRATION COMPLETED~~~~~~~~~~~";
    }
    virtual void forgotpass() {
        cout << "\n~~~~~~~~~~PASSWORD IS RECOVERED~~~~~~~~~~";
    }
    virtual void updatepass() {
        cout << "\n~~~~~~~~~~PASSWORD IS UPDATED~~~~~~~~~~";
    }
};


class Book {
protected :
    int copy;
    string id;
    string name;
    string author;
    string publication;
    string category;
    string ISBN;
    map<string, float> mp;

public :
    Book () {
        copy = 0;
    }
    void addBook();
    void deleteBook();
    void updateBook();
    bool checkAvailability();
    void showBook();
    void bookSearch ();
    float getprice(string, string);
};

float Book :: getprice(string b_id, string type) {
    ifstream fin;
    fin.open("bookIn.txt", ios :: in);
    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    }
    else {
        fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
        mp.clear();
        for (int i = 0; i < 3; i++) {
            string type;
            float price;
            fin >> type >> price;
            mp.insert({type, price});
        }

        while(!fin.eof()) {
            if (id == b_id) {
                for (auto it : mp) {
                    if (it.first == type) {
                        fin.close();
                        return it.second;
                    }
                }
            }
            mp.clear();
            fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
            for (int i = 0; i < 3; i++) {
                string type;
                float price;
                fin >> type >> price;
                mp.insert({type, price});
                }
            }
            fin.close();
    }
    return 0.0;
}

void Book::addBook() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADD BOOK MENU             ";
    cout<<"\n======================================================================\n\n";

    cout << "BOOK ID : ";
    cin >> id;
    cout << "ENTER BOOK NAME : ";
    cin >> name;
    cout << "ENTER AUTHOR NAME: ";
    cin >> author;
    cout << "ENTER PUBLICATION NAME : ";
    cin >> publication;
    cout << "ENTER CATEGORY NAME : ";
    cin >> category;
    cout << "ENTER ISBN : ";
    cin >> ISBN;
    cout << "ENTER BOOK COPIES : ";
    cin >> copy;

    cout<< "SET BOOK PRICE : \n";
    mp.clear();
    for (int i = 0; i < 3; i++) {
        string type;
        float price;
        cout << "ENTER TYPE : ";
        cin >> type;
        cout << "ENTER PRICE : ";
        cin >> price;
        mp.insert({type, price});
    }

    ofstream fout;
    fout.open("bookIn.txt", ios :: app);
    if (!fout) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    }
    else {
        fout << id << " " << name << " " << author << " " << publication << " " 
        << category << " " << ISBN << " " << copy << endl;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            fout << it->first << " " << it->second << endl;
        }
        cout << "\n~~~~~~~~~~BOOK ADDED SUCCESSFULLY~~~~~~~~~~\n";
    }
    system("pause");
    fout.close();
}

void Book :: showBook() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       SHOW BOOK MENU             ";
    cout<<"\n======================================================================\n";

    ifstream fin;
    fin.open("bookIn.txt", ios :: in);
    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    }
    else {
        fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
        mp.clear();
        for (int i = 0; i < 3; i++) {
            string type;
            float price;
            fin >> type >> price;
            mp.insert({type, price});
        }

        while(!fin.eof()) {
            cout << "\nBOOK ID IS : " << id;
            cout << "\nBOOK NAME IS : " << name;
            cout << "\nAUTHOR NAME IS : " << author;
            cout << "\nPUBLICATION NAME IS : " << publication;
            cout << "\nCATEGORY IS : " << category;
            cout << "\nISBN IS : " << ISBN;
            cout << "\nPRICE FOR THIS BOOK\n";
            for(auto it = mp.begin(); it != mp.end(); it++) {
                cout << setw(8) << it->first << setw(8) << it->second << endl;
            }

            mp.clear();
            fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
            for (int i = 0; i < 3; i++) {
                string type;
                float price;
                fin >> type >> price;
                mp.insert({type, price});
                }
            cout << "\n\n";
            }
            system("pause");
            fin.close();
    }
} 

void Book :: updateBook() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       UPDATE BOOK MENU             ";
    cout<<"\n======================================================================\n\n";

    string b_id, b_name, newId, newName, newAuthor, newPub, newIsbn, newCat;
    int cnt = 0, newCopy;
    map<string, float> newPrice;

    fstream file;
    file.open("bookIn.txt", ios::in | ios::out);
    ofstream fout;
    fout.open("temp.txt", ios::app);

    if (!file) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    } else {
        cout << "ENTER BOOK ID : ";
        cin >> b_id;
        cout << "ENTER BOOK NAME : ";
        cin >> b_name;

        file >> id >> name >> author >> publication >> category >> ISBN >> copy;
        mp.clear();
        for (int i = 0; i < 3; i++) {
            string type;
            float price;
            file >> type >> price;
            mp.insert({type, price});
        }

        while (!file.eof()) {
            if (b_id == id || b_name == name) {
                cout << "\n*******************************************************\n";
                cout << "ENTER NEW BOOK ID : ";
                cin >> newId;
                cout << "ENTER NEW BOOK NAME : ";
                cin >> newName;
                cout << "ENTER NEW AUTHOR NAME : ";
                cin >> newAuthor;
                cout << "ENTER NEW PUBLICATION NAME : ";
                cin >> newPub;
                cout << "ENTER NEW CATEGORY NAME : ";
                cin >> newCat;
                cout << "ENTER NEW ISBN : ";
                cin >> newIsbn;
                cout << "ENTER NEW BOOK COPIES : ";
                cin >> newCopy;

                cout << "SET BOOK NEW PRICE : \n";
                newPrice.clear();

                for (int i = 0; i < 3; i++) {
                    string type;
                    float price;
                    cout << "ENTER TYPE : ";
                    cin >> type;
                    cout << "ENTER TYPE : ";
                    cin >> price;
                    newPrice.insert({type, price});
                }
                fout << newId << " " << newName << " " << newAuthor << " " << newPub << " "
                << newCat << " " << newIsbn << " " << newCopy << endl;

                for (auto it = newPrice.begin(); it != newPrice.end(); it++) {
                    fout << it->first << " " << it->second << endl;
                }
                cnt++;
            } 
            else {
                fout << id << " " << name << " " << author << " " << publication << " "
                     << category << " " << ISBN << " " << copy << endl;

                for (auto it = mp.begin(); it != mp.end(); it++) {
                    fout << it->first << " " << it->second << endl;
                }
            }

            file >> id >> name >> author >> publication >> category >> ISBN >> copy;
            mp.clear(); 
            for (int i = 0; i < 3; i++) {
                string type;
                float price;
                file >> type >> price;
                mp.insert({type, price});
            }
        }
        if (cnt == 0) {
            cout << "\n..........BOOK ID NOT FOUND..........";
        }
        else {
            cout << "\n~~~~~~~~~~~BOOK UPDATED SUCCESSFULLY~~~~~~~~~";
        }
    }
    cout << endl;
    system("pause");

    file.close();
    fout.close();
    remove("bookIn.txt");
    rename("temp.txt", "bookIn.txt");
}

void Book :: deleteBook() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       DELETE BOOK MENU             ";
    cout<<"\n======================================================================\n";
    string b_id, b_name;
    int cnt = 0;

    fstream file;
    file.open("bookIn.txt", ios::in | ios::out);
    ofstream fout;
    fout.open("temp.txt", ios::app);

    if (!file) {
        cout << "\n..........ERROR IN FILE OPENING.........." << endl;
    } else {
        cout << "ENTER BOOK ID : ";
        cin >> b_id;
        cout << "ENTER BOOK NAME : ";
        cin >> b_name;

        file >> id >> name >> author >> publication >> category >> ISBN >> copy;
        mp.clear();
        for (int i = 0; i < 3; i++) {
            string type;
            float price;
            file >> type >> price;
            mp.insert({type, price});
        }

        while (!file.eof()) {
            if (b_id == id || b_name == name) {
                cnt++;
            } else {
                fout << id << " " << name << " " << author << " " << publication << " "
                     << category << " " << ISBN << " " << copy << endl;

                for (auto it = mp.begin(); it != mp.end(); it++) {
                    fout << it->first << " " << it->second << endl;
                }
            }

            file >> id >> name >> author >> publication >> category >> ISBN >> copy;
            mp.clear(); 
            for (int i = 0; i < 3; i++) {
                string type;
                float price;
                file >> type >> price;
                mp.insert({type, price});
            }
        }
        if (cnt == 0) {
            cout << "\n..........BOOK ID OR NAME NOT FOUND..........";
        }
        else {
            cout << "\n~~~~~~~~~~BOOK IS DELETED SUCCESSFULLY~~~~~~~~~~";
        }
    }
    cout << endl;
    system("pause");

    file.close();
    fout.close();
    remove("bookIn.txt");
    rename("temp.txt", "bookIn.txt");
}

bool Book :: checkAvailability() {
    string b_id, b_name;
    int cnt = 0, cpy;

    ifstream fin;
    fin.open("bookIn.txt", ios :: in);

    if (!fin) {
        cout << "\n...........ERROR IN FILE OPENING..........";
    } else {
        cout << "BOOK ID : ";
        cin >> b_id;
        cout << "BOOK NAME : ";
        cin >> b_name;

        fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
        mp.clear();
        for (int i = 0; i < 3; i++) {
            string type;
            float price;
            fin >> type >> price;
            mp.insert({type, price});
        }

        while (!fin.eof()) {
            if (b_id == id || b_name == name) {
                cnt++;
                cout << "ENTER HOW MANY COPIES YOU WANT ?? ";
                cin >> cpy;
                if (copy >= cpy) {
                    cout << "\n~~~~~~~~~~IN STOCK~~~~~~~~~~";
                    return true;
                }
                else {
                    return false;
                }
                break;
            } else {
                fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
                mp.clear(); 
                for (int i = 0; i < 3; i++) {
                    string type;
                    float price;
                    fin >> type >> price;
                    mp.insert({type, price});
                }
            }
        }
        if (cnt == 0) {
            cout << "\n..........BOOK ID OR NAME NOT FOUND..........";
            return false;
        }
        fin.close();
    }
    return false;
}

void Book :: bookSearch () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       BOOK SEARCH MENU             ";
    cout<<"\n======================================================================\n";

    string b_id, b_name;
    int cnt = 0;
    ifstream fin;
    fin.open("bookIn.txt", ios :: in);
    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    } else {
        cout << "BOOK ID : ";
        cin >> b_id;
        cout << "BOOK NAME : ";
        cin >> b_name;
        cout << "\n\n************************************************************";

        fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
        mp.clear();
        for (int i = 0; i < 3; i++) {
            string type;
            float price;
            fin >> type >> price;
            mp.insert({type, price});
        }
        while (!fin.eof()) {
            if (b_id == id || b_name == name) {
                cnt++;
                cout << "\nBOOK ID IS : " << id;
                cout << "\nBOOK NAME IS : " << name;
                cout << "\nAUTHOR NAME IS : " << author;
                cout << "\nPUBLICATION NAME IS : " << publication;
                cout << "\nCATEGORY IS : " << category;
                cout << "\nISBN IS : " << ISBN;
                cout << "\nPRICE FOR THIS BOOK\n";
                for(auto it = mp.begin(); it != mp.end(); it++) {
                    cout << setw(8) << it->first << setw(8) << it->second << endl;
                }
                break;
            } else {
                fin >> id >> name >> author >> publication >> category >> ISBN >> copy;
                mp.clear(); 
                for (int i = 0; i < 3; i++) {
                    string type;
                    float price;
                    fin >> type >> price;
                    mp.insert({type, price});
                }
            }
        }
        if (cnt == 0) {
            cout << "\n..........BOOK ID OR NAME NOT FOUND..........";
        }
        system("pause");
        fin.close();
    }
}


class DiscountPolicy {
protected:
    static float discount;
public :
    float aplyDiscount(float pr) {
        return  (pr - pr * discount);
    }
};
float DiscountPolicy :: discount = 0.15;

class DeleveryMethod {
protected :
    static double fast_charge;
    static double normal_charge;
    DeliveryTime option;
};

double DeleveryMethod :: fast_charge = 100;
double DeleveryMethod :: normal_charge = 50;


class Order : public DiscountPolicy, public DeleveryMethod, public Book {
private :
    string bookId;
    string user_id;
    string order_date;
    string u_phone;
    string u_addres;
    float total;
    string book;
    string deltime;
    string delopt;
public :
    void placeOrder();
    void cancelOrder();
    void orderInfo();
    void seeOrderlist();
};

void Order::placeOrder() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       BOOK ORDER MENU             ";
    cout<<"\n======================================================================\n";

    ofstream fout;
    fout.open("orderlist.txt", ios::app);

    bool availity;
    availity = checkAvailability();
    if (availity) {
        cout << "\n\nENTER YOUR MAIL : ";
        cin >> user_id;
        cout << "BOOK ID : ";
        cin >> bookId;
        cout << "ENTER ORDERING DATE : ";
        cin >> order_date;
        cout << "ENTER YOUR PHONE NUMBER : ";
        cin >> u_phone;
        cout << "ENTER YOUR ADDRESS : ";
        cin >> u_addres;

        string book;
        cout << "ENTER WHICH TYPE OF WOULD YOU LIKE TO BUY (PDF / OLD_BOOK / NEW_BOOK) ?? : ";
        cin >> book;
        
        float price, newPrice;
        price = getprice(bookId, book);
        newPrice = aplyDiscount(price);
        cout << "\nAFTER APPLYING 15% DISCOUNT PRICE IS : " << newPrice;

        cout << "\nENTER DELIVERY OPTION";
        cout << "\n[1] FAST_DELIVERY (100TK).";
        cout << "\n[2] NORMAL_DELIVERY (50TK).\n";
        cout << "YOUR CHOICE : " ;
        cin >> deltime;

        if (deltime == "FAST_DELIVERY") {
            option = Fast_Delivery;
            total = newPrice + fast_charge;
        } else {
            option = Normal_Delivery;
            total = newPrice + normal_charge;
        }

        cout << "ENTER PAYMENT METHOD (CASH_ON_DELIVERY / ONLINE_PAYMENT) : ";
        cin >> delopt;

        if (!fout) {
            cout << "\n..........ERROR IN FILE OPENING..........";
        } else {
            fout << user_id << " " << bookId << " " << order_date << " "<< u_phone << " " 
            << u_addres << " " << book << " " << deltime << " " << delopt << " " << total << endl;

            cout << "\n~~~~~~~~~~ORDER COMPLETED~~~~~~~~~~";
        }
    } else {
        cout << "\n**********OUT OF STOCK**********";
    }
    cout<< "\n";
    system("pause");
    fout.close();
}

void Order::cancelOrder() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       BOOK ORDER CANCEL MENU             ";
    cout<<"\n======================================================================\n";

    int cnt = 0;
    string u_id,b_id;
    fstream file;
    file.open("orderlist.txt", ios::in | ios::out);
    ofstream fout;
    fout.open("temp.txt", ios::app);

    if (!file) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    } else {
        cout << "ENTER YOUR MAIL : ";
        cin >> u_id;
        cout << "ENTER BOOK ID : ";
        cin >> b_id;

        file >> user_id >> bookId >> order_date >> u_phone >> u_addres >> book >> deltime >> delopt >> total;
        while (!file.eof()) {
            if (u_id == user_id && b_id == bookId) {
                cnt++;
            } else {
                fout << user_id << " " << bookId << " " << order_date << " "<< u_phone << " " 
                << u_addres << " " << book << " " << deltime << " " << delopt << " " << total << endl;
            }
            file >> user_id >> bookId >> order_date >> u_phone >> u_addres >> book >> deltime >> delopt >> total;
        }
        if (cnt == 0) {
            cout << "\n..........ORDER IS NOT FOUND..........";
        }
        else {
            cout << "\n~~~~~~~~~~ORDER IS CANCELLED SUCCESSFULLY~~~~~~~~~~";
        }
    }
    cout << endl;
    system("pause");

    file.close();
    fout.close();
    remove("orderlist.txt");
    rename("temp.txt", "orderlist.txt");
}

void Order :: orderInfo() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       CHECK ORDER INFO MENU             ";
    cout<<"\n======================================================================\n";

    int cnt = 0;
    string u_id;
    ifstream fin;
    fin.open("orderlist.txt", ios::in);

    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    } else {
        cout << "\nENTER YOUR MAIL : ";
        cin >> u_id;

        fin >> user_id >> bookId >> order_date >> u_phone >> u_addres >> book >> deltime >> delopt >> total;
        while (!fin.eof()) {
            if (u_id == user_id) {
                cnt++;
                cout << "\n USER MAIL : " << user_id;
                cout << "\n BOOK ID : " << bookId;
                cout << "\n ORDERING DATE : " << order_date;
                cout << "\n USER PHONE NUMBER IS : " << u_phone;
                cout << "\n USER ADDRESS IS : " << u_addres;
                cout << "\n TOTAL COST : " << total;
                cout << "\n BOOK FORMAT IS : " << book;
                cout << "\n PAYMENT METHOD IS : " << delopt;
                cout << "\n DELIVERY OPTIOIN : " << deltime;
                break;
            } 

        fin >> user_id >> bookId >> order_date >> u_phone >> u_addres >> book >> deltime >> delopt >> total;
        }
        if (cnt == 0) {
            cout << "\n..........ORDER IS NOT FOUND...........";
        }
    }
    cout << endl;
    system("pause");
    fin.close();
}

void Order :: seeOrderlist() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ORDER INFORMATION MENU             ";
    cout<<"\n======================================================================\n";

    ifstream fin;
    fin.open("orderlist.txt", ios::in);

    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    } else {
        fin >> user_id >> bookId >> order_date >> u_phone >> u_addres >> book >>
        deltime >> delopt >> total;
        while (!fin.eof()) {
            cout << "\n USER MAIL : " << user_id;
            cout << "\n BOOK ID : " << bookId;
            cout << "\n ORDERING DATE : " << order_date;
            cout << "\n USER PHONE NUMBER IS : " << u_phone;
            cout << "\n USER ADDRESS IS : " << u_addres;
            cout << "\n TOTAL COST : " << total;
            cout << "\n BOOK FORMAT IS : " << book;
            cout << "\n PAYMENT METHOD IS : " << delopt;
            cout << "\n DELIVERY OPTIOIN : " << deltime;

            fin >> user_id >> bookId >> order_date >> u_phone >> u_addres >> book >> deltime >>
            delopt >> total;
            cout << "\n\n";
        }
    }
    cout << endl;
    system("pause");
    fin.close();
}



class userReview {
private:
    int rating;
    string text;
public :
    void review_rating();
    void view_review();
};

void userReview :: review_rating() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER REVIEW AND RATING MENU             ";
    cout<<"\n======================================================================\n";
    string userid;
    cout << "\nENTER YOUR MAIL : ";
    cin >> userid;

    cout << "\nHOW MUCH YOU SATISFIED WITH OUR SYSTEM? PLEASE RATE THIS SYSTEM OUT OF 5 STAR (*) : ";
    cin >> rating;

    cout << "\nMAKE SOME COMMENT ABOUT THIS SYSTEM : ";
    cin.ignore();
    getline(cin, text);

    ofstream fout;
    fout.open("reviewIn.txt", ios :: app);

    if(!fout) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    } 
    else {
        fout << userid << " " << rating << " " << text << endl;
        cout << "\n~~~~~~~~~~THANK YOUR FOR YOUR REVIEW~~~~~~~~~~\n";
    }
    system("pause");
    fout.close();
}

void userReview :: view_review() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER REVIEW AND RATING             ";
    cout<<"\n======================================================================\n";
    ifstream fin;
    fin.open("reviewIn.txt", ios :: in);
    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
        return;
    }
    string id;

    while (fin >> id && fin >> rating) {
        fin.ignore(); 
        getline(fin, text);
        cout << "\n  USER MAIL : " << id;
        cout << "\n  RATING : " << rating << ",   COMMENT : " << text << endl;
    }
    system("pause");
    fin.close();
}



class Admin : public OnlineBookShop {
private :
    string username;
    string password;
public :
    void login();
    void registration();
    void logout();
    void updatepass();
};

void Admin :: registration () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADMIN REGISTRATION MENU             ";
    cout<<"\n======================================================================\n";
    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> username;
    while(1) {
       cout << "\nENTER PASSWORD (AT LEAST LENGTH OF 8 CHARACTER) : ";
       cin >> password;
       if (password.size() >= 8) {
        break;
       } 
       else {
        cout << "\n..........TOO SHORT PASSWORD!! PLEASE TRY AGAIN..........";
       }
    }
    ofstream fin;
    fin.open("adminIn.txt", ios::out);
    if (!fin) {
        cout << "\n...........ERROR IN FILE OPENING..........";
    }
    else {
        fin << username << " " << password << endl;
        cout << "\n~~~~~~~~~~REGISTRATION COMPLETED SUCCESSFULLY~~~~~~~~~~"; 

    }
    cout << "\n";
    system("pause");
    fin.close();
    loadProgram ad;
    ad.adminMenu();
}

void Admin :: login () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADMIN LOG-IN MENU             ";
    cout<<"\n======================================================================\n";

    string name, pass;
    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> name;
    cout << "\nENTER PASSWORD : ";
    cin >> pass;

    ifstream fout;
    fout.open("adminIn.txt", ios :: in);
    if (!fout) {
        cout << "\n...........ERROR IN FILE OPENING..........";
    }
    else {
        fout >> username >> password;
    }
    if (username == name && password == pass) {
        cout << "\n~~~~~~~~~~~LOG IN SUCCESSFULLY~~~~~~~~~~\n";
        system("pause");
        admin_control_system();
    }
    else {
        cout << "\n...........WRONG USERNAME OR PASSWORD!! PLEASE TRY AGAIN..........";
        cout << "\n";
        system("pause");
        fout.close();
        loadProgram ad;
        ad.adminMenu();
    }
    fout.close();
}

void Admin :: updatepass () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADMIN UPDATE PASSWORD MENU             ";
    cout<<"\n======================================================================\n";

    string name, pass, newName, newPass;
    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> name;
    cout << "\nENTER PASSWORD : ";
    cin >> pass;

    fstream finout;
    finout.open("adminIn.txt", ios :: out | ios :: in);
    if (!finout) {
        cout << "\n...........ERROR IN FILE OPENING..........";
    }
    else {
        finout >> username >> password;
    }
    ofstream fin;
    fin.open("temp.txt", ios :: app);
    if (username == name || password == pass) {
        cout << "\n~~~~~~~~~INFORMATION MATCHED~~~~~~~~~~~\n";
        
        cout << "\nENTER YOUR USERNAME (EMAIL) : ";
        cin >> newName;
        while(1) {
        cout << "\nENTER NEW PASSWORD (AT LEAST LENGTH OF 8 CHARACTER) : " ;
        cin >> newPass;
        if (newPass.size() >= 8) {
            break;
        } 
        else {
            cout << "\n..........TOO SHORT PASSWORD!! PLEASE TRY AGAIN..........";
        }
    }
        fin << newName << " " << newPass << endl;
        cout << "\n~~~~~~~~~~~SUCCESSFULLY UPDATED PASSWORD~~~~~~~~~~~";
    }
    else {
        cout << "\n..........WRONG USERNAME OR PASSWORD!! PLEASE TRY AGAIN..........";
    }
    cout << "\n";
    system("pause");
    finout.close();
    fin.close();
    remove("adminIn.txt");
    rename("temp.txt", "adminIn.txt");

    loadProgram ad;
    ad.adminMenu();
}

void Admin :: logout () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADMIN LOG-OUT MENU             ";
    cout<<"\n======================================================================\n";

    string name, pass;
    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> name;
    cout << "\nENTER PASSWORD : ";
    cin >> pass;

    ifstream fout;
    fout.open("adminIn.txt", ios :: in);
    if (!fout) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    }
    else {
        fout >> username >> password;
    }

    if (name == username && pass == password) {
        cout << "\n~~~~~~~~~~LOG OUT SUCCESSFULLY~~~~~~~~~~~";
        exit(1);
    }
    else {
        cout << "\n..........WRONG USERNAME OR PASSWORD!! PLEASE TRY AGAIN..........";
    }
    cout << "\n";
    system("pause");
    fout.close();
    loadProgram ad;
    ad.adminMenu();
}

void admin() {
    Admin adm;
    loadProgram lp;
    int choice;
    while (true) {
        lp.adminMenu();
        cout << "\n  ENTER YOUR CHOICE : ";
        cin >> choice;
        switch(choice) {
            case 1 :
                adm.login();
                break;
            case 2 :
                adm.registration();
                break;
            case 3 :
                adm.logout();
                break;
            case 4 :
                adm.updatepass();
                break;
            case 5 :
                return;
            default : 
                cout << "\n..........YOU HAVE ENTERED A WRONG NUMBER.........." << endl;
                break;
        }
    }
}

void admin_control_system()
{
    int choice;
    char x;
    loadProgram ad;
    Order od;
    userReview rv;
 
    while (1) {
        ad.admin_functionality();
        cout << "\nENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice) {
        case 1:
            do {
                cin.ignore();
                od.addBook();
                cout << "\n\nWant to add"
                     << " another book? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;
        case 2:
            od.showBook();
            break;
        case 3:
            od.updateBook();
            break;
        case 4:
            od.deleteBook();
            break;
        case 5:
            od.seeOrderlist();
            break;
        case 6 :
            rv.view_review();
            break;
        case 7:
            return;
        default:
            cout << "\n~~~~~~~~~~SORRY!! INVALID INPUT~~~~~~~~~~~\n";
        }
    }
}


class User : public OnlineBookShop {
private :
    string u_username;
    string u_password;
public :
    void login();
    void registration();
    void logout();
    void forgotpass();
};

void User :: registration () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER REGISTRATION MENU             ";
    cout<<"\n======================================================================\n";

    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> u_username;
    while(1) {
       cout << "\nENTER PASSWORD (AT LEAST LENGTH OF 8 CHARACTER) : ";
       cin >> u_password;
       if (u_password.size() >= 8) {
        break;
       } 
       else {
        cout << "\n..........TOO SHORT PASSWORD!! PLEASE TRY AGAIN..........";
       }
    }
    ofstream fin;
    fin.open("userIn.txt", ios :: app);
    if (!fin) {
        cout << "\n..........ERROR IN FILE OPENING..........";
    }
    else {
        fin << u_username << " " << u_password << endl;
        cout << "\n~~~~~~~~~~REGISTRATION COMPLETED SUCCESSFULLY~~~~~~~~~~~";
    } 
    fin.close();
    cout << "\n";
    system("pause");
    loadProgram us;
    us.userMenu();
}

void User :: login () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER LOG-IN MENU             ";
    cout<<"\n======================================================================\n";

    string name, pass;
    int cnt = 0;
    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> name;
    cout << "\nENTER PASSWORD : ";
    cin >> pass;

    ifstream fout;
    fout.open("userIn.txt", ios :: in);
    if (!fout) {
        cout << "\n..........ERROR IN FILE OPENING...........";
    }
    else {
        fout >> u_username >> u_password;
        while (!fout.eof()) {
        if (u_username == name && u_password == pass) {
            cout << "\n~~~~~~~~~~LOG IN SUCCESSFULLY~~~~~~~~~~\n";
            system("pause");
            fout.close();
            cnt++;
            user_control_system();
            break;
        }
        else {
            fout >> u_username >> u_password;
        }
        }
    }
    if (cnt == 0) {
        cout << "\n...........WRONG USERNAME OR PASSWORD!! TRY AGAIN CAREFULLY..........\n";
        system("pause");
        fout.close();
        loadProgram us;
        us.userMenu();
    }
}

void User :: forgotpass () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER RECOVERING PASSWORD MENU             ";
    cout<<"\n======================================================================\n";

    cout << "\n~~~~~FORGOT PASSWORD?? NO WORRIES~~~~~~";
    int cnt = 0;
    string name;
    cout << "\n\nENTER USERNAME (EMAIL) : ";
    cin >> name;

    ifstream fout;
    fout.open("userIn.txt", ios :: in);
    if (!fout) {
        cout << "\n...........ERROR IN FILE OPENING.........." << endl;
    }
    else {
        fout >> u_username >> u_password;
        while (!fout.eof()) {
            if (name == u_username) {
            cout << "\n**********YOUR PASSWORD IS : " << u_password;
            cnt++;
            break;
            }
            else {
                fout >> u_username >> u_password;
            }
        }
    }
    if(cnt == 0) {
        cout << "\n............WRONG USERNAME!! PLEASE TRY AGAIN CAREFULLY..........";
    }
    cout << "\n";
    system("pause");
    fout.close();
    loadProgram us;
    us.userMenu();
}

void User :: logout () {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER LOG-OUT MENU             ";
    cout<<"\n======================================================================\n";

    string name, pass;
    int cnt = 0;
    cout << "\nENTER USERNAME (EMAIL) : ";
    cin >> name;
    cout << "\nENTER PASSWORD : ";
    cin >> pass;

    ifstream fout;
    fout.open("userIn.txt", ios :: in);
    if (!fout) {
        cout << "\n...........ERROR IN FILE OPENING...........";
    }
    else {
        fout >> u_username >> u_password;
        while(!fout.eof()) {
            if (name == u_username && pass == u_password) {
            cout << "\n~~~~~~~~~~LOG OUT SUCCESSFULLY~~~~~~~~~~";
            cnt++;
            exit(0);
            }
            else {
                fout >> u_username >> u_password;
            }
        }
    }

    if (cnt == 0) {
        cout << "\n...........WRONG USERNAME OR PASSWORD...........";
    }
    cout << "\n";
    system("pause");
    fout.close();
    loadProgram us;
    us.userMenu();
}

void user() {
    loadProgram pd;
    int choice;
    OnlineBookShop *ptr;
    ptr = new User;
    while (true) {
        pd.userMenu();
        cout << "\n  ENTER YOUR CHOICE : ";
        cin >> choice;
        switch(choice) {
            case 1:
                ptr->login();
                break;
            case 2:
                ptr->registration();
                break;
            case 3:
                ptr->logout();
                break;
            case 4:
                ptr->forgotpass();
                break;
            case 5:
                return;
            default : 
                cout << "\n..........YOU HAVE ENTERED A WRONG NUMBER..........";
                break;
        }
    }
}

void user_control_system()
{
    int choice;
    char x;
    Order ed;
    loadProgram us;
    userReview urv;
    while (1) {
        us.user_functionality();
        cout << "\nENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice) {
        case 1: 
            ed.showBook();
            break;
        case 2:
            ed.bookSearch();
            break;
        case 3:
            ed.placeOrder();
            break;
        case 4:
            ed.cancelOrder();
            break;
        case 5:
            ed.orderInfo();
            break;
        case 6:
            urv.review_rating();
            break;
        case 7:
            return;
        default:
            cout << "\n~~~~~~~~~~SORRY!! INVALID INPUT~~~~~~~~~~~\n";
        }
    }
}

int main()
{
    loadProgram ld;
    int ch;
    while (true) {
        ld.mainProgram();
        cout << "\n  ENTER YOUR CHOICE : ";
        cin >> ch;
        switch(ch) {
            case 1:
                admin();
                break;
            case 2:
                user();
                break;
            case 3:
                cout << "\n~~~~~~~~~~SUCCESSFULLY EXIT THE PROGRAM~~~~~~~~~~~";
            exit(0);

            default:
                cout << "\n~~~~~~~~~~SORRY!! INVALID INPUT~~~~~~~~~~~\n";
                system("pause");
        }
    }
    return 0;
}