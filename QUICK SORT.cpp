#include <iostream>
using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void Quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        Quicksort(arr, low, pi - 1);
        Quicksort(arr, pi + 1, high);
    }
}

int main() {
    int l;
    cout << "Enter the length of the array: ";
    cin >> l;

    int arr[l];
    cout << "Enter the array elements: ";
    for (int i = 0; i < l; i++) {
        cin >> arr[i];
    }

    Quicksort(arr, 0, l - 1);

    cout << "Quick Sorted array: ";
    for (int i = 0; i < l; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
