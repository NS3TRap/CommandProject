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

void ExpensesRecord::getExpensesRecord(){
    Date* date;
    system("cls");
    cout << "\nDate\tAddressee\tAmount\tCategory\n"
    << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // В контейнере нет расходов
        cout << "***Расходов нет***\n" << endl;
    else
    {
        iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    { // распечатываем все расходы
         date = (*iter)->getDate();
         cout << date->month << '/' << date->day << '/'<<date->year<<
         '\t' << (*iter)->getPayee() << '\t' << '\t';
         cout << (*iter)->getAmount() << '\t' << (*iter)->getCategory() << endl;
         iter++;
    }
    cout << endl;
    }
}

float ExpensesRecord::displaySummary(){
    float totalExpenses = 0; // Сумма по всем категориям расходов
    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\tAll categories\t0\n";
        return 0;
    }
    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //выводим на экран категории расходов
        cout << '\t' << ((*iter)->getCategory()) << '\t' << ((*iter)->getAmount()) << endl;
        totalExpenses += (*iter)->getAmount(); //подсчитываем все расходы
        iter++;
    }
    return totalExpenses;
}

void ExpenseEntryScreen::addNewExpenses(){
    date = new Date;
    string category, payee;
    float amount;

    system("cls");
    cout << "Enter month (1-12): ";
    cin >> date->month;
    cin.ignore(80, '\n');
    cout << "Enter the day (1-31): ";
    cin >> date->day;
    cin.ignore(80, '\n');
    cout << "Enter year: ";
    cin >> date->year;
    cin.ignore(80, '\n');
    cout << "Enter an expense category (Repair, Taxes): ";
    cin >> category;
    cout << "Enter recipient (ProstokvashinoElectroSbyt): ";
    cin >> payee;
    cout << "Enter amount (39.95): ";
    cin >> amount;
    cin.ignore(80, '\n');
    // создаем новый расход
    Expense* ptrExpense = new Expense(date, category, payee, amount);
    // вставляем расход в список всех расходов
     ptrExpenseRecord->insertExp(ptrExpense);
}
