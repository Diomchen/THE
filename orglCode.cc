//orgCode.cpp
#include "menu.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>

#define ESYS "Employee System"
#define MSYS "Master System"
#define ETITLE "====================================菜单===================================="
#define SIDETITLE "==========选菜栏=========="
#define FOOT "============================================================================"
#define COUNT "===================================状态栏===================================="
#define ETIPS "\tYou can press the \"SPACE\" key to confirm your choice \n\n\tor press the \"TAB\" key to revoke your choice \n\n\tor press the \"ENTER\" key to submit your choices\n\n\tor press the \"ESC\" key to quit this system"
#define MTITLE "===============================店铺及员工管理==============================="

using namespace std;

string LogIn::serchStr = "\0";

//=======================================================logIn

void LogIn::isGoOn(){
    if(tValue == 0)
        exit(0);
}

void LogIn::login(){
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
        if(verifyingMas(userN,passW))
        {
            SetConsoleTextAttribute(tOut,FOREGROUND_GREEN|0X8);
            cout<<"\n\n\t\tLog in...";
            symbol = "master";
            Sleep(1*1000);
            system("cls");
            break;
        }
        else if(verifyingEmp(userN,passW))
        {
            serchStr = userN;
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

bool LogIn::verifyingEmp(string userN,string passW){
    ifstream inFile;
    string serchO,serchT;

    inFile.open("employeeCountInformation.txt",ios::in);
    if(!inFile.is_open()){
        return false;
    }
    else{
        while(!inFile.eof()){
            inFile>>serchO;
            if(serchO == userN){
                inFile>>serchT;//Key step : read the serchT which is behind the serchO
                if(serchT == passW){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
    inFile.close();

    return false;
}

bool LogIn::verifyingMas(string userN,string passW){

    ifstream inFile;
    string serchO,serchT;
    inFile.open("masterCountInformation.txt",ios::in);
    if(!inFile.is_open()){
        return false;
    }
    else{
        while(!inFile.eof()){
            inFile>>serchO;
            if(serchO == userN){
                inFile>>serchT;
                if(serchT == passW){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
    inFile.close();

    return false;
}

void LogIn::select(){
    if(symbol == "master")
    {
        //the master's system
        Master B;
        B.theMasterSystem();
    }
    else if(symbol == "employee")
    {
        //the employees' system
        Employee A;//TIPS : If you want to use the classB's function in the classA , you could make a object to use it.
        A.theEmployeeSystem();
    }
}

//===================================================================================================================================







//=======================================================The employees' system=======================================================

COORD pos = {0,0};//define the begin pos

void Employee::showTheMenu(HANDLE hOut,string *types,int Size,int thisIndex){

//    int i;
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
    for(int t=0 ; t<(int)sStorage.size() ; t++){
        pos.X = 87;
        pos.Y = 4+span;
        SetConsoleCursorPosition(hOut,pos);
        cout<<sStorage[t].sName<<" : "<<sStorage[t].sPrice<<" 元"<<"\n"<<endl;
        span += 2;
    }

//=======================================================================
    for(int i=0 ; i<Size ; i+=2){
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
    fflush(stdout);
}

void Employee::readEmployeeD(){
    string empN;
    string empP;
    string empS;
    int intempS;
    EmpD empMidObj;

    ifstream inEMPfile("employeeCountInformation.txt");
    if(!inEMPfile.is_open()){
        cout<<"Open is failure!";
        Sleep(3000);
        exit(0);
    }
    else{
        while(!inEMPfile.eof()){
            inEMPfile>>empN;
            empMidObj.EmpNu = empN;

            inEMPfile>>empP;
            empMidObj.EmpPa = empP;

            inEMPfile>>empS;
            intempS = str2num(empS);
            empMidObj.EmpSa = intempS;

            empd.push_back(empMidObj);
        }
    }
    inEMPfile.close();
}

void Employee::readRestaurantD(){
    string mSale;
    string year;
    int j = 1;

    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);

    ifstream inRfile("restaurantData.txt");
    if(!inRfile.is_open()){
        exit(0);
    }
    else{
        while(!inRfile.eof()){
            inRfile>>mSale;
            sa[j].monthS = str2num(mSale);
            inRfile>>year;
            sa[j].wY = str2num(year);
            j++;
            if(13 == j)break;
        }

        if(str2num(year)!=(1900+p->tm_year)){
            for(int i=1 ; i<13 ; i++){
                sa[i].monthS = 0;
                sa[i].wY = (1900+p->tm_year);
           }
        }
    }
    inRfile.close();
}

int Employee::selectMenu(int Size ,int *thisIndex){
    int ch;
    ch = getch();
    switch(ch){
        case UP: if(*thisIndex>0) *thisIndex -= 2;break;
        case DOWN: if(*thisIndex<Size -2) *thisIndex += 2; break;
        case LEFT:if(*thisIndex>=10) *thisIndex -= 10;break;
        case RIGHT:if(*thisIndex<20) *thisIndex += 10;break;
        case SPACE:return SPACE;break;
        case ENTER:return ENTER;break;
        case ESC:return ESC;break;
        case TAB:return TAB;break;
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
    tag.sCopies = wantNum;
    tag.sPrice = kind[thisIndex].price * wantNum;

    sStorage.push_back(tag);

}

CONSOLE_CURSOR_INFO sss;

void Employee::showAndPrintTheReceipt(){

    double AllPrice = 0;
    int AllNum = 0;

    char ch;
    LogIn Operator;
    string sTime = getPresentTime();

    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);

    HANDLE sOut;
    sOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i=0 ; i<(int)sStorage.size() ; i++){
        AllPrice += sStorage[i].sPrice;
        AllNum += sStorage[i].sCopies;
    }

    sa[p->tm_mon+1].monthS += (int)AllPrice;

    for(int i=0 ; i<(int)empd.size() ; i++){
        if(Operator.getSech() == empd[i].EmpNu){
            empd[i].EmpSa += (int)AllPrice;
            break;
        }
    }

    ofstream outEMPDfile("employeeCountInformation.txt",ios::trunc);
    if(!outEMPDfile.is_open()){
        exit(0);
    }
    else{
        for(int i=0 ; i<(int)empd.size()-1; i++){
            outEMPDfile<<empd[i].EmpNu<<endl;
            outEMPDfile<<empd[i].EmpPa<<endl;
            outEMPDfile<<empd[i].EmpSa<<endl;
        }
    }
    outEMPDfile.close();

    ofstream outRfile("restaurantData.txt");
    if(!outRfile.is_open()){
        exit(0);
    }
    else{
        for(int i=1 ; i<13 ; i++){
            outRfile<<sa[i].monthS<<endl;
            outRfile<<sa[i].wY<<endl;
        }
    }
    outRfile.close();

//----------------------------------------------------------------------------------------------------------------------------mark
    cout<<"\n\n\tOperator  :  "<<Operator.getSech()<<endl;

    cout<<"\n\tCommodity\t\t\t\tNumber\t\tSubtotal"<<endl;
    cout<<"\t-----------------------------------------------------------------------"<<endl;
    for(int i=0 ; i<(int)sStorage.size() ; i++){
        cout<<"\n\n\t"<<sStorage[i].sName<<"\t\t\t\t\t"<<sStorage[i].sCopies<<"\t\t"<<sStorage[i].sPrice;
    }
    cout<<"\n\t-----------------------------------------------------------------------"<<endl;
    cout<<"\n\t         \t\t\t\tAllNumber\tTotal Amount";
    cout<<"\n\t-----------------------------------------------------------------------"<<endl;
    cout<<"\n\tTotal : \t\t\t\t"<<AllNum<<"\t\t"<<fixed<<setprecision(1)<<AllPrice<<endl;
    cout<<"\n\t-----------------------------------------------------------------------"<<endl;


    cout<<"\n\tDo you want to print the receipt?( Y / N )";
    cin>>ch;
    if('Y' == ch){
        fstream printReceipt("receipt.txt",ios::app);
        ofstream outReceipt("receipt.txt",ios::trunc);
        if(!outReceipt.is_open()){
            SetConsoleTextAttribute(sOut,FOREGROUND_RED);
            cout<<"Print  Failure!";
        }
        else{
            outReceipt<<"\n\n\n\t-----------------------------------------------------------------------------------------------"<<endl;
            outReceipt<<"\t\t\t\t\tX X 饭 店"<<endl;
            outReceipt<<"\t-----------------------------------------------------------------------------------------------"<<endl;
            outReceipt<<"\tDate\t\t\t\t\t\t"<<sTime<<endl;
            outReceipt<<"\tOperator\t\t\t\t\t\t"<<Operator.getSech()<<endl;
            outReceipt<<"\t-----------------------------------------------------------------------------------------------"<<endl;
            outReceipt<<"\tCommodity\t\t\t\tNumber\t\tSubtotal"<<endl;
            outReceipt<<"\t-----------------------------------------------------------------------------------------------"<<endl;
            for(int i=0 ; i<(int)sStorage.size() ; i++){
                outReceipt<<"\n\n\t"<<sStorage[i].sName<<"\t\t\t\t\t"<<sStorage[i].sCopies<<"\t\t"<<sStorage[i].sPrice;
            }
            outReceipt<<"\n\t-----------------------------------------------------------------------------------------------"<<endl;
            outReceipt<<"\n\t\t\t\t\t\tAllNumber\tTotal Amount";
            outReceipt<<"\n\t-----------------------------------------------------------------------------------------------"<<endl;
            outReceipt<<"\n\tTotal : \t\t\t\t\t"<<AllNum<<"\t\t"<<fixed<<setprecision(1)<<AllPrice<<endl;
            outReceipt<<"\n\t-----------------------------------------------------------------------------------------------"<<endl;
            outReceipt<<"\n\t--------------------------------- Thank you for patronage ! --------------------------------"<<endl;


        }
        outReceipt.close();
        printReceipt.close();

        system("cls");
        SetConsoleTextAttribute(sOut,FOREGROUND_GREEN|0x0a);
        cout<<"\n\n\n\n\n\n\t\t\tPrint  Success!!\n\n\n\t\tAnd  the  system  will  back  to  the  menu  after  3s .....";
        Sleep(3000);
    }


}

string Employee::getPresentTime(){
    string strTime;

    time_t pt;
    time(&pt);

    strTime = ctime(&pt);
    return strTime;

}

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

    readRestaurantD();

    readEmployeeD();

    while(true){
        readRestaurantD();
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
            char chO;
            cout<<"Do you want to delete your last choice?( Y / N )";
            cin>>chO;
            if(chO == 'Y'){
                sStorage.erase(sStorage.end()-1);
            }
        }//I want to left "TAB" for the setting of 'revoking' , it's could be intresting :-)
        if(sele == ENTER){
            system("cls");
            pos.X = 5;
            pos.Y = 13;
            SetConsoleCursorPosition(hOut,pos);
            char chT;
            cout<<"Do you want to submit your choice?( Y / N )";
            cin>>chT;
            if(chT == 'Y'){
                    system("cls");
                while(true){
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
                    showAndPrintTheReceipt();
                    //initail the vector array;
                    sStorage.clear();
                    break;
                }
            }
        }
    }
}

//===================================================================================================================================









//=======================================================The master's system=========================================================
COORD zos{0,0};

void Master::showTheVersion(HANDLE xOut,string *options,int optionNum,int thatIndex){
    system("cls");

    SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);
    zos.X = 15;
    zos.Y = 2;
    SetConsoleCursorPosition(xOut,zos);
    cout<<MTITLE;

    SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);
    zos.X = 15;
    zos.Y = 17;
    SetConsoleCursorPosition(xOut,zos);
    cout<<FOOT;

    for(int i=0 ; i<optionNum ; i+=2){
        if(i == thatIndex){
            SetConsoleTextAttribute(xOut,FOREGROUND_RED|0x8);
            zos.X = 48;
            zos.Y = 5 + i;
            SetConsoleCursorPosition(xOut,zos);
            cout<<"=>   "<<options[i];
        }
        else{
            SetConsoleTextAttribute(xOut,FOREGROUND_BLUE|0x8);
            zos.X = 48;
            zos.Y = 5 + i;
            SetConsoleCursorPosition(xOut,zos);
            cout<<options[i];
        }

    }
    fflush(stdout);

}

int Master::select(int optionNum,int *thatIndex){
    int cch;
    cch = getch();
    switch(cch){
        case UP_:if(*thatIndex>0) *thatIndex-=2;break;
        case DOWN_:if(*thatIndex<optionNum-2) *thatIndex+=2;break;
        case ENTER_:return ENTER_;break;
        case ESC_:return ESC_;break;
    }
    return 0;
}

void Master::readEmployeeDetail(){
    string empN;
    string empP;
    string empS;
    int intempS;
    EmpDetail empMidObj;

    ifstream inEMPfile("employeeCountInformation.txt");
    if(!inEMPfile.is_open()){
        cout<<"Open is failure!";
        Sleep(3000);
        exit(0);
    }
    else{
        while(!inEMPfile.eof()){
            inEMPfile>>empN;
            empMidObj.EmpNum = empN;

            inEMPfile>>empP;
            empMidObj.EmpPassword = empP;

            inEMPfile>>empS;
            intempS = str2num(empS);
            empMidObj.EmpSales = intempS;

            Emp.push_back(empMidObj);
        }
    }
    inEMPfile.close();
}

void Master::readRestaurantData(){
    string mSale;
    string year;
    int j = 1;

    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);

    ifstream inRESfile("restaurantData.txt");
    if(!inRESfile.is_open()){
        exit(0);
    }
    else{
        while(!inRESfile.eof()){
            inRESfile>>mSale;
            sav[j].monthSale = str2num(mSale);
            inRESfile>>year;
            sav[j].wYear = str2num(year);
            j++;
            if(13 == j)break;
        }

        if(str2num(year)!=(1900+p->tm_year)){
            for(int i=1 ; i<13 ; i++){
                sav[i].monthSale = 0;
                sav[i].wYear = (1900+p->tm_year);
           }
        }
    }
    inRESfile.close();
}

void Master::addMember(){
    system("cls");

    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);

    HANDLE kOut;
    kOut = GetStdHandle(STD_OUTPUT_HANDLE);

    string registerPass;
    string registerName;
    EmpDetail newMeb;

    cout<<"\n\t\t-----------------------注册新员工-----------------------";
    cout<<"\n\n\n\t\t\t\t(用户名将自动生成)";
    cout<<"\n\n\n\t\t\t\t请输入密码 : ";
    cin>>registerPass;
    registerName = num2str(1900+p->tm_year)+num2str(1+p->tm_mon)+num2str(p->tm_mday)+num2str(p->tm_hour)+num2str(p->tm_min)+num2str(p->tm_sec);
    newMeb.EmpNum = registerName;
    newMeb.EmpPassword = registerPass;
    newMeb.EmpSales = 0;

    Emp.push_back(newMeb);

    ofstream outEMPfile("employeeCountInformation.txt",ios::app);
    if(!outEMPfile.is_open()){
        cout<<"WRONG!";
        exit(0);
    }
    else{
        outEMPfile<<registerName<<endl;
        outEMPfile<<registerPass<<endl;
        outEMPfile<<0<<endl;
    }
    outEMPfile.close();

    cout<<"\n\n\t\t\t\t\tRegisting...";
    Sleep(3000);
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\tSUCCESS!!";
    cout<<"\n\n\n\t\t\t Your USERNAME is : ";
    SetConsoleTextAttribute(kOut,FOREGROUND_RED|0x8);
    cout<<registerName;
    SetConsoleTextAttribute(kOut,FOREGROUND_GREEN|0x8);
    cout<<"\n\n\n\t\t\t Your PASSWORD is : ";
    SetConsoleTextAttribute(kOut,FOREGROUND_RED|0x8);
    cout<<registerPass;
    SetConsoleTextAttribute(kOut,FOREGROUND_GREEN|0x8);
    cout<<"\n\n\t\t\tYou must remember them in 15s!!";
    Sleep(15000);
}

void Master::deleteMember(){
    system("cls");

    HANDLE dOut;
    dOut = GetStdHandle(STD_OUTPUT_HANDLE);

    string unsubscribe;
    char en;
    bool mid = true;
    cout<<"\n\t\t-----------------------注销员工-----------------------";
    cout<<"\n\n\t\t\t请输入需注销的账号 ：";
    cin>>unsubscribe;

    cout<<"\n\n\t\t\tDo you want to log out from this account?( Y / N ) : ";
    cin>>en;
    if('Y' == en){
        for(int i=0 ; i<(int)Emp.size() ; i++){
            if(unsubscribe == Emp[i].EmpNum){
                Emp.erase(Emp.begin()+i);

                ofstream outEMPfile("employeeCountInformation.txt",ios::trunc);
                if(!outEMPfile.is_open()){
                    cout<<"wrong!";
                    Sleep(2000);
                    exit(0);
                }
                else{
                    for(int j=0 ; j<(int)Emp.size()-1 ; j++){
                        outEMPfile<<Emp[j].EmpNum<<endl;
                        outEMPfile<<Emp[j].EmpPassword<<endl;
                        outEMPfile<<Emp[j].EmpSales<<endl;
                    }
                }
                outEMPfile.close();
                system("cls");
                cout<<Emp.size();
                cout<<"\n\n\n\n\n\t\t\t\t\t\t注销成功！";
                Sleep(3000);
                mid = false;
                break;
            }
        }
        if(mid){
            system("cls");
            SetConsoleTextAttribute(dOut,FOREGROUND_RED|0x8);
            cout<<"\n\n\t\t\t未找到此员工！";
            Sleep(2000);
        }
    }
}

void Master::changeMember(){
    system("cls");

    HANDLE lOut;
    lOut = GetStdHandle(STD_OUTPUT_HANDLE);

    string eAccount;
    string eAccountPass;
    bool mid = true;

    cout<<"\n\t\t-----------------------更改员工密码-----------------------";
    cout<<"\n\n\t\t请输入员工账号 ：";
    cin>>eAccount;

    for(int i=0 ; i<(int)Emp.size() ; i++){
        if(eAccount == Emp[i].EmpNum){
            cout<<"\n\n\t\t请输入新密码 ：";
            cin>>eAccountPass;
            Emp[i].EmpPassword = eAccountPass;

            ofstream outEMPfile("employeeCountInformation.txt",ios::trunc);
            if(!outEMPfile.is_open()){
                cout<<"wrong!";
                Sleep(2000);
                exit(0);
            }
            else{
                for(int j=0 ; j<(int)Emp.size() ; j++){
                    outEMPfile<<Emp[j].EmpNum<<endl;
                    outEMPfile<<Emp[j].EmpPassword<<endl;
                    outEMPfile<<Emp[j].EmpSales<<endl;
                }
            }
            outEMPfile.close();
            system("cls");
            cout<<"\n\n\n\n\t\t\t\t\t修改成功!";
            Sleep(3000);
            mid = false;
            break;
        }
    }
    if(mid){
        system("cls");
        SetConsoleTextAttribute(lOut,FOREGROUND_RED|0x8);
        cout<<"\n\n\n\n\t\t\t\t\t未找到此员工！";
        Sleep(2000);
    }
}

void Master::findMember(){
    system("cls");

    HANDLE mOut;
    mOut = GetStdHandle(STD_OUTPUT_HANDLE);

    string EmpAccount;
    string one,two;
    string curentAchive;
    int j=0;
    bool mark = true;

    cout<<"\n\n\t\t\t----------------------查询员工当前总业绩----------------------";
    cout<<"\n\n\n\t\t\t\t\t\t请输入员工账号：";
    cin>>EmpAccount;
    ifstream inEMPfile("employeeCountInformation.txt");
    if(!inEMPfile.is_open()){
        exit(0);
    }
    else{
        while(!inEMPfile.eof()){
            inEMPfile>>curentAchive;
            if(EmpAccount == curentAchive){
                inEMPfile>>one;
                inEMPfile>>two;
                mark = false;
                break;
            }
            j++;
        }
        if(mark){
            system("cls");
            SetConsoleTextAttribute(mOut,FOREGROUND_RED|0x8);
            cout<<"\n\n\t\t\t未找到此员工！";
            Sleep(2000);
        }
    }
    inEMPfile.close();
    if(!mark){
        cout<<"\n\n\t\t\t\t\t\t此员工当前业绩："<<two;
        cout<<"\n\n\n\t\t\t\t\t\t3s后返回主菜单";
        Sleep(3000);
    }
}

COORD gos = {0,30};

void Master::annualSummary(){
    system("cls");

    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);

    HANDLE uOut;
    uOut = GetStdHandle(STD_OUTPUT_HANDLE);

    int j;
    int mid =-1;
    cout<<"\n\n\t\t\t----------------------查询店铺综合情况----------------------";
    cout<<"\n\n\n\t=====================================   全体员工数据一览   ======================================\n\n\n";
    SetConsoleTextAttribute(uOut,07);
    for(int i=0 ; i<(int)Emp.size()-1 ; i++ ){
        cout<<"\n\n\t\t"<<string(35,'+')<<"     |     "<<string(35,'+');
        cout<<"\n\t\t\t\t\t\t\t|\n\t\t员工账号："<<Emp[i].EmpNum<<"\t\t\t|";

        i++;
        if(i>=(int)Emp.size()-1){
            cout<<"\n\t\t\t\t\t\t\t|\n\t\t销售量："<<Emp[i-1].EmpSales;
            break;
        }
        else{
            cout<<"\t员工账号："<<Emp[i].EmpNum;
            cout<<"\n\t\t\t\t\t\t\t|\n\t\t销售量："<<Emp[i-1].EmpSales<<"\t\t\t\t|"<<"\t销售量："<<Emp[i].EmpSales;
        }
    }
    cout<<"\n\n";
    SetConsoleTextAttribute(uOut,FOREGROUND_RED|0x8);
    for(int i=0 ; i<(int)Emp.size()-1 ; i++){
        if(Emp[i].EmpSales>mid){
            mid = Emp[i].EmpSales;
            j = i;
        }
    }

    cout<<"\n\n\t\t"<<"   "<<string(24,'*')<<string(8,' ')<<"销 售 之 星"<<string(8,' ')<<string(24,'*');
    cout<<"\n\n\t\t"<<"         "<<string(18,'*')<<string(9,' ')<<Emp[j].EmpNum<<string(10,' ')<<string(18,'*');
    cout<<"\n\n\t\t\t"<<"       "<<string(12,'*')<<string(8,' ')<<"个 人 销 额"<<string(8,' ')<<string(12,'*');
    cout<<"\n\n\t\t\t\t"<<"     "<<string(6,'*')<<string(11,' ')<<mid<<string(11,' ')<<string(6,'*');

    SetConsoleTextAttribute(uOut,FOREGROUND_GREEN|0x8);
    cout<<"\n\n\n\t=============================================================================================\n";
//=========================================================================================================================================

    int star[13] = {0};
    int lid = -1;
    int k = 0;
    int t = 1;
    double allSale = 0;
    for(int i=1 ; i<13 ; i++){
        star[i] = ceil(sav[i].monthSale/240);
        if(lid<sav[i].monthSale){
            lid = sav[i].monthSale;
            k = i;
        }
        allSale += sav[i].monthSale;
    }
    cout<<"\n\t===================================   餐馆"<<1900+p->tm_year<<"年度数据一览   ====================================\n";

    SetConsoleTextAttribute(uOut,07);
    cout<<"\n\n\n\n\t\t"<<string(22,' ')<<"5k"<<string(21,' ')<<"10k"<<"   月销售额";
    cout<<"\n\t\t"<<string(50,'-')<<">";
    for(int i=1 ; i<13 ; i++){
            cout<<"\n\t"<<i<<"月 "<<"\t|"<<string(star[i],'*');
            cout<<"\n\t\t|";
    }
    cout<<"\n\t\tV";


    for(int i=0 ; i<25 ; i++){
        gos.X = 68;
        gos.Y = 48+i;
        if(t == k&&i%2!=0){
            SetConsoleTextAttribute(uOut,FOREGROUND_RED|0x8);
            cout<<"<-"<<sav[t].monthSale;
            SetConsoleTextAttribute(uOut,07);
            t++;
        }
        else if(t!=k && i%2!=0){
            cout<<"<-"<<sav[t].monthSale;
            t++;
        }
        else{
            cout<<" ";
        }
        SetConsoleCursorPosition(uOut,gos);
    }

    SetConsoleTextAttribute(uOut,FOREGROUND_RED|0x8);
    cout<<"\n\n\t\t销额最高月份： "<<k<<"月"<<"\t销售额： "<<sav[k].monthSale<<"\n\n\t\t"<<"全年总销额："<<fixed<<setprecision(2)<<allSale;

    SetConsoleTextAttribute(uOut,FOREGROUND_GREEN|0x8);
    gos.X = 0;
    gos.Y = 75;
    SetConsoleCursorPosition(uOut,gos);
    cout<<"\n\n\n\t=============================================================================================\n";
    fflush(stdout);
    getch();
}

CONSOLE_CURSOR_INFO vvv;

void Master::theMasterSystem(){
    int thatIndex = 0;
    int optionNum = 10;
    int opo = 1;

    HANDLE xOut;

    xOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTitle(MSYS);

    GetConsoleCursorInfo(xOut,&vvv);
    vvv.bVisible = 0;

    SetConsoleCursorInfo(xOut,&vvv);

    readEmployeeDetail();

    readRestaurantData();
    //At the begining, we should read the "txt" storage,because it will be convenient for us to continue to do the other tasks

    while(true){
        readRestaurantData();

        showTheVersion(xOut,options,optionNum,thatIndex);
        opo = select(optionNum,&thatIndex);
        if(opo == ESC_){
            system("cls");
            cout<<"\n\n\n\t\t\t>>>>>>>>>>>>>>   This system is stop!  <<<<<<<<<<<<<<\n\n\n\n";
            SetConsoleTextAttribute(xOut,07);
            break;
        }
        if(opo == ENTER_){
            switch(thatIndex){
                case 0:SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);addMember();break;
                case 2:SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);deleteMember();break;
                case 4:SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);changeMember();break;
                case 6:SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);findMember();break;
                case 8:SetConsoleTextAttribute(xOut,FOREGROUND_GREEN|0x8);annualSummary();break;
            }
        }
    }



}

int str2num(string s){
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

string num2str(int i){
    stringstream ss;
    ss<<i;
    return ss.str();
}




