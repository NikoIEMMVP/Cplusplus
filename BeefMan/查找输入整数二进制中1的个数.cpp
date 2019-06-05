#include <iostream>

int main()
{
    int input;
    while(std::cin >> input){
        if(input == 0 || input < 0){
            if(input == 0){
                std::cout << 0 << std::endl;
                return 1;
            }
            
            input = (-1) * input;
        }
        
        int count = 0;
        for(int i = 0; i < 31; ++i){
            if(1 == ((input>>i) & 1))
                ++count;
        }
        
        std::cout << count << std::endl;
        
    }
    return 0;
}