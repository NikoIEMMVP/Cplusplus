

//删除在第一个字符串中出现的第二个字符串的字符


#include <iostream>
#include <string.h>



void DeleteChars(char* str1, char* str2){
    if(str1 == nullptr || str2 == nullptr)
        return;

    bool temp[256];
    for(int i = 0; i < 256; ++i){
        temp[i] = false;
    }

    while(*str2){
        temp[*str2] = true;
        ++str2;
    }

    char* fast = str1;
    char* slow = str1;

    while(*fast != '\0'){
        if(!temp[*fast]){
            *slow = *fast;
            ++slow;
            ++fast;
        }
        else
        {
            ++fast;
        }
        
    }

    *slow = '\0';
}


int main()
{
    char str1[] = "They are students";
    char str2[] = "aeiou";
    DeleteChars(str1,str2);
    std::cout << str1 << std::endl;
    return 0;
}