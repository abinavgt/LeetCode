class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int value = 0;

        for(int bit: nums){
            value = (value*2 + bit) % 5;  
            // 011, value = 0 [0*2+0] = 0 %5 == 0 divisible by 5
            // Now value is 0 [0*2+1] = 1%5 == 1 not divisible by 5,so it returns  value 1 itself
            // Now value is 1 [1*2+1] = 3&5 == 3 not divisible 
            ans.push_back(value==0);
        }
        return ans;
    }
};