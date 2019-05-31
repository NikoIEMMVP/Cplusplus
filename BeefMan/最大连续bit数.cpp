#include <iostream>



int main()
{
    int input = 0;
    while(std::cin >> input){
        int count = 0;
        int ret = 0;
        for(int i = 0; i < 32; i++){
            if(1 == ((input>>i) & 1)){
                count++;
            }else{
                if(count > ret){
                    ret = count;
                }
                count = 0;
            }
        }
        std::cout << ret << std::endl;
    }
    return 0;
}