class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        if(n==0) return 0;

        vector<int> candies(n,1);
        //Left->Right Traversal
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        int count = candies[n-1]; //Initially in 1 candy
        //Rigth->Left Traversal
        for(int i =n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candies[i-1] = max(candies[i]+1,candies[i-1]);
            }
            count += candies[i-1]; // Counting the candy from the last(modiefied)
        }
        return count;
    }
};