//orgCode.cpp
#include "menu.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

#define ESYS "Employee System"
#define MSYS "Master System"
#define ETITLE "====================================菜单===================================="
#define SIDETITLE "==========选菜栏=========="
#define FOOT "============================================================================"
#define COUNT "===================================计数栏===================================="
#define ETIPS "\tYou can press the \"SPACE\" key to confirm your choice \n\n\tor press the \"TAB\" key to revoke your choice \n\n\tor press the \"ENTER\" key to submit your choices\n\n\tor press the \"ESC\" key to quit this system"
#define MTITLE "==================================店铺及员工管理=================================="

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
    HANDLE tOut;
    tOut = GetStdHandle(STD_OUTPUT_HANDLE);

    while(t>0)
    {
        SetConsoleTextAttribute(tOut,07);
        cout<<"\n\nYou have "<<t<<" chances to login.";
        cout<<"\n\tUsername  :  ";
        cin>>userN;
        cout<<"\n\tPassword  :  ";
        cin>>passW;
        if("master" == userN && "666666" == passW)
        {
            SetConsoleTextAttribute(tOut,FOREGROUND_GREEN|0X8);
            cout<<"\n\n\t\tLog in...";
            symbol = "master";
            Sleep(5*1000);
            system("cls");
            break;
        }
        else if("20189999" == userN && "private" == passW)
        {
            SetConsoleTextAttribute(tOut,FOREGROUND_GREEN|0X8);
            cout<<"\n\n\t\tLog in...";
            symbol = "employee";
            Sleep(3*1000);
            system("cls");
            break;
        }
        SetConsoleTextAttribute(tOut,FOREGROUND_RED|0X8);
        cout<<"The Username or the Passeord  is WRONG !!!\n\n";
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

        Employee A;//TIPS : If you want to use the classB's function in the classA , you could make a object to use it.
        A.theEmployeeSystem();
    }
}

//=======================================================The employees' system

COORD pos = {0,0};//define the begin pos


void Employee::showTheMenu(HANDLE hOut,string *types,int Size,int thisIndex){

    int i;
    system("cls");

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|0x8);//get the 'TITLE'
    pos.X = 5;
    pos.Y = 2;
    SetConsoleCursorPosition(hOut,pos);//set the position of the 'TITLE'
    cout<<ETITLE;

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|0x8);
    pos.X = 85;
    pos.Y = 2;
    SetConsoleCursorPosition(hOut,pos);
    cout<<SIDETITLE;

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|0x8);
    pos.X = 5;
    pos.Y = 15;
    SetConsoleCursorPosition(hOut,pos);
    cout<<COUNT;

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|0x8);
    pos.X = 5;
    pos.Y = 19;
    SetConsoleCursorPosition(hOut,pos);
    cout<<FOOT;
    cout<<"\n"<<ETIPS;




    SetConsoleTextAttribute(hOut,FOREGROUND_RED|0x8);
    int span = 0;
    for(int t=0 ; t<sStorage.size() ; t++){
        pos.X = 87;
        pos.Y = 4+span;
        SetConsoleCursorPosition(hOut,pos);
        cout<<sStorage[t].sName<<" : "<<sStorage[t].sPrice<<" 元"<<"\n"<<endl;
        span += 2;
    }

//    for(it=sStorage.begin() ; it!=sStorage.end() ; it++ ){
//        pos.X = 87;
//        pos.Y = 4+span;
//        SetConsoleCursorPosition(hOut,pos);
//        cout<<(*it).sName<<" : "<<(*it).sPrice<<" 元"<<"\n"<<endl;
//        span += 2;
//
//    }
//-----------------------------------------------------------------------------------------mark

//=======================================================================
    for(i=0 ; i<=Size ; i+=2){
        if(i == thisIndex){
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|0x8);
            if(i>=0&&i<10){
                pos.X = 5;
                pos.Y = 5+i;
            }
            if(i >= 10&&i<20){
                pos.X = 35;
                pos.Y = i-5;
            }
            if(i>=20&&i<30){
                pos.X = 65;
                pos.Y = i-15;
            }
            SetConsoleCursorPosition(hOut,pos);
            cout<<"=>"<<types[i];
        }
        else{
            SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|0x8);
            if(i>=0&&i<10){
                pos.X = 5;
                pos.Y = 5+i;
            }
            if(i >= 10&&i<20){
                pos.X = 35;
                pos.Y = i-5;
            }
            if(i>=20&&i<30){
                pos.X = 65;
                pos.Y = i-15;
            }
            SetConsoleCursorPosition(hOut,pos);
            cout<<types[i];
        }
    }
