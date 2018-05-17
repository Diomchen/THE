//orgCode.cpp
#include "menu.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define ETITLE "菜单"
#define MTITLE "店铺及员工管理"

using namespace std;

//=======================================================logIn

void LogIn::isGoOn()
{
    if(tValue == 0)
        exit(0);
}

void LogIn::login()
{
    int t = 3;
    string userN,passW;

    while(t>0)
    {
        cout<<"You have "<<t<<" chances to login.";
        cout<<"\nUsername  :  ";
        cin>>userN;
        cout<<"\nPassword  :  ";
        cin>>passW;
        if("master" == userN && "666666" == passW)
        {
            cout<<"\n\n\t\tLog in...";
            symbol = "master";
            Sleep(5*1000);
            system("cls");
            break;
        }
        else if("20189999" == userN && "private" == passW)
        {
            cout<<"\n\n\t\tLog in...";
            symbol = "employee";
            Sleep(3*1000);
            system("cls");
            break;
            //
        }
        cout<<"the username or the passeord  is wrong !!!\n\n";
        t--;
        tValue = t;
    }
}

void LogIn::select()
{
    if(symbol == "master")
    {
        //the master's system
        cout<<"master";
    }
    else if(symbol == "employee")
    {
        //the employees' system
        cout<<"employee";
    }
}

//=======================================================The employees' system
CONSOLE_CURSOR_INFO fff;

COORD pos = {0,0};


void Employee::showTheMenu(HANDLE hOut,string *types,int size,int thisIndex){

    int i;
    system("cls");

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    pos.X = 30;
    pos.Y = 0;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ETITLE;

    for(i=0 ; i<=size ; i++){
        if(i == thisIndex){
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|0x8);
            pos.X=30;
            pos.Y = 5+i;
            SetConsoleCursorPosition(hOut,pos);
            cout<<types[i];

        }
        else{
            SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|0x8);
            pos.x = 30;
            pos.Y = 5+i;
            SetConsoleCursorPosition(hOut,pos);
            cout<<types[i];

        }
    }
    fflush(stdout);


}

int Employee::selectMenu(){



}
void Employee::inputValue(int sele){



}
void Employee::showAndPrintTheReceipt(){



}
void Employee::theEmployeeSystem(){
    int sele;
    int thisIndex = 0;
    int typeSize = 10;
    HANDLE hout;
    SetConsoleTitle(ETITLE);//??

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);//??I think it could be delete.

    GetConsoleCursorInfo(hOut,&fff);

    fff.bVisible = 0;

    SetConsoleCursorInfo(hOut,&fff);

    while(true){
        showTheMenu(hout,types,typeSize,thisIndex);
        sele = selectMenu(*typeSize,thisIndex);
        inputValue(sele);
    }






}












