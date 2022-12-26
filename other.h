#ifndef OTHER_H
#define OTHER_H
#include "clients.h"

using namespace std;

class AnnualReport
{
private:
    //ListOfOrders* ptrListOfOrders;
    //ExpenseRecord* ptrExpenseRecord;
public:
    AnnualReport(/*ListOfOrders* ptrLOO, ExpenseRecord* ptrER*/)/*: ptrListOfOrders(ptrLOO), ptrExpenseRecord(ptrER)*/;
    void display();
};

class UserInterfaceScreen
{
private:
    ListOfClients* ptrClientsList;
    ClientEntryScreen* ptrCES;
    //ExpenseEntryScreen* ptrEES;
    //ListOfOrders* ptrListOfOrders;
    //OrderInteractionScreen ptrOIS;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterfaceScreen() {}
    ~UserInterfaceScreen() {}
    void interact();
};
#endif // OTHER_H
