class Solution {
public:
    void merge(vector<int> &arr,int start,int mid,int end){
        int i = start,j=mid+1;
        vector<int> temp; //Stores the new sorted array

        while(i<=mid && j<=end){ // MERGE SORT 
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){   // Left elements 
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end){   // Rigth elements
            temp.push_back(arr[j]);
            j++;
        }
        for(int index = 0;index<temp.size();index++){
            arr[index+start] = temp[index];
        }
    }

    void mergesort(vector<int> &arr,int start,int end){
        if(start<end){
            int mid = start+(end-start)/2;
              
            mergesort(arr,start,mid); // For the left cut
            mergesort(arr,mid+1,end); //For the Rigth cut

            merge(arr,start,mid,end); // Calls the function
        }
    }
    vector<int> sortArray(vector<int>& arr) {
        
        mergesort(arr,0,arr.size()-1);
        return arr;
    }
};