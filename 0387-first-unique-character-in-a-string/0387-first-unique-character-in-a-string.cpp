class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> mp;
        queue<int> q;

        for(int i=0;i<s.size();i++){
            //mp.find(s[i]) != mp.end() is when the char is alrady exist(update/store)
            
            if(mp.find(s[i]) == mp.end()){ //used for finding the first occurence
                q.push(i); //it just pushes the index 
            }
            mp[s[i]]++; 
            while(q.size()>0 && mp[s[q.front()]]>1){
                q.pop();
            }
        }
        return q.empty() ? -1:q.front();
    }
};