//========================================================================
    fflush(stdout);//Why not use the system("cls")?
                   //because it's
}

int Employee::selectMenu(int Size ,int *thisIndex){
    int ch;
    ch = getch();
    switch(ch){
        case UP: if(*thisIndex>0) *thisIndex -= 2;break;
        case DOWN: if(*thisIndex<Size -2) *thisIndex += 2; break;
        case LEFT:if(*thisIndex>=10) *thisIndex -= 10;break;
        case RIGHT:if(*thisIndex<20) *thisIndex += 10;break;
        case SPACE:return 32; break;
        case ENTER:break;
        case ESC:return 27;break;
        case TAB:return 9;break;
//Idea : to make a effect of rebacking
    }
    return 0;
}
void Employee::inputValue(int cou,int thisIndex){
    int wantNum;
    showStorage tag;//key step

    cout<<kind[thisIndex].name<<"× ";
    cin>>wantNum;

    tag.sName = kind[thisIndex].name;
    tag.sPrice = kind[thisIndex].price * wantNum;

    sStorage.push_back(tag);

}


//void Employee::showAndPrintTheReceipt(){
//
//
//
//}

CONSOLE_CURSOR_INFO fff;//flashCursor


void Employee::theEmployeeSystem(){
    int sele;
    int thisIndex = 0;
    int Size = 30;
    int cou = 1;

    HANDLE hOut;
    SetConsoleTitle(ESYS);//change this title

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);//get the std Handle

    GetConsoleCursorInfo(hOut,&fff);//get cursor

    fff.bVisible = 0;//set this cursor disappear

    SetConsoleCursorInfo(hOut,&fff);//set cursor

    while(true){
        showTheMenu(hOut,types,Size,thisIndex);
        sele = selectMenu(Size, &thisIndex);
        if(sele == ESC){
            system("cls");
            cout<<"\n\n\n\t\t\t>>>>>>>>>>>>>>   This system is stop!  <<<<<<<<<<<<<<\n\n\n\n";
            SetConsoleTextAttribute(hOut,07);
            break;
        }
        if(sele == SPACE){
            pos.X = 5;
            pos.Y = 17;
            SetConsoleCursorPosition(hOut,pos);
            switch(thisIndex){
                case 0:
                    inputValue(cou,thisIndex);
                    break;
                case 2:
                    inputValue(cou,thisIndex);
                    break;
                case 4:
                    inputValue(cou,thisIndex);
                    break;
                case 6:
                    inputValue(cou,thisIndex);
                    break;
                case 8:
                    inputValue(cou,thisIndex);
                    break;
                case 10:
                    inputValue(cou,thisIndex);
                    break;
                case 12:
                    inputValue(cou,thisIndex);
                    break;
                case 14:
                    inputValue(cou,thisIndex);
                    break;
                case 16:
                    inputValue(cou,thisIndex);
                    break;
                case 18:
                    inputValue(cou,thisIndex);
                    break;
                case 20:
                    inputValue(cou,thisIndex);
                    break;
                case 22:
                    inputValue(cou,thisIndex);
                    break;
                case 24:
                    inputValue(cou,thisIndex);
                    break;
                case 26:
                    inputValue(cou,thisIndex);
                    break;
                case 28:
                    inputValue(cou,thisIndex);
                    break;
            }
            cou++;
        }
        if(sele == TAB){
            pos.X = 5;
            pos.Y = 17;
            SetConsoleCursorPosition(hOut,pos);
            char ch;
            cout<<"Do you want to delete your last choice?( Y / N )";
            cin>>ch;
            if(ch == 'Y'){
                int mid;
//                showStorage tpg;
                int s = sStorage.size();
                sStorage.pop_back(sStorage[s-1]);
//--------------------------------------------------------------------------------------------mark
//                mid = ;
//                showStorage tpg;
//                tpg.sName.pop_back();
//                tpg.sPrice.pop_back(mid);
            }

        }

        //I want to left "BACKSPACE" for the setting of 'revoking' , it's could be intresting :-)

    }
}












