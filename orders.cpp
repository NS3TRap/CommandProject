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
