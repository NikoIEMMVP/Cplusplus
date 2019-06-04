// 输入给定日期 年 月 日
// 输出 这是这一年的第几天、


#include <iostream>


int DayOfYear(const int year, const int month, const int day){
    if(year <= 0 || month <= 0 || day <= 0){
        return -1;
    }
    int Day[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return Day[month - 1] + day + 1;
    }else
        return Day[month - 1] + day;
}


int main()
{
    int year,month,day;
    while(std::cin >> year >> month >> day){
        int ret = DayOfYear(year, month, day);
        if(ret == -1)
            return 1;
        std::cout << ret << std::endl;
    }
    return 0;
}