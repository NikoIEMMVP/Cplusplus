// 给定一个长度不小于2的数组arr。 写一个函数调整arr，
// 使arr中要么所有的偶数位上都是偶数，要么所有的奇数位上都是奇数上。 
// 要求：如果数组长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1),
// 下标0,2,4,6...算作偶数位,下标1,3,5,7...算作奇数位，例如[1,2,3,4]调整为[2,1,4,3]即可
#include <algorithm>
class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        for(int i = 0, j = 1; i < len && j < len; ){
            if((arr[i] % 2) == 0){
                i += 2;
                continue;
            }
            if((arr[j] % 2) == 1){
                j += 2;
                continue;
            }
            
            if(i < len && j < len){
                swap(arr[i], arr[j]);
            }
            
            i+=2;
            j+=2;
        }
    }
};