class Solution {
public:
    string removeTrailingZeros(string nums) {
        
        int n = nums.size();
        int i = n-1;
        while(i >= 0 && nums[i]=='0'){
            i--; // Now the lasr index changes 
        }
        string output = ""; //creates an empty string
        for(int j=0;j<=i;j++){
            output.push_back(nums[j]);
        }
        return output;
    }
};