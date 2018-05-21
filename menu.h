//menu.h
#ifndef MENU_H_
#define MENU_H_
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//LogIn
class LogIn
{
private:
    int tValue;

    std::string symbol = "\0";
public:


    void login();
    void isGoOn();
    void select();
};

//Employee
class Employee
{
private:
    enum
    {
        UP = 72,
        DOWN = 80,
        LEFT = 75,
        RIGHT = 77,
        ENTER = 13,
        ESC = 27,
    };
    std::string types[30]=
    {
//        {
            "    ƻ����",
            "    ",
            "    ���ӷ�",
            "    ",
            "    ���ѷ�",
            "    ",
            "    ���Ϸ�",
            "    ",
            "    ���ܷ�",
            "    ",
            "    �㽶��",
            "    ",
            "    ���ӷ�",
            "    ",
            "    ���淹",
            "    ",
            "    ��ݮ��",
            "    ",
            "    ʯ��",
            "    ",
            "    �㽶��",
            "    ",
            "    ���ӷ�",
            "    ",
            "    ���淹",
            "    ",
            "    ��ݮ��",
            "    ",
            "    ʯ��",
            "    "
    };

public:

    void  theEmployeeSystem();
    void showTheMenu(HANDLE hOut,std::string *types,int Size,int thisIndex);
    int  selectMenu(int Size,int *thisIndex);
    void inputValue();
    void showAndPrintTheReceipt();

//    void showTheMenuDetails();   //there is a good idea to perfect the program.

};





#endif // MENU_H_
