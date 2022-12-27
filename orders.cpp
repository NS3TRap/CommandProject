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

int Order::getNumberOrder(){
    return numberOrder;
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

Order* ListOfOrders::findOrders(int numberOrder){
    iter = ptrOrdersList.begin();
    while (iter != ptrOrdersList.end())
    {
    if ((*iter)->getNumberOrder() == numberOrder)
    {
        return (*iter);
    }
    iter++;
    }
    return NULL;
}

int ListOfOrders::getNewNumberOrder(){
    if (ptrOrdersList.empty())
        return 1;
    else{
        rIter = ptrOrdersList.rbegin();
        return (*rIter)->getNumberOrder()+1;
    }
}

void ListOfOrders::display(){
    system("cls");
    cout << "\nNum ||\tTask name  \t||Fio   \t\t\t||Car \t||Cost\t||Status name\n"<<
            "--------------------------------------------------------------------------------------\n";
    if (ptrOrdersList.empty())
        cout << "***The list is empty***\n" << endl;
    else
    {
        iter = ptrOrdersList.begin();
        while (iter != ptrOrdersList.end())
        {
            cout << (*iter)->getNumberOrder() << "\t" << "||" <<
                    (*iter)->getTaskName() << "\t" << "||" <<
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
    string phone;
    numberOrder = ptrListOfOrders->getNewNumberOrder();
    system("cls");
    cout << "Enter customer name:\n";
    cin >> fio->fname;
    cout << "Enter client's last name:\n";
    cin >> fio->lname;
    cout << "Enter customer patronymic:\n";
    cin >> fio->sname;
    cout << "Enter customer phone:\n";
    cin >> phone;
    cin.ignore(80, '\n');
    if(ptrListOfClients->findClientByFio(fio,phone)){
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
        Order* ptrOrder = new Order(numberOrder,taskName,fio,car,cost,statusName);
        ptrListOfOrders->addNewOrders(ptrOrder);
    }else {
        cout << "No such client found!\n";
        system("pause");
    }

}

void OrderInteractionScreen::changeOrder(){
    string newStatus;
    Order* ptrOrder;
    system("cls");
    cout << "Enter number order:\n";
    cin >> numberOrder;
    ptrOrder = ptrListOfOrders->findOrders(numberOrder);
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
