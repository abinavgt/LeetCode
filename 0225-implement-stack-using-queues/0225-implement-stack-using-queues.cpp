class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) { //O(n) - Reallocating all the elements in existing push function in each loop
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {//O(1)
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {//O(1)
        return q1.front();
    }
    
    bool empty() {//O(1)
        return q1.empty();
    }
};

//SC : O(n) we used two queue , q1 auxiliary spaces , but q2 temporary storage

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */