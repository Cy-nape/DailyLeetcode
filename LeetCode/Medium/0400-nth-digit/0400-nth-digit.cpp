class Solution {
public:
    int findNthDigit(int n) {
        int numdigit = 1;
        int digitcount = 9;
        while(1ll * numdigit * digitcount < n){
            n -= numdigit * digitcount;
            ++numdigit;
            digitcount *= 10;
        }

        int number = pow(10, numdigit-1) + (n-1)/numdigit;

        int indexnumber = (n-1)%numdigit;

        string numberstr = to_string(number);
        return numberstr[indexnumber]-'0';
    }
};