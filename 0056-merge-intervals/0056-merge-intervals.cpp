class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if(intervals.empty()) return{};
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]); //pushing the first interval

        for(int i=1;i<n;i++){ 
            //here the back returns the interval , which was merged last in list
            vector<int> &mergedinterval = result.back(); //now [1,3]
            if(intervals[i][0] <= mergedinterval[1]){
                mergedinterval[1] = max(mergedinterval[1],intervals[i][1]);
            } else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

//TC : O(nlogn) --> sorting and for loop
//SC : O(logn) --> recursive call satck