// https://leetcode.com/problems/basic-calculator-ii/description/

// When we have + or - we push it as it to stack (For - push -num)
// When we have * or / we take top element from stack and do the operation
// At last we add all elements on stack
class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int currentNumber = 0;
        char currentOperation = '+'; 
        
        for (char c : s+'+') { // Append '+' to process last number
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            } else if (!isspace(c)) { // Operator encountered
                if (currentOperation == '+') {
                    stack.push(currentNumber);
                } else if (currentOperation == '-') {
                    stack.push(-currentNumber);
                } else if (currentOperation == '*') {
                    int num = stack.top() * currentNumber;
                    stack.pop();
                    stack.push(num);
                } else if (currentOperation == '/') {
                    int num = stack.top() / currentNumber;
                    stack.pop();
                    stack.push(num);
                }
                
                currentOperation = c;
                currentNumber = 0;
            }
        }
        
        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};
