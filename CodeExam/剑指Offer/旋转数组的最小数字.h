class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        for(int i = 1; i < rotateArray.size(); i ++)
            if(rotateArray[i] < rotateArray[i-1])
                return rotateArray[i];
        return rotateArray[0];
    }
};