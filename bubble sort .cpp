#include<iostream>
using namespace std ;

void bubbleSort(int arr[], int n,int &swapCount, int &comparisonCount) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++) {
            comparisonCount++;
            if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int swapCount = 0, comparisonCount = 0;
    bubbleSort(arr, n, swapCount, comparisonCount);


    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout << "Total swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;
}
