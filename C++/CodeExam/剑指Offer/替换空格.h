class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len1 = strlen(str), len2 = 0;
        for(int i = 0; i < len1; i ++) {
            len2++;
            if(str[i] == ' ') len2 += 2;
        }
        for(int i = len1-1, j = len2-1; i >= 0; i --, j--) {
            if(str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j] = '%';
            } else {
                str[j] = str[i];
            }
        }
        str[len2] = '\0';
	}
};