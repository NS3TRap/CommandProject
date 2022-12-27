#ifndef OTHER_H
#define OTHER_H
#include "clients.h"
#include "expenses.h"
#include "orders.h"

using namespace std;

class AnnualReport
{
private:
    ListOfOrders* ptrListOfOrders;
    ExpensesRecord* ptrExpenseRecord;
    float income, expense;
public:
    AnnualReport(ListOfOrders* ptrLOO, ExpensesRecord* ptrER): ptrListOfOrders(ptrLOO), ptrExpenseRecord(ptrER) {}
    void display();
};

class UserInterfaceScreen
{
private:
    ListOfClients* ptrClientsList;
    ClientEntryScreen* ptrCES;
    ExpenseEntryScreen* ptrEES;
    ExpensesRecord* ptrExpensesRecord;
    ListOfOrders* ptrListOfOrders;
    OrderInteractionScreen* ptrOIS;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterfaceScreen();
    ~UserInterfaceScreen();
    void interact();
};
#endif // OTHER_H
