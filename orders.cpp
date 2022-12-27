#include "orders.h"
#include <iostream>

using namespace std;

string Order::getTaskName(){
    return taskName;
}
Fio* Order::getFio(){
    return fio;
}

string Order::getCar(){
    return car;
}

float Order::getCost(){
    return cost;
}

string Order::getStatusName(){
    return statusName;
}

void Order::changeStatusName(string newStatus){
    statusName = newStatus;
}
ListOfOrders::~ListOfOrders(){
    while (!ptrOrdersList.empty())
    {
        iter = ptrOrdersList.begin();
        delete *iter;
        ptrOrdersList.erase(iter);
    }
}

void ListOfOrders::addNewOrders(Order* ptrOrder){
    ptrOrdersList.push_back(ptrOrder);
}

void ListOfOrders::changeStatusName(Order* ptrOrder, string newStatus){
    ptrOrder->changeStatusName(newStatus);
}

float ListOfOrders::getSumOrders(){
    float sum = 0;
    iter = ptrOrdersList.begin();
    while (iter != ptrOrdersList.end())
    {
        if ((*iter)->getStatusName() == "completed")
        {
            sum += (*iter)->getCost();
        }
        iter++;
    }
    return sum;
}

Order* ListOfOrders::findOrders(string taskName, Fio* fio, string car, float cost){
    Fio* findFio;
    iter = ptrOrdersList.begin();
    while (iter != ptrOrdersList.end())
    {
    findFio = (*iter)->getFio();
    if (findFio->fname == fio->fname && findFio->sname == fio->sname && findFio->lname == fio->lname &&
        (*iter)->getTaskName() == taskName && (*iter)->getCar() == car && (*iter)->getCost() == cost)
    {
        delete fio;
        return (*iter);
    }
    iter++;
    }
    return NULL;
}

void ListOfOrders::display(){
    system("cls");
    cout << "\nTask name  \t||Fio   \t\t\t||Cost   \t||Status name\n"<<
            "--------------------------------------------------------------------------------------\n";
    if (ptrOrdersList.empty())
        cout << "***The list is empty***\n" << endl;
    else
    {
        iter = ptrOrdersList.begin();
        while (iter != ptrOrdersList.end())
        {
            cout << (*iter)->getTaskName() << "\t" << "||" <<
                    (*iter)->getFio()->fname << " "<<
                    (*iter)->getFio()->lname << " "<<
                    (*iter)->getFio()->sname << "\t" << "||" <<
                    (*iter)->getCar() << "\t" << "||" <<
                    (*iter)->getCost() << "\t" << "||" <<
                    (*iter)->getStatusName() << endl;
            *iter++;
        }
    }
}
void OrderInteractionScreen::addNewOrder(){
    fio = new Fio;
    system("cls");
    cout << "Enter customer name:\n";
    cin >> fio->fname;
    cout << "Enter client's last name:\n";
    cin >> fio->lname;
    cout << "Enter customer patronymic:\n";
    cin >> fio->sname;
    cin.ignore(80, '\n');
    if(ptrListOfClients->findClientByFio(fio)){
        system("cls");
        cout << "Enter the name of the task:\n";
        getline(cin, taskName);
        cout << "Enter the make of the car:\n";
        getline(cin, car);
        cout << "Enter price:\n";
        cin >> cost;
        cout << "Enter order status (in progress, completed):\n";
        cin.ignore(80, '\n');
        getline(cin, statusName);
        Order* ptrOrder = new Order(taskName,fio,car,cost,statusName);
        ptrListOfOrders->addNewOrders(ptrOrder);
    }else {
        cout << "No such client found!\n";
        system("pause");
    }

}

void OrderInteractionScreen::changeOrder(){
    fio = new Fio;
    string newStatus;
    Order* ptrOrder;
    system("cls");
    cout << "Enter customer name:\n";
    cin >> fio->fname;
    cout << "Enter client's last name:\n";
    cin >> fio->lname;
    cout << "Enter customer patronymic:\n";
    cin >> fio->sname;
    cout << "Enter the name of the task:\n";
    cin >> taskName;
    cout << "Enter the make of the car:\n";
    cin >> car;
    cout << "Enter price:\n";
    cin >> cost;
    ptrOrder = ptrListOfOrders->findOrders(taskName,fio,car,cost);
    if(ptrOrder != NULL){
        cout << "Enter a new order status(in progress, completed):\n";
        cin >> newStatus;
        ptrOrder->changeStatusName(newStatus);
    }else{
        cout << "No such order found!\n";
        system("pause");
    }
    delete fio;
}
