

// 有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？ 

// 输入描述:
// 输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。



// 输出描述:
// 对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。


// 正常推倒：
#include <iostream>
 
 
int Coke(int n){
    if(n < 3){
        if(2 == n){
            int count = 1;
            return 1;
        }else
            return 0;
    }
     
    int count = n / 3;
    int bottle = count + n % 3;
    return count + Coke(bottle);
}
 
 int main()
 {
     int n;
     while(std::cin >> n){
         if(!n){
             return 0;
         }
          
         std::cout << Coke(n) << std::endl;
     }
     return 0;
 }


 // 数学分析：最后喝到的可乐数是空瓶子除以2.。。。
 #include <iostream>
 
 

 
 int main()
 {
     int n;
     while(std::cin >> n){
         if(!n){
             return 0;
         }
          
         std::cout << n / 2 << std::endl;
     }
     return 0;
 }