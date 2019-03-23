void Merge(vector<int> &array, int l, int m, int r) {
    int  *tmp = new int[r-l+1];
    int i = l, j = m+1, k = 0;
    while(i <= m && j <= r) {
        if(array[i] <= array[j]) {
            tmp[k++] = array[i++];
        } else {
            tmp[k++] = array[j++];
        }
    }
    while(i <= m) {
        tmp[k++] = array[i++];
    }
    while(j <= r) {
        tmp[k++] = array[j++];
    }
    for(int i = 0; i < k; i ++) {
        array[l + i] = tmp[i];
    }
    delete [] tmp;
}

void MergeSort(vector<int> &array, int start, int end) {
    if(start >= end) return;
    int l = start, r = end, m = (start+end)/2;
    MergeSort(array, l, m);
    MergeSort(array, m+1, r);
    Merge(array, l, m, r);
}

