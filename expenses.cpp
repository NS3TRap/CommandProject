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
