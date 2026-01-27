class Solution {
public:
    int squares(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10; 
            sum += digit*digit;
            n /= 10; 
        }
        return sum;
    }
    bool isHappy(int n) {
        // the squares still goes on so we use ' Floyd Cycle Detection' also called slow fast approach
        
        int slow = n;
        int fast = n;
        do{
            slow = squares(slow);
            fast = squares(squares(fast));
        }while(slow != fast);
        //Time limit will be exceeded when it is infinte loop
        return slow ==1;
    }
};