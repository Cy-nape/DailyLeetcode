class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo = 0;
        int hi = sqrt(c);

        while (lo <= hi) {
            long long sum = (long long)lo * lo + (long long)hi * hi;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                lo++;
            } else {
                hi--;
            }
        }

        return false;
    }
};