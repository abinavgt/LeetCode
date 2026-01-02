class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        int i=0;
        int n = intervals.size();
        //Inserting the intervals that are before the newInterval
        while(i<n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        //Merge logic
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        result.push_back(newInterval);
        //After the merge insertion
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
//TC: O(n) 
//SC: O(1) No extra space , we used only auxiliary vector