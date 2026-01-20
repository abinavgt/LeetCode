class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,-1); //we can initialize to -1 or 0
        stack<int> s;

        for(int i=2*n;i>=0;i--){
            while(s.size()>0 && nums[s.top()] <=nums[i%n]){
                s.pop();
            }
            ans[i%n] = s.empty() ? -1:nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};

//TC : O(n), SC : O(n)
