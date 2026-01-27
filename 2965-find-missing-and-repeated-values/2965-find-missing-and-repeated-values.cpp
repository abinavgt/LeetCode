class Solution{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid){
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int actualsum =0;
        int duplicate =-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                int val = grid[i][j]; // points out the elemnent
                actualsum += val;

                if(s.count(val)){
                    duplicate = val;
                }
                s.insert(val);
            }
        }
        int expectedsum = (n*n) * (n*n+1)/2;
        int missing = expectedsum -(actualsum - duplicate);
        return {duplicate,missing};
    }
};
// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
//         vector<int> ans;
//         unordered_set<int> s;
//         int n = grid.size();
//         int a,b;
//         int expsum = 0,actualsum = 0;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 actualsum += grid[i][j];

//                 if(s.find(grid[i][j]) != s.end()){
//                     a = grid[i][j];
//                     ans.push_back(a);
//                 }
//                 s.insert(grid[i][j]);
//             }
//         }
//         expsum = (n*n) *(n*n +1)/2;
//         b = expsum +a - actualsum;
//         ans.push_back(b);
//         return ans;
//     }
// };