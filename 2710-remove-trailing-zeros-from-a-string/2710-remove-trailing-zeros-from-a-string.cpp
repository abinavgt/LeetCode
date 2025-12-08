class Solution {
public:
    string removeTrailingZeros(string nums) {
        
        int n = nums.size();
        int i = n-1;

        while(i>=0 && nums[i]=='0'){
            i--;
        }
        string output = ""; //creates an empty string ,where the final answer is stored
        for(int j=0;j<=i;j++){
            output.push_back(nums[j]);
        }
        return output;
    }
};