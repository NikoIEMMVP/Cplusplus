#include <iostream>
#include <string>

int main()
{
    std::string str;
    while(std::cin >> str)
        {
        size_t i = 0;
        for ( i = 0; i < str.size(); i++)
            {
            if(str.find(str[i])==str.rfind(str[i]))
            {
                std::cout<<str[i]<<std::endl;
                    break;
            }
        }
        if(i==str.size())
            std::cout<<-1;
    }
    return 0;
}