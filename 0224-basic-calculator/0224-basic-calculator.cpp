class Solution {
public:
    int calculate(string s) {
        
        //Basic Calculator Theory 
        long long int sum =0;
        int sign = 1; // This sign detrmine whether +1 or -1 depends on operation
        stack<pair<int,int>> st; //Stores the sum and sign;

        for(int i=0;i<s.size();i++){
            //Initially we are checking string belong to integer or not '0 to 9'
            long long int num =0;
            if(isdigit(s[i])){
                while(s.size()>0 && isdigit(s[i])){
                    num = num * 10 + ((s[i])-'0'); //This coverts string to integer
                    i++;
                }
                //After checking , if it is integer then it performs the calculation
                i--; //again starts from index 0
                sum += num*sign;
                sign =1; //again reset sign to 1
            }
            else if(s[i]=='-'){
                sign = -1*sign;
            }
            else if(s[i]=='('){
                st.push({sum,sign});
                sum =0; //Reset values to the default, checks the cal inside the brackets
                sign =1;
            }
            else if(s[i]==')'){
                sum = st.top().first + st.top().second * sum;
                st.pop();
                // Here the st.top().first() is value stored in stack and second is ootside
            }
        }
        return sum;

    }
};