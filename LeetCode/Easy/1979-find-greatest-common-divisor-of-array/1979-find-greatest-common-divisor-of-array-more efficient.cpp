class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = *min_element(nums.begin(), nums.end());
        int m = *max_element(nums.begin(), nums.end());

        while (s > 0) {
            int temp = s;
            s = m % s;
            m = temp;
        }
        return m;
    }
};