#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int files[]={6,5,2,3};
    int n=4;
    int totalcost=0;

    sort(files,files+n);

    for (int i=0;i<n-1;i++) {
        int mergecost=files[i] + files[i+1];
        totalcost+=mergecost;
        files[i+1]=mergecost;
        sort(files+i+1,files+n);
    }
    cout<<"Minimum cost for Huffman coding :- "<<totalcost <<endl;
    cout<<"Table Huffman coding :- "<<n*8 <<endl;
    return 0;
}
