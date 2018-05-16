//Programing:the system of resterant counting

#include <iostream>
#include "menu.h"
#include <sstream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    LogIn a;
    a.login();
    if(a.isGoOn()){
        return 0;
    }
    cout<<"\nhello!";


    return 0;
}
