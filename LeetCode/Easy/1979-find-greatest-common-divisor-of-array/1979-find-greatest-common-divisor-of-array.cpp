class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = nums[0];
        int m = nums[nums.size()-1];
        if(s==0) return m;
        if(m%s==0){
            return s;
        }
        for(int i = s; i>0;i--){
            if(s % i == 0 && m % i == 0){
                return i;
            }
        }
        return 0;
    }
};