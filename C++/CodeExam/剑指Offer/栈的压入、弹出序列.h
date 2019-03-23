class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        s.push(pushV[0]);
        int k = 0;
        for(int i = 1; i < pushV.size(); i ++) {
            if(s.top() == popV[k]){
                k ++;
                s.pop();
                s.push(pushV[i]);
            } else if(pushV[i] == popV[k]) {
                k ++;
            } else {
                s.push(pushV[i]);
            }
        }
        while(!s.empty()) {
            if(s.top() != popV[k]) {
                break;
            }
            s.pop();
            k ++;
        }
        if(k != popV.size()) 
            return false;
        else 
            return true;
    }
};