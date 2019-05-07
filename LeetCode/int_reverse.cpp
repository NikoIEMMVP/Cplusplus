//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

class Solution {
public:
    int reverse(int x) {
        vector<int> v;
        long int sum = 0;
        int yushu = 0;
        
        while(x){
            yushu = x % 10;
            v.push_back(yushu);
            x /= 10;
        }
        
        for(auto vit = v.begin(); vit != v.end(); vit++){
            sum = *vit + sum*10;
        }
        
        if(sum > 2147483647 || sum < -2147483648){
            return 0;
        }
        
        return sum;
    }
};