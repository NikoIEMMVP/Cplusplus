
// NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
// 现在给你一段时间区间，请你帮他计算总收益有多少。

// 输入描述:
// 输入包含多组数据。

// 每组数据包含两个日期from和to (2000-01-01 ≤ from ≤ to ≤ 2999-12-31)。

// 日期用三个正整数表示，用空格隔开：year month day。


// 输出描述:
// 对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。
// 示例1
// 输入
// 2000 1 1 2000 1 31
// 2000 2 1 2000 2 29
// 输出
// 62
// 29

// write your code here cpp
#include <iostream>
#include <vector>


int main()
{
    int year1,month1,day1,year2,month2,day2;
    int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2){
        int sum = 0;
        for(int i = year1; i < year2; i++){
            if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)){
                sum += 550;
            }else{
                sum += 549;
            }
        }
        if(month2 > month1){
            for(int i = month1; i < month2; i++){
                if(i != 4 && i != 6 && i != 8 && i != 9 && i != 10 && i != 12){
                    sum += day[i];
                }else{
                    sum += 2 * day[i];
                }
                
                i = month1;
                if(i != 4 && i != 6 && i != 8 && i != 9 && i != 10 && i != 12){
                    sum -= day1;
                }else{
                    sum -= day1 * 2;
                }
                
                i = month2;
                if(i != 4 && i != 6 && i != 8 && i != 9 && i != 10 && i != 12){
                    sum += day2 + 1;
                }else{
                    sum += (day2 + 1) * 2;
                }
            }
        }else if(month1 == month2){
            int i = month2;
                if(i != 1 && i != 4 && i != 6 && i != 8 && i != 9 && i != 10 && i != 12){
                    sum += day2 - day1 + 1;
                }else{
                    sum += (day2 - day1 + 1)* 2;
                }
        }else{
            for(int i = 0; i < month1;i++){
                if(i != 1 && i != 4 && i != 6 && i != 8 && i != 9 && i != 10 && i != 12){
                    sum -= day[i];
                }else{
                    sum -= day[i] * 2;
                }
            }
            
            int i = month1;
            if(i != 1 && i != 4 && i != 6 && i != 8 && i != 9 && i != 10 && i != 12){
                    sum -= day1;
                }else{
                    sum -= day1 * 2;
                }
        }
        
          std::cout << sum << std::endl;
        
    }
    return 0;
}