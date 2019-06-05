// 解析在命令行中输入的命令
// 各命令以空格为间隔
//对于包含 “” 的参数，如果其内有空格，不能解析为多个参数，应为一个参数

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    char input[1024];
    vector<string> v;
    while(cin.getline(input,1024)){
        string s = "";
        int size = strlen(input);
        v.clear();
        for(int i = 0; i < size; i++){
            if(input[i] == '"'){
                i++;
                while(input[i] != '"'){
                    s += input[i];
                    i++;
                }
                v.push_back(s);
                s = "";
                i++;
                continue;
            }
            else{
                if(input[i] != ' '){
                    s += input[i];
                }
                else{
                    v.push_back(s);
                    s = "";
                }
            }
        }
        
          if(!s.empty()){
            v.push_back(s);
        }
        
        cout << v.size() << endl;
        
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << endl;
        }
    }
    return 0;
}