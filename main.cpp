#include "include.h"

int main()
{
    vector<int> array {4, 3, 6, 1, 9};
    for(int i = 0; i < array.size(); i ++) {
        cout << array[i] << " ";
    }
    cout << endl;
    array = InsertSort(array);
    for(int i = 0; i < array.size(); i ++) {
        cout << array[i] << " ";
    }
    return 0;
}