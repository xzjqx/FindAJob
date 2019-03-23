class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.length() == 0) return ans;
        char *s = (char*)str.c_str();
        sort(s, s+strlen(s));
        do {
            ans.push_back(str);
        } while(next_permutation(s, s+strlen(s)));
        return ans;
    }
};