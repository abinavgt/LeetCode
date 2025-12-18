class Solution {
public:
    int calculate(string s) {
        
        int n = s.size();
        long long int sum =0;
        int sign = 1; //this can be +1 or -1 either ,depends on the opeartion
        stack<pair<int,int>>st;

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){ //if the string is integer from '0 to 9'
                long long int num =0;
                while(s.size()>0 && isdigit(s[i])){

                    num = num * 10 +(s[i] - '0'); //here the 's[i]-0' this converts string to integer 
                    i++;
                }
                i--;
                sum += num*sign;
                sign =1;
            }
            else if(s[i]=='-'){
                sign = -1*sign;
            }
            else if(s[i] =='('){
                st.push({sum,sign});
                sum =0;
                sign =1;
            }
            else if(s[i]==')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }
        }
        return sum;
    }
};