class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> result;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int start = nums[i];
            // (i+1<n) here it checks the next element that less than nums lenght
            while(i+1<n && nums[i]+1 == nums[i+1]){ //Index Out of Bound Exception
                i++;
            }
            if(start == nums[i]){ 
                result.push_back(to_string(start));
            } else{ 
                result.push_back(to_string(start) +"->"+ to_string(nums[i]));
            }
        }
        return result;
    }
};