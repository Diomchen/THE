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
#include <math.h>

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
        {"���ּ���",20},{},
        {"�۶��������",20},{},
        {"�Ǵ��Ź�",20},{},
        {"Ƥ���C����",20},{},
        {"������˿",20},{},
        {"ˮ����",20},{},
        {"��������",25},{},
        {"�����Ź�",25},{},
        {"ը����",25},{},
        {"��������",25},{},
        {"��������",25},{},
        {"���Ŷ���",30},{},
        {"�罷��ͷ",30},{},
        {"����ع���",30},{},
        {"���㶹����",30},{},
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

    struct YearS{
        int monthS ;
        int wY;
    };

    YearS sa[13];

    std::string types[30]=
    {
            "    ���ּ��� 20��",
            "    ",
            "    �۶�������� 20��",
            "    ",
            "    �Ǵ��Ź� 20��",
            "    ",
            "    Ƥ���C���� 20��",
            "    ",
            "    ������˿ 20��",
            "    ",
            "    ˮ���� 20��",
            "    ",
            "    �������� 25��",
            "    ",
            "    �����Ź� 25��",
            "    ",
            "    ը���� 25��",
            "    ",
            "    �������� 25��",
            "    ",
            "    �������� 25��",
            "    ",
            "    ���Ŷ��� 30��",
            "    ",
            "    �罷��ͷ 30��",
            "    ",
            "    ����ع��� 30��",
            "    ",
            "    ���㶹���� 30��",
            "    "
    };

public:
    void readEmployeeD();
    void readRestaurantD();
    void theEmployeeSystem();
    void showTheMenu(std::string *types,int Size,int thisIndex);
    int  selectMenu(int Size,int *thisIndex);
    void inputValue(int cou,int thisIndex);
    void showAndPrintTheReceipt();
    std::string getPresentTime();

//    void showTheMenuDetails();

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

    std::vector<EmpDetail> Emp;

    struct YearSale{
        int monthSale;
        int wYear;
    };

    YearSale sav[13];

    std::string options[10] = {
        "ע����Ա��",
        " ",
        "ע��Ա��",
        " ",
        "����Ա������",
        " ",
        "��ѯԱ����ǰ��ҵ��",
        " ",
        "��ѯ�����ۺ����",
        " ",
    };



public:

    void theMasterSystem();
    void readEmployeeDetail();
    void readRestaurantData();//--------------------------------------------------mark
    void catchMoney();
    void showTheVersion(std::string *options,int optionNum,int thatIndex);
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
