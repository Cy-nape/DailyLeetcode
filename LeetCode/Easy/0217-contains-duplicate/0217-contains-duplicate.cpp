class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freqMap; 
        for (int num : nums) { 
            if(freqMap[num]==1){ 
                return true; 
            } 
            freqMap[num]++; 
        } 
        return false;

    }
};