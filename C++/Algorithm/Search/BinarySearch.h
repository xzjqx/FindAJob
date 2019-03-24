int BinarySearch(vector<int> array, int key) {
    int left = 0, right = array.size()-1;
    int mid;
    while(left <= right) {
        mid = (left+right) / 2;
        if(array[mid] == key) return mid;
        else if(array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}