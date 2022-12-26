#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <list>
#include "typefio.h"
using namespace std;

class Order
{
private:
    string taskName;
    Fio fio;
    string car;
    float cost;
    string statusName;
public:
    Order(string tn, Fio name, string car, float cost, string sn): taskName(tn), fio(name), car(car), cost(cost), statusName(sn) {}
    ~Order();
    string getTaskName();
    Fio getFio();
    string getCar();
    float getCost();
    string getStatusName();
};

class ListOfOrders
{
private:
    list<Order*> ptrOrdersList;
    list<Order*>::iterator iter;
public:
    ~ListOfOrders();
    void addNewOrders();
    void changeStatusName();
    void getOrdersList();
};

class OrderInteractionScreen
{
private:
    ListOfOrders* ptrListOfOrders;
public:
    OrderInteractionScreen(ListOfOrders* ptrLOO) : ptrListOfOrders(ptrLOO) {}
    ~OrderInteractionScreen();
    void addNewOrder();
    void changeOrder();
};
#endif // ORDERS_H
