#include <iostream>
#include <vector>
#include <string>

bool is_lengths(const std::vector<std::string>& v, const int n){
    if(v.empty()){
        return true;
    }
    
    int size = 0;
    for(int i = 0; i < v.size(); i++){
        if(size > v[i].size()){
            return false;
        }
        size = v[i].size();
    }
    
    return true;
}

bool is_lexicographical(const std::vector<std::string>& v, const int n){
    if(v.empty()){
        return true;
    }
   
    for(int i = 0; i < v.size() - 1; i++){
        int cur_index = 0;
        int next_index = 0;
        std::string cur = v[i];
        std::string next = v[i + 1];
        
        while(cur_index < cur.size() || next_index < next.size()){
            if(cur[cur_index] > next[next_index]){
                return false;
            }
            if(cur_index >= cur.size() || next_index >= next.size()){
                if(cur_index >= cur.size()){
                    return true;
                }
                else{
                    return false;
                }
            }
            
            cur_index++;
            next_index++;
        }
    }
    
    return true;
    
}


int main()
{
    int n = 0;
    std::vector<std::string> v_s;
   
    while(std::cin >> n){
         v_s.resize(n);
        for(int i = 0; i < n; i++){
            std::cin.get();
            getline(std::cin, v_s[i]);
        }
        
        bool lex = is_lexicographical(v_s, n);
        bool leg = is_lengths(v_s,n);
        
        if(lex || leg){
            if(lex && leg){
                std::cout << "both" << std::endl;
            }
            else if(lex){
                std::cout << "lexicographically" << std::endl;
            }
            else if(leg){
                std::cout << "lengths" << std::endl;
            }
        }
        else
            std::cout << "none" << std::endl;
    }
    return 0;
}

//////////////////////////////////////////////////




#include <iostream>
#include <vector>
#include <string>

bool is_lengths(const std::vector<std::string>& v){
    
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i].size() > v[i+1].size()){
            return false;
        }
    }
    
    return true;
}

bool is_lexicographical(const std::vector<std::string>& v){
   
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i + 1])
            return false;
    }
    
    return true;
    
}


int main()
{
    int n = 0;
    std::vector<std::string> v_s;
   
    
    while(std::cin >> n){
         v_s.resize(n);
        for(int i = 0; i < n; i++){
            std::cin.get();
            getline(std::cin, v_s[i]);
        }
        
        bool lex = is_lexicographical(v_s);
        bool leg = is_lengths(v_s);
        
        if(lex || leg){
            if(lex && leg){
                std::cout << "both" << std::endl;
            }
            else if(lex){
                std::cout << "lexicographically" << std::endl;
            }
            else if(leg){
                std::cout << "lengths" << std::endl;
            }
        }
        else
            std::cout << "none" << std::endl;
    }
    return 0;
}