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
    string taskName;
    Fio* fio;
    string car;
    float cost;
    string statusName;
public:
    Order(string tn, Fio* name, string car, float cost, string sn): taskName(tn), fio(name), car(car), cost(cost), statusName(sn) {}
    ~Order() {}
    string getTaskName();
    Fio* getFio();
    string getCar();
    float getCost();
    string getStatusName();
    void changeStatusName(string);
};

class ListOfOrders
{
private:
    list<Order*> ptrOrdersList;
    list<Order*>::iterator iter;
public:
    ~ListOfOrders();
    void addNewOrders(Order*);
    void changeStatusName(Order*, string);
    float getSumOrders();
    void display();
    Order* findOrders(string, Fio* , string , float );
};

class OrderInteractionScreen
{
private:
    ListOfOrders* ptrListOfOrders;
    ListOfClients* ptrListOfClients;
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
