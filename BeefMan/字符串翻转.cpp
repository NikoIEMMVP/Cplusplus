#include <iostream>
#include <string>

std::string& ReverseString(std::string& str){
    int i = 0;
    int size = str.size() - 1;
    while(i < size){
        char temp;
        temp = str[i];
        str[i] = str[size];
        str[size] = temp;
        i++;
        size--;
    }
    
    return str;
}

int main()
{
    std::string input;
    while(std::cin >> input){
        std::cout << ReverseString(input) << std::endl;
    }
    return 0;
}