// https://leetcode.com/problems/implement-queue-using-stacks/description/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int topEle=s2.top();
            s2.pop();
            return topEle;
        }


        while(!s1.empty()){
            int topEle=s1.top();
            s1.pop();
            s2.push(topEle);
        }

        int topEle=s2.top();
        s2.pop();
        return topEle;
    }
    
    int peek() {
        if(!s2.empty()){
            int topEle=s2.top();
            return topEle;
        }


        while(!s1.empty()){
            int topEle=s1.top();
            s1.pop();
            s2.push(topEle);
        }

        int topEle=s2.top();
        return topEle;
    }
    
    bool empty() {
        if(!s2.empty() || !s1.empty()){
            return false;
        }
        return true;
    }
};