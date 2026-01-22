class Solution {
public:
    int myAtoi(string s) {
        
        int i =0;
        int n = s.size();
        while(i<n && s[i]==' ') i++; //Removing trailing zeroes
        
        //For handling the sign 1 or + and -1 for -
        int sign = 1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }

        //Parsing loop , stops when the string is char or any 
        int result =0;
        while(i<n && isdigit(s[i])){ //Checks the character int('0'-'9')
            int digit = s[i]-'0'; //converts the char to int

            if(result> (INT_MAX-digit)/10){ //contorls the overflow , the limit shoudl not be exceeded
                return sign ==1? INT_MAX:INT_MIN;
            }
            result = result*10 + digit;   
            i++;         
        }
        return result*sign;
    }
};