#include "other.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

UserInterfaceScreen::UserInterfaceScreen(){
    ptrClientsList = new ListOfClients;
    ptrListOfOrders = new ListOfOrders;
    ptrExpensesRecord = new ExpensesRecord;
}

UserInterfaceScreen::~UserInterfaceScreen(){
    delete ptrClientsList;
    delete ptrListOfOrders;
    delete ptrExpensesRecord;
}

void UserInterfaceScreen::interact(){
    while (true) {
        cout << "Enter the required menu item:\ni - Data input;\no - Data output\np - Report Output;\nq - Exit" << endl;
        ch = getch();
        if(ch == 'i'){
            system("cls");
            cout << "Enter the required menu item:\nc - Add client;\no - Operations with orders;\ne - Add an expense entry;\nq - Back;\n";
            ch = getch();
            switch (ch) {
            case 'c':
                ptrCES = new ClientEntryScreen(ptrClientsList);
                ptrCES->addNewClient();
                delete ptrCES;
                break;
            case 'o':
                ptrOIS = new OrderInteractionScreen(ptrListOfOrders,ptrClientsList);
                cout << "Enter the required menu item:\na - Add order;\nc - Change order status;\nAny key- Back;\n";
                ch = getch();
                if(ch == 'a'){
                    ptrOIS->addNewOrder();
                }else if(ch == 'c'){
                    ptrOIS->changeOrder();
                }
                //delete ptrOIS;
                break;
            case 'e':
                ptrEES = new ExpenseEntryScreen(ptrExpensesRecord);
                ptrEES->addNewExpenses();
                delete ptrEES;
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
        else if(ch == 'o'){
            system("cls");
            cout << "Enter the required menu item:\nc - Display a list of clients;\n"<<
                    "o - Display a list of orders;\ne - Output list of expenses;\nq - Back;\n";
            ch = getch();
            switch (ch) {
            case 'c':
                ptrClientsList->getListClients();
                system("pause");
                break;
            case 'o':
                ptrListOfOrders->display();
                system("pause");
                break;
            case 'e':
                ptrExpensesRecord->getExpensesRecord();
                system("pause");
                break;
            case 'q':
                break;
            default:
                system("cls");
                cout << "Unknown operation" << endl;
                system("pause");
                break;
            }
        }else if(ch == 'p'){
            ptrAnnualReport = new AnnualReport(ptrListOfOrders,ptrExpensesRecord);
            ptrAnnualReport->display();
            system("pause");
            delete ptrAnnualReport;
        }else if(ch == 'q'){
            break;
        }else {
            cout << "Unknown operation. Try again!";
            system("pause");
        }
        system("cls");
    }
}

void AnnualReport::display()
{
    system("cls");
    cout << "Annual Report\n--------------\n" << endl;
    cout << "Income\n" << endl;
    cout << "\tIncome from orders (services):\t\t";
    income = ptrListOfOrders->getSumOrders();
    cout << income << endl;
    cout << "Expenses\n" << endl;
    expense = ptrExpenseRecord->displaySummary();
    cout << "Total expenses:\t\t";
    cout << expense << endl;
    // вычисляем прибыльность
    cout << "\nBalance:\t\t\t" << (income - expense) << endl;
}
