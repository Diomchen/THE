
//Programing    :    the system of resterant managing
//Date          :    2018-5-24
//Author        :    DiomChen
//Blog          :    https://blog.csdn.net/qq_41628088

#include <iostream>
#include <string>
#include "menu.h"
#include <sstream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{

    SetConsoleTitle("Login");

    LogIn user;
    user.login();

    user.isGoOn();

    user.select();

    return 0;
}
