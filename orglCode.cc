//orgCode.cpp
#include "menu.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

//logIn

bool LogIn::isGoOn(){
    if(tValue == 0){
        return true;
    }
    return false;
}

void LogIn::login()
{
    int t = 3;
    string userN,passW;

    while(t>0)
    {
        cout<<"You have "<<t<<" chances to login.";
        cout<<"\nUsername\t:";
        cin>>userN;
        cout<<"\nPassword\t:";
        cin>>passW;
        if("admin" == userN&&"123456" == passW){
            cout<<"\n\n\t\tLog in...";
            Sleep(5*1000);
            system("cls");
            break;
        }
        cout<<"the username or the passeord  is wrong !!!\n\n";
        t--;
        tValue = t;
    }
}
