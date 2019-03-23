class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()) {
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int node = stack2.top();
        stack2.pop();
        while(!stack2.empty()) {
            int tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};