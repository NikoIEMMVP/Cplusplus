// 有一金额出现的次数大于一半，找到那个数字
// 若有这个数字 返回这个数字
// 若没有 返回0
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(gifts.size() < n)
            return 0;
        if(gifts.size() == 0)
            return 0;
        
        sort(gifts.begin(), gifts.end());
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(gifts[i] == gifts[n / 2]){
                count ++;
            }
        }
        
        if(count > n / 2)
            return gifts[n / 2];
        else 
            return 0;
    }
};