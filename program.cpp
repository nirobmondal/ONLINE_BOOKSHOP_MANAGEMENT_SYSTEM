#pragma once
#include<bits/stdc++.h>
using namespace std;

time_t ct = time(0);
string ctm = ctime(&ct);

enum DeliveryTime {Fast_Delivery = 1, Normal_Delivery = 2};

class loadProgram {
public :
    void mainProgram() {
    system("cls");
    cout << "\t\t\t   " << ctm ;
    cout<<"\n================================================================================\n";
    cout<<"\t\t       ONLINE BOOKSHOP MANAGEMENT SYSTEM             ";
    cout<<"\n================================================================================\n";
    cout << "\n  [1]  ADMIN.";
    cout << "\n  [2]  USER.";
    cout << "\n  [3]  EXIT THE PROGRAM.";
    cout << "\n\n************************************************************";
    }

    void adminMenu() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADMIN MENU             ";
    cout<<"\n======================================================================\n";
    cout << "\n  [1]   LOG-IN.";
    cout << "\n  [2]   REGISTER.";
    cout << "\n  [3]   LOG-OUT.";
    cout << "\n  [4]   UPDATE PASSWORD.";
    cout << "\n  [5]   RETURN MAIN MENU.";
    cout << "\n\n************************************************************";
    }

    void admin_functionality() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       ADMIN CONTROL PANEL             ";
    cout<<"\n======================================================================\n";
    cout << "\n  [1]   ADD BOOK.";
    cout << "\n  [2]   DISPLAY BOOKS.";
    cout << "\n  [3]   UPDATE BOOK.";
    cout << "\n  [4]   DELETE BOOK.";
    cout << "\n  [5]   SEE ORDER LIST.";
    cout << "\n  [6]   SEE USER REVIEW.";
    cout << "\n  [7]   RETURN TO ADMIN MENU.";
    cout << "\n\n************************************************************";
    }

    void userMenu() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER MENU             ";
    cout<<"\n======================================================================\n";
    cout << "\n  [1]   LOG-IN.";
    cout << "\n  [2]   REGISTER.";
    cout << "\n  [3]   LOG-OUT.";
    cout << "\n  [4]   FORGOT PASSWORD.";
    cout << "\n  [5]   RETURN MAIN MENU.";
    cout << "\n\n************************************************************";
    }

    void user_functionality() {
    system("cls");
    cout << "\t\t   " << ctm ;
    cout<<"\n======================================================================\n";
    cout<<"\t\t       USER CONTROL PANEL             ";
    cout<<"\n======================================================================\n";
    cout << "\n  [1]   SEE ALL BOOKS.";
    cout << "\n  [2]   SEARCH BOOKS.";
    cout << "\n  [3]   PLACE ORDER.";
    cout << "\n  [4]   CANCEL ORDER.";
    cout << "\n  [5]   SEE ORDER INFORMATION.";
    cout << "\n  [6]   GIVE REVIEW.";
    cout << "\n  [7]   RETURN TO USER MENU.";
    cout << "\n\n************************************************************";
    }
};