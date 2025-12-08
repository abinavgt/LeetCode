

class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        string ans = "";

        int i = n - 1;
        while(i >= 0 && num[i] == '0') i--;  

        for(int j = 0; j <= i; j++){
            ans.push_back(num[j]);
        }

        return ans;
    }
};