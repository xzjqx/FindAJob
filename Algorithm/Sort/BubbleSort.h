vector<int> BubbleSort(vector<int> array) {
    int len = array.size();
    for(int i = 0; i < len; i ++) {
        for(int j = i+1; j < len; j ++) {
            if(array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    return array;
}