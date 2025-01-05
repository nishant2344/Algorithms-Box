#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int files[]={2,3,7,5};
    int n=4;
    int totalcost=0;

    sort(files,files+n);

    for (int i=0;i<n-1;i++) {
        int mergecost=files[i] + files[i+1];
        totalcost+=mergecost;
        files[i+1]=mergecost;
        sort(files,files+n);
    }
    cout<<"Minimum cost to merge all files:- "<<totalcost <<endl;
    return 0;
}
