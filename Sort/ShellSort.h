vector<int> ShellSort(vector<int> array) {
    int len = array.size();
    for(int gap = len/2; gap > 0; gap /= 2) {
        for(int i = gap; i < len; i ++) {
            int j = i, tmp = array[i];
            while(j-gap >= 0 && tmp < array[j-gap]) {
                array[j] = array[j-gap];
                j -= gap;
            }
            array[j] = tmp;
        }
    }
    return array;
}