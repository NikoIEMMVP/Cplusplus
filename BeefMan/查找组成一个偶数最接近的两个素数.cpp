#include <iostream>

bool IsPrime(const int num){
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0){
            return false;
        }
    }
    
    return true;
}


int main()
{
    int input = 0;
    while(std::cin >> input){
        if(input % 2 != 0)
            return 1;
        
        int differ = 0;
        int min = 0;
        int ret = 0;
        for(int j = 2; j <= input / 2; ++j){
            if(IsPrime(j) && IsPrime(input - j)){
                differ = input - j -j;
                if(min == 0 || differ < min){
                    min = differ;
                    ret = j;
                }
            }
        }
        
        
        std::cout << ret << std::endl;
        std::cout << input - ret << std::endl;
        
    }
    return 0;
}