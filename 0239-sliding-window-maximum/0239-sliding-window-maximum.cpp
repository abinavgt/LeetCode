class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;

        //for the 1st window , checking out the presence of deque
        for(int i=0;i<k;i++){ //dq.front() holds the max value 
            while(dq.size()>0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            
            // it removes not part of curr window
            while(dq.size()>0 && dq.front() <= i-k){
                dq.pop_front();
            }

            //Removes the smaller value
            while(dq.size()>0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};