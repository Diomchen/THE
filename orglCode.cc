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
//        theEmployeeSystem();
    }
}

//=======================================================The employees' system
CONSOLE_CURSOR_INFO fff;//flashCursor

COORD pos = {0,0};//define the begin pos


void Employee::showTheMenu(HANDLE hOut,string *types,int Size,int thisIndex){

    int i;
    system("cls");

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    pos.X = 30;
    pos.Y = 0;
    SetConsoleCursorPosition(hOut,pos);
    cout<<ETITLE;

    for(i=0 ; i<=Size ; i++){
        if(i == thisIndex){
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|0x8);
            pos.X=30;
            pos.Y = 5+i;
            SetConsoleCursorPosition(hOut,pos);
            cout<<types[i];

        }
        else{
            SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|0x8);
            pos.X = 30;
            pos.Y = 5+i;
            SetConsoleCursorPosition(hOut,pos);
            cout<<types[i];

        }
    }
    fflush(stdout);


}

int Employee::selectMenu( Size , *thisIndex){
    int ch;
    ch = getch();
    switch(ch){
        case UP: if(*thisIndex>0) *thisIndex -= 1;break;
        case DOWN: if(*thisIndex<Size -1) *thisIndex += 1; break;
        case LEFT:return 0;break;
        case RIGHT:return 0;break;
//        case :break;
//        case :break;
//Idea : to make a effect of rebacking
    }


}
//void Employee::inputValue(int sele){
//
//
//
//}
//void Employee::showAndPrintTheReceipt(){
//
//
//
//}

void Employee::theEmployeeSystem(){
    int sele;
    int thisIndex = 0;
    int Size = 10;
    HANDLE hOut;
    SetConsoleTitle(ETITLE);//

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);//

    GetConsoleCursorInfo(hOut,&fff);

    fff.bVisible = 0;

    SetConsoleCursorInfo(hOut,&fff);

    while(true){
        showTheMenu(hOut,types,Size,thisIndex);
        sele = selectMenu(Size, &thisIndex);
//        if(sele == ESC){
//            break;
//        }
//I want to left this position to the setting of 'reback' , it's could be intresting :-)
        if(sele == ENTER){
            switch(thisIndex){
                case 0:break;
                case 1:break;
                case 2:break;
                case 3:break;
                case 4:break;
                case 5:break;
                case 6:break;
                case 7:break;
                case 8:break;
                case 9:break;
            }
        }
        //inputValue(sele);
    }






}












