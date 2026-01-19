class Solution {
public:
    int vowelConsonantScore(string s) {
        
        int vowel =0;
        int consonant =0;
        for(char ch:s){
            if(ch>='a' &&ch<='z'){ 
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    vowel++;
                }else{
                    consonant++;
                }
            }
        }
        if(consonant==0) return 0;
        return vowel/consonant;
    }
};