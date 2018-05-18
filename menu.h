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
    enum{
        UP = 72,
        DOWN = 80,
        LEFT = 75,
        RIGHT = 77,
        ENTER = 13,
        ESC = 27,
    };
    std::string types[10]=
    {
        "\tÆ»¹û·¹",
        "\tÀæ×Ó·¹",
        "\tÆÏÌÑ·¹",
        "\tÎ÷¹Ï·¹",
        "\t²¤ÂÜ·¹",
        "\tÏã½¶·¹",
        "\téÙ×Ó·¹",
        "\tÇàÔæ·¹",
        "\t²ÝÝ®·¹",
        "\tÊ¯Áñ·¹"
    };

public:

    void  theEmployeeSystem();
    void showTheMenu(HANDLE hOut,std::string *types,int Size,int thisIndex);
    int staticselectMenu(int Size,int *thisIndex);//require : use the keyborad to operate this act
    void inputValue();
    void showAndPrintTheReceipt();

//    void showTheMenuDetails();   //there is a good idea to perfect the program.

};





#endif // MENU_H_
