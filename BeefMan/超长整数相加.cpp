// 请设计一个算法完成两个超长正整数的加法。

// 输入描述:
// 输入两个字符串数字

// 输出描述:
// 输出相加后的结果，string型

// 示例1
// 输入
// 99999999999999999999999999999999999999999999999999
// 1
// 输出
// 100000000000000000000000000000000000000000000000000

#include <iostream>
#include <string>

int main()
{
    std::string s1,s2;
    while(std::cin >> s1 >> s2){
        if(s1.size() > s2.size()){
            s2 = std::string(s1.size() - s2.size(), '0') + s2;
        }else if(s1.size() < s2.size()){
            s1 = std::string(s2.size() - s1.size(), '0') + s1;
        }
        
        int carry = 0;
        std::string ret = "";
        for(int i = s1.size() - 1; i >= 0; --i){
            int temp = s1[i] - '0' + s2[i] - '0' + carry;
            char c = temp % 10 + '0';
            ret = c + ret;
            carry = temp / 10;
        }
        
        if(carry){
            ret = '1' + ret;
        }
        std::cout << ret << std::endl;
        
    }
    return 0;
}
















