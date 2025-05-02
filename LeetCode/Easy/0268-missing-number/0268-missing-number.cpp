class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // resubmission to test extension
        int n = nums.size()+1;
        int numsum = 0;
        for(int i=0;i<nums.size();i++){
            numsum += nums[i];
        }
        int orgsum= (n*(n-1)/2);
        return orgsum-numsum;
    }
};