//字符串中找最长数字串



#include <iostream>
#include <string>


int main()
{
    std::string s;
    s.reserve(255);
    while(getline(std::cin,s)){
        int max_size = 0;
        int start = 0;
        int count = 0;
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                count = 0;
                index = i;
                while(s[i] >= '0' && s[i] <= '9'){
                    count++;
                    i++;
                }
                
                if(count > max_size){
                max_size = count;
                start = index;
                }
            }
            
            
        }
        
        std::cout << s.substr(start,max_size) << std::endl;
    }
    return 0;
}