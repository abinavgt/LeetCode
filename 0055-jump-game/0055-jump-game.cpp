class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int goal = nums.size()-1; 
        // backward greedy is optimized and clean
        for(int i =nums.size()-1;i>=0;i--){

            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal ==0;
    }
};