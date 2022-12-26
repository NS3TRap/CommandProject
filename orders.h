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

#endif // ORDERS_H
