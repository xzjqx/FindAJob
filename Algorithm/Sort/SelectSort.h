vector<int> SelectSort(vector<int> array) {
    int len = array.size();
    for(int i = 0; i < len; i ++) {
        int key = array[i], min_pos = i;
        for(int j = i+1; j < len; j ++) {
            if(key > array[j]) {
                min_pos = j;
                key = array[j];
            }
        }
        if(i != min_pos) {
            array[min_pos] = array[i];
            array[i] = key;
        } 
    }
    return array;
}