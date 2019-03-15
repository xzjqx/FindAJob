void swap(vector<int> &array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int partition(vector<int> &array, int left, int right) {
    int pos = left, index = pos + 1;
    for(int i = index; i <= right; i ++) {
        if(array[i] < array[pos]) {
            swap(array, i, index);
            index ++;
        }
    }
    swap(array, pos, index - 1);
    return index - 1;
}

vector<int> QuickSort(vector<int> array, int left, int right) {
    if(left < right) {
        int pos = partition(array, left, right);
        array = QuickSort(array, left, pos - 1);
        array = QuickSort(array, pos + 1, right);
    }
    return array;
}