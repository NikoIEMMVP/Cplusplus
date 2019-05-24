//  一个字符串A，一个字符串B
// 将字符串B 插入到 A 中，判断是否是回文串


#include <iostream>
#include <string>


bool isPalindrome(std::string& temp){
    int size = temp.size();
    for(int i = 0; i < temp.size(); i++){
        if(i < size){
            if(temp[i] != temp[size - 1])
            return false;
        }else
            break;
        size--;
    }
    
    return true;
}


void theNumberOfPalindrome(std::string& str1, std::string& str2){
    int size = str1.size();
    int count = 0;
    std::string temp;
    std::string cur ;
    for(int i = 0; i <= size; i++){
        cur = str1;
        temp = cur.insert(i,str2);
        if(isPalindrome(temp))
            count++;
    }
    std::cout << count << std::endl;
}

int main()
{
    std::string str1,str2;
    while(std::cin >> str1 >> str2){
        theNumberOfPalindrome(str1,str2);
    }
    return 0;
    
}