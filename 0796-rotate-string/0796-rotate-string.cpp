class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length() != goal.length()) return false;
        return (s+s).find(goal) != string::npos; //std::string::npos refers there is no valid index
    }
    //Manual rotation can be done , but the complexity will be O(n2)
    //s = s.substr(1) + s[0]
};

//TC -- O(n) & SC -- O(n)