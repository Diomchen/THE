//menu.h
#ifndef MENU_H_
#define MENU_H_
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

//LogIn
class LogIn
{
private:
    int tValue;
    std::string symbol = "\0";
    static std::string serchStr;
public:
    std::string getSech(){
        return serchStr;
    };

    void login();
    void isGoOn();
    void select();
    bool verifyingEmp(std::string userN,std::string passW);
    bool verifyingMas(std::string userN,std::string passW);
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
        SPACE = 32,
        TAB = 9
    };

    struct storage{
        std::string name;
        int price;
    };

    storage kind[30]{
        {"Æ»¹û·¹",10},{},
        {"Àæ×Ó·¹",10},{},
        {"ÆÏÌÑ·¹",10},{},
        {"Î÷¹Ï·¹",10},{},
        {"²¤ÂÜ·¹",10},{},
        {"Ïã½¶·¹",10},{},
        {"éÙ×Ó·¹",10},{},
        {"ÇàÔæ·¹",10},{},
        {"²ÝÝ®·¹",15},{},
        {"Ê¯Áñ·¹",15},{},
        {"Ïã½¶·¹",15},{},
        {"éÙ×Ó·¹",15},{},
        {"ÇàÔæ·¹",15},{},
        {"²ÝÝ®·¹",15},{},
        {"Ê¯Áñ·¹",15},{},
    };

    struct showStorage{
        std::string sName;
        int sCopies;
        int sPrice;
    };

    std::vector<showStorage> sStorage;

    struct EmpD{
        std::string EmpNu;
        std::string EmpPa;
        int EmpSa;
    };

    std::vector<EmpD> empd;

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
    void readEmployeeD();
    void theEmployeeSystem();
    void showTheMenu(HANDLE hOut,std::string *types,int Size,int thisIndex);
    int  selectMenu(int Size,int *thisIndex);
    void inputValue(int cou,int thisIndex);
    void showAndPrintTheReceipt();
    std::string getPresentTime();

//    void showTheMenuDetails();   //there is a good idea to perfect the program.

};


//Master
class Master{

private:
    enum{
        UP_ = 72,
        DOWN_ = 80,
        ENTER_ = 13,
        ESC_ = 27
    };

    struct EmpDetail{
        std::string EmpNum;
        std::string EmpPassword;
        int EmpSales;
    };

    std::vector<EmpDetail> Emp;//rember to release their storage

    std::string options[10] = {
        "×¢²áÐÂÔ±¹¤",
        " ",
        "×¢ÏúÔ±¹¤",
        " ",
        "¸ü¸ÄÔ±¹¤ÃÜÂë",
        " ",
        "²éÑ¯Ô±¹¤µ±Ç°×ÜÒµ¼¨",
        " ",
        "²éÑ¯µ±Ç°µêÆÌ×ÜÒµ¼¨",
        " ",
    };



public:
    void theMasterSystem();
    void readEmployeeDetail();
    void catchMoney();
    void showTheVersion(HANDLE xOut,std::string *options,int optionNum,int thatIndex);
    int select(int optionNum,int *thatIndex);
    void addMember();
    void deleteMember();
    void changeMember();
    void findMember();
    void annualSummary();





};

int str2num(std::string s);

std::string num2str(int i);

#endif // MENU_H_
