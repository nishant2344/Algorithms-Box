#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalknapsack(int W, struct Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        } else {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main() {
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalknapsack(W, arr, n) << endl;
    return 0;
}
