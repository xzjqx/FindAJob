class Solution {
public:
    bool verify(vector<int> s, int start, int end) {
        if(start >= end) return true;
        int i = end-1;
        while(i >= start && s[end] < s[i]) i --;
        for(int j = start; j <= i; j ++) {
            if(s[j] > s[end]) return false;
        }
        return verify(s, start, i) && verify(s, i+1, end-1);
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return verify(sequence, 0, sequence.size()-1);
    }
};