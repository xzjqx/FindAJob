vector<int> InsertSort(vector<int> array) {
    int len = array.size();
    for(int i = 1; i < len; i ++) {
        int key = array[i], pos = i;
        for(int j = i; j > 0; j --) {
            if(key < array[j-1]) {
                pos = j-1;
                array[j] = array[j-1];
            } else {
                break;
            }
        }
        if(pos != i) {
            array[pos] = key;
        }
    }
    return array;
}