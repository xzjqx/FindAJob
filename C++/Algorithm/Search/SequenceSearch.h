int SequenceSearch(vector<int> array, int key) {
    for(int i = 0; i < array.size(); i ++) {
        if(key == array[i])
            return i;
    }
    return -1;
}