class Solution {
public:
    vector<int> m;
    int mi = INT_MAX;
    vector<int> stack;
    void push(int value) {
        stack.push_back(value);
        if(value <= mi) {
            mi = value;
            m.push_back(stack.size()-1);
        }
    }
    void pop() {
        if(stack.size()-1 == m[m.size()-1]) {
            m.pop_back();
            mi = stack[m[m.size()-1]];
        }
        stack.pop_back();
    }
    int top() {
        return stack[stack.size()-1];
    }
    int min() {
        return mi;
    }
};