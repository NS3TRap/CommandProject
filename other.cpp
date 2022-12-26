#include "other.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

UserInterfaceScreen::UserInterfaceScreen(){
    ptrClientsList = new ListOfClients;
    //ptrListOfOrders = new ListOfOrders;
    ptrExpensesRecord = new ExpensesRecord;
}

UserInterfaceScreen::~UserInterfaceScreen(){
    delete ptrClientsList;
    //delete ptrListOfOrders;
    delete ptrExpensesRecord;
}

void UserInterfaceScreen::interact(){
    while (true) {
        cout << "Enter the required menu item:\ni - Data input;\np - Report Output;\nq - Exit" << endl;
        ch = getch();
        if(ch == 'i'){
            system("cls");
            cout << "Enter the required menu item:\nc - Add client;\no - Operations with orders;\ne - Add an expense entry;\nq - Back;\n";
            ch = getch();
            switch (ch) {
            case 'c':
                //ptrCES = new ClientEntryScreen(ptrClientsList);
               // ptrCES->addNewClient();
                //delete ptrCES;
                break;
            case 'o':
                //ptrOIS = new OrderInteractionScreen(ptrListOfOrders);
                cout << "Enter the required menu item:\na - Add order;\nc - Change order status;\nAny key- Back;\n";
                ch = getch();
                if(ch == 'a'){
                    //ptrOIS->addNewOrder();
                }else if(ch == 'c'){
                    //ptrOIS->changeOrder();
                }
                //delete ptrOIS;
                break;
            case 'e':
                //ptrEES = new ExpenseEntryScreen(ptrExpensesRecord);
                //ptrEES->addNewExpenses();
                //delete ptrEES;
                break;
            case 'q':
                break;
            default:
                system("cls");
                cout << "Unknown operation" << endl;
                system("pause");
                break;
            }
        }
        else if(ch == 'p'){

        }else if(ch == 'q'){
            break;
        }else {
            cout << "Unknown operation. Try again!";
            system("pause");
        }
        system("cls");
    }
}
