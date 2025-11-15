class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int start =0;
        int end = nums.size()-1;
        
        // Basically this peak element should be greater than the neighbours so,
        while(start<end){
            int mid = start + (end - start)/2;
            if(nums[mid]<nums[mid+1]){
                start = mid +1; 
            }
            else{
                end = mid; 
            }
        }
        return start; // Here the we can return either start or end
        //start == end (Peak Element) 
    }
};