class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        //int sign = x<0 ? -1:1;
        //x = abs(x);
        while(x!=0){
            int digit = x%10;
            reversed = reversed *10 + digit;
            x/=10; 
        }
        //reversed *= sign;
        if(reversed< INT_MIN || reversed>INT_MAX){
            return 0;
        }

        return (int)reversed;
    }
};