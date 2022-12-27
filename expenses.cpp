#include "expenses.h"

Expense::~Expense() {
    delete date;
}

Date* Expense::getDate(){
    return date;
}

string Expense::getCategory(){
    return category;
}

string Expense::getPayee(){
    return payee;
}

float Expense::getAmount(){
    return amount;
}

ExpensesRecord::~ExpensesRecord() {
    // удалить указатели на вектор
    while (!vectPtrsExpenses.empty())
    {
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
}

void ExpensesRecord::insertExp(Expense* ptrExpense){
    vectPtrsExpenses.push_back(ptrExpense);
}
