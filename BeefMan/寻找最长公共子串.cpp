// 查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。

// 输入描述:
// 输入两个字符串


// 输出描述:
// 返回重复出现的字符


#include <iostream>
#include <string>


int main()
{
    std::string str1, str2;
    while(std::cin >> str1 >> str2){
        if(str1.size() == 0 || str2.size() == 0){
            return 0;
        }
        
        if(str1.size() > str2.size()){
            swap(str1, str2);
        }
        
        std::string ret;
        for(int i = 0; i < str1.size(); ++i){
            for(int j = i; j < str1.size(); ++j){
                std::string temp = str1.substr(i, j - i + 1);
                if(int(str2.find(temp)) < 0)
                    break;
                else if(ret.size() < temp.size())
                    swap(ret,temp);
                    
            }
        }
        
        std::cout << ret << std::endl;
    }
    return 0;
}