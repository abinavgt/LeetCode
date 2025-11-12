class Solution {
public:
    string intToRoman(int num) {
       
       // String the values
       vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
       vector<string> alphabets = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
       
       string answer = ""; // Stores the final alphabet
       for(int i=0;i<values.size();i++){
            while(num >= values[i]){  // Checks whether num = {values-values};
                num -= values[i];  
                answer += alphabets[i]; // Stores the final string 

            }
       }
       return answer;
    }
};