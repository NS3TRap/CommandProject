#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <list>
#include "typefio.h"
#include "clients.h"
using namespace std;

class Order
{
private:
    int numberOrder;
    string taskName;
    Fio* fio;
    string car;
    float cost;
    string statusName;
public:
    Order(int no,string tn, Fio* name, string car, float cost, string sn): numberOrder(no),taskName(tn), fio(name), car(car), cost(cost), statusName(sn) {}
    ~Order() {}
    string getTaskName();
    Fio* getFio();
    string getCar();
    float getCost();
    string getStatusName();
    void changeStatusName(string);
    int getNumberOrder();
};

class ListOfOrders
{
private:
    list<Order*> ptrOrdersList;
    list<Order*>::iterator iter;
    list<Order*>::reverse_iterator rIter;
public:
    ~ListOfOrders();
    void addNewOrders(Order*);
    void changeStatusName(Order*, string);
    float getSumOrders();
    void display();
    Order* findOrders(int);
    int getNewNumberOrder();
};

class OrderInteractionScreen
{
private:
    ListOfOrders* ptrListOfOrders;
    ListOfClients* ptrListOfClients;
    int numberOrder;
    string taskName;
    Fio* fio;
    string car;
    float cost;
    string statusName;
public:
    OrderInteractionScreen(ListOfOrders* ptrLOO,ListOfClients* ptrLOC) : ptrListOfOrders(ptrLOO), ptrListOfClients(ptrLOC) {}
    ~OrderInteractionScreen() {}
    void addNewOrder();
    void changeOrder();
};
#endif // ORDERS_H
