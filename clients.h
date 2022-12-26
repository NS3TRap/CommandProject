#ifndef CLIENTS_H
#define CLIENTS_H
#include "typefio.h"
#include <list>
using namespace std;

class Client
{
private:
    Fio fio;
    string phone;
public:
    Client(Fio prtFio,string ph): fio(prtFio), phone(ph) {}
    ~Client() {}
    Fio getFio();
    string getPhone();
};

class ListOfClients{
private:
    list<Client*> ptrClientList;
    list<Client*>::iterator iter;
public:
    ~ListOfClients() {}
    void addClient(Client*);
    void getListClients();
};

class ClientEntryScreen{
private:
    ListOfClients* ptrListOfClients;
    Fio fio;
    string phone;
public:
    ClientEntryScreen(ListOfClients* ptrLOC): ptrListOfClients(ptrLOC){}
    void addNewClient();
};



#endif // CLIENTS_H
