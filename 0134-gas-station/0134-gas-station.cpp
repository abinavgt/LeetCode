class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalGas =0,totalCost =0;
        for(int val:gas){
            totalGas += val;
        }
        for(int val:cost){
            totalCost += val;
        }
        if(totalGas < totalCost){
            return -1;
        }
        // the core logic we compare the gas and cost
        int st =0 , currentGas =0;
        for(int i=0;i<gas.size();i++){
            currentGas += gas[i] - cost[i];

            if(currentGas < 0){
                st = i+1;
                currentGas =0;
            }
        }
        return st; //which returns the index position
    }
};