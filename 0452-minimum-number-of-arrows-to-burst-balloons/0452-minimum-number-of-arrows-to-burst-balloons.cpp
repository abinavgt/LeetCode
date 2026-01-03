class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.empty()) return {};
        int n = points.size();
        //the condition sorts , the ooder according to index 1 position
        sort(points.begin(),points.end(),[](const vector<int> &x,const vector<int> &y){
            return x[1]<y[1];
        });

        int currentend = points[0][1];
        int count = 1; 
        for(int i=1;i<n;i++){
            if(points[i][0] > currentend){
                count++;
                currentend = points[i][1];
            }
        }
        return count;
    }
};