#include <iostream>
#include "overloading.h"

using namespace std;

int main()
{
    bankAccount acc1("savas", "eratesli", 5200, "05346256566");

    cout << acc1;
    
    acc1 + 1000;

    cout << acc1;

    //acc1 - 25000;

    //cout << acc1;

    return 0;
}

