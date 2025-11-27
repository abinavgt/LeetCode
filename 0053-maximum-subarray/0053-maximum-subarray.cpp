class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentsum = 0;
        int maxsum = INT_MIN;

        for(int val : nums){

            currentsum = currentsum + val;
            maxsum = max(currentsum,maxsum);

            if(currentsum<0){
                currentsum = 0;
            }
        }
        return maxsum;
    }
};