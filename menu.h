//menu.h
#ifndef MENU_H_
#define MENU_H_
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>


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
        BACKSPACE = 8,
        SPACE = 32
    };

    struct storage{
        std::string name;
        int price;
    };

    storage kind[15]{
        {"Æ»¹û·¹",10},
        {"Àæ×Ó·¹",10},
        {"ÆÏÌÑ·¹",10},
        {"Î÷¹Ï·¹",10},
        {"²¤ÂÜ·¹",10},
        {"Ïã½¶·¹",10},
        {"éÙ×Ó·¹",10},
        {"ÇàÔæ·¹",10},
        {"²ÝÝ®·¹",15},
        {"Ê¯Áñ·¹",15},
        {"11",15},
        {"12",15},
        {"13",15},
        {"14",15},
        {"15",15},
    };

    struct showStorage{
        std::string sName;
        int sPrice;
    };
    std::vector<showStorage> sStorage;

    std::string types[30]=
    {
            "    Æ»¹û·¹ 10£¤",
            "    ",
            "    Àæ×Ó·¹ 10£¤",
            "    ",
            "    ÆÏÌÑ·¹ 10£¤",
            "    ",
            "    Î÷¹Ï·¹ 10£¤",
            "    ",
            "    ²¤ÂÜ·¹ 10£¤",
            "    ",
            "    Ïã½¶·¹ 10£¤",
            "    ",
            "    éÙ×Ó·¹ 10£¤",
            "    ",
            "    ÇàÔæ·¹ 10£¤",
            "    ",
            "    ²ÝÝ®·¹ 15£¤",
            "    ",
            "    Ê¯Áñ·¹ 15£¤",
            "    ",
            "    Ïã½¶·¹ 15£¤",
            "    ",
            "    éÙ×Ó·¹ 15£¤",
            "    ",
            "    ÇàÔæ·¹ 15£¤",
            "    ",
            "    ²ÝÝ®·¹ 15£¤",
            "    ",
            "    Ê¯Áñ·¹ 15£¤",
            "    "
    };

public:

    void  theEmployeeSystem();
    void showTheMenu(HANDLE hOut,std::string *types,int Size,int thisIndex);
    int  selectMenu(int Size,int *thisIndex);
    void inputValue(int cou,int thisIndex);
    void showSideMenu();
    void showAndPrintTheReceipt();

//    void showTheMenuDetails();   //there is a good idea to perfect the program.

};





#endif // MENU_H_
