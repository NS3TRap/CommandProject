#include <iostream>
#include "other.h"

using namespace std;

int main()
{
    UserInterfaceScreen* UIS = new UserInterfaceScreen();
    UIS->interact();
    return 0;
}
