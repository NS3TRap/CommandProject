#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
using namespace std;

typedef struct date
{
    int day;
    int month;
    int year;
} Date;

class Expense
{
private:
    Date* date;
    string category;
    string payee;
    float amount;
public:
    Expense( Date* d, string categ, string pay, float a) : date(d),category(categ),payee(pay),amount(a) {}
    ~Expense();
    Date* getDate();
    string getCategory();
    string getPayee();
    float getAmount();
};

class ExpensesRecord
{
private:
    vector<Expense*> vectPtrsExpenses;
    vector<Expense*>::iterator iter;
public:
    ~ExpensesRecord();
    void insertExp(Expense*);
    void getExpensesRecord();
    float displaySummary();
};

class ExpenseEntryScreen
{
private:
    ExpensesRecord* ptrExpenseRecord;
    Date* date;
    string category;
    string payee;
    float amount;
public:
    ExpenseEntryScreen(ExpensesRecord* ptrER) : ptrExpenseRecord(ptrER) {}
    void addNewExpenses();
};

#endif // EXPENSES_H
