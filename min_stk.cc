stack<long long> stk;
     long long min ;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(stk.size()==0){
            stk.push(x);
            min = x;
        }else{
            if(x >= min){
                stk.push(x);
            }else{
                stk.push((long long)x+(long long)x-min);
                min = x;
            }
        }
            
    }
    
    void pop() {
        if(stk.size()){
            if(stk.top()>=min){
                stk.pop();
            }else{
                min = min+min - stk.top();
                stk.pop();
            }
        }
    }
    
    int top() {
        if(stk.size()){
            if(stk.top()>=min) return (int)stk.top();
            else{
                return (int)min;
            }
        }else{
            return -1;
        }
    }
    
    int getMin() {
        return (int)min;
    }
