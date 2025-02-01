// https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // transfer from q1 to q2 till q1 size becomes 1
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        // now return front of q1
        int ans=q1.front();
        q1.pop();

        // swap q1 and q2
        swap(q1,q2);

        return ans;
    }
    
    int top() {
        // transfer from q1 to q2 till q1 size becomes 1
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        // now store front of q1
        int ans=q1.front();

        // push it to q2 as well
        q2.push(q1.front());
        q1.pop();

        // swap q1 and q2
        swap(q1,q2);

        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};