// https://leetcode.com/problems/min-stack/description/
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;

    MinStack() {
    }
    
    void push(int val) {
        // push min value for this element in the minStack
        if(s1.empty()){
            s2.push(val); 
        }else{
            if(val<s2.top()){
                s2.push(val);
            }else{
                s2.push(s2.top());
            }
        }
        s1.push(val);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

// Optimize -> we don't need to push minimum answer for each element just push on each update and pop if that element is removed
// IMP : push also incase current value = current min since we need to handle duplicates
// 0,1,0 if we remove last 0 then our 1st 0 will also be removed from our min stack 
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;

    MinStack() {
    }
    
    void push(int val) {
        // push min value for this element in the minStack
        if(s1.empty()){
            s2.push(val); 
        }else{
            if(val<=s2.top()){
                s2.push(val);
            }else{
                // no need
                //s2.push(s2.top());
            }
        }
        s1.push(val);
    }
    
    void pop() {
        int removedElement = s1.top();
        s1.pop();

        if(removedElement == s2.top()){
            s2.pop(); // this can't be ans anymore
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

// Improved
class MinStack {
public:
    stack<int> minStack;
    stack<int> elementStack;

    MinStack() {
        
    }
    
    void push(int val) {
        elementStack.push(val);

        if(minStack.empty() || val<=minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(elementStack.top()==minStack.top()){
            minStack.pop();
        }
        elementStack.pop();
    }
    
    int top() {
        return elementStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};