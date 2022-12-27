#include "clients.h"
#include <iostream>
using namespace std;

Fio* Client::getFio(){
    return fio;
}

string Client::getPhone(){
    return phone;
}

ListOfClients::~ListOfClients(){
    while (!ptrClientList.empty())
    {
        iter = ptrClientList.begin();
        delete *iter;
        ptrClientList.erase(iter);
    }
}

void ListOfClients::addClient(Client* ptrClient){
    ptrClientList.push_back(ptrClient);
}

void ListOfClients::getListClients(){
    system("cls");
    cout << "\nFirst Name  \t||Second Name   \t||Patronymic  \t||Phone\n-------------------------------------------------------------------------\n";
    if (ptrClientList.empty())
        cout << "***The list is empty***\n" << endl;
    else
    {
        iter = ptrClientList.begin();
        while (iter != ptrClientList.end())
        {
            cout << (*iter)->getFio()->fname << "\t\t" << "||" <<
                    (*iter)->getFio()->lname << "\t\t" << "||" <<
                    (*iter)->getFio()->sname << "\t" << "||" <<
                    (*iter)->getPhone() << endl;
            *iter++;
        }
    }
}

bool ListOfClients::findClientByFio(Fio* searchFio){
    Fio* findFio;
    iter = ptrClientList.begin();
    while (iter != ptrClientList.end())
    {
    findFio = (*iter)->getFio();
    if (findFio->fname == searchFio->fname && findFio->sname == searchFio->sname && findFio->lname == searchFio->lname)
    {
        return true;
    }
    iter++;
    }
    return false;
}

void ClientEntryScreen::addNewClient(){
    fio = new Fio;

    system("cls");
    cout << "Enter customer name:\n";
    cin >> fio->fname;
    cout << "Enter client's last name:\n";
    cin >> fio->lname;
    cout << "Enter customer patronymic:\n";
    cin >> fio->sname;
    cout << "Enter customer phone:\n";
    cin >> phone;

    Client* ptrClient = new Client(fio, phone);
    ptrListOfClients->addClient(ptrClient);
}
