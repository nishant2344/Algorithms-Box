#include <iostream>
using namespace std;

// Selection sort function with tracking of swaps and comparisons
void selectionSort(int arr[], int n, int &swapCount, int &comparisonCount) {
    for (int i = 0; i < n - 1; i++) {  // Outer loop runs from 0 to n-2 (one less than size)
        int bigindex = i;  // Assume the first element is the largest in the unsorted part
        for (int j = i + 1; j < n; j++) {  // Inner loop goes through the unsorted part
            comparisonCount++;  // Count each comparison
            if (arr[j] > arr[bigindex]) {  // Find the largest element in the unsorted part
                bigindex = j;  // Update index of the largest element
            }
        }
        // Swap the largest element with the last element of the unsorted part
        if (bigindex != i) {  // Only swap if needed (if bigindex changed)
            swap(arr[bigindex], arr[n - i - 1]);
            swapCount++;  // Count each swap
        }
    }
}

int main() {
    int n;

    // Prompt user for the number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;  // Get the number of elements from the user

    int arr[n];  // Declare the array with the user-specified size

    // Prompt user to input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Take input from the user for each element of the array
    }

    int swapCount = 0, comparisonCount = 0;  // Variables to track swaps and comparisons
    selectionSort(arr, n, swapCount, comparisonCount);  // Call selection sort

    // Output the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Output the total number of swaps and comparisons
    cout << "Total swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;  // Return success code
}
