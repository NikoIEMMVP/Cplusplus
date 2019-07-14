// 今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
// 1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
// 2. 待所有字条加入完毕，每人从箱中取一个字条；
// 3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
// 现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？

// 输入描述:
// 输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。


// 输出描述:
// 对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率。
// 示例1
// 输入
// 2
// 输出
// 50.00%

#include <iostream>


float theYear(int n){
    if(n == 1){
        return 0;
    }else if(n == 2){
        return 1;
    }else{
        return (n - 1) * (theYear(n - 2) + theYear(n - 1)); 
    }
}

int main()
{
    int n;
    
    while(std::cin >> n){
        long long  sum = 1;
        for(int i = 2; i <= n; i++){
            sum *= i;
        }
        
        float ret = theYear(n);
        double end = (ret / sum) * 100;
        
        printf("%.2lf%%\n",end);        
    }
    return 0;
}