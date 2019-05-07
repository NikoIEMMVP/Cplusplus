// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。


//思路：反转一半的数字//

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 || (x % 10 == 0 && x != 0))
           return false;
        
        int reverseNumber = 0;
        while(x > reverseNumber){
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }
        
       if(x == reverseNumber || x == reverseNumber / 10)
           return true;
        
        return false;
        
    }
};