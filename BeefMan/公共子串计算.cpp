

// 计算两个字符串的最大公共字串的长度，字符不区分大小写







#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    while(cin>>str1>>str2){
         int len1=str1.length(),len2=str2.length(),cnt,maxt=0,k;
    for(int i=0;i<len1;i++){
         for(int j=0;j<len2;j++){k=0,cnt=0;
            while(str1[i+k]==str2[j+k]&&i+k<=len1&&j+k<=len2){
                    cnt++;k++;
                }if(maxt<cnt) maxt=cnt;
         }
         if(maxt==min(len1,len2)) break;
    }
    cout<<maxt<<'\n';
    }
    return 0;
}