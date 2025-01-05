#include<iostream>
#include<algorithm>
using namespace std;

struct job {
  int id;
  int profit;
  int deadline;

};
bool compare (job a , job b){
  return a.profit > b.profit;
}
int main() {
  int n=5;
  job jobs[]={{1,20,2},{2,15,2},{3,10,1},{4,5,3},{5,1,3}};

  sort (jobs , jobs + n , compare);
  int slots [n]={0};
  int totalprofit = 0;
  int result[n]={-1};

  for (int i=0;i<n;i++){
    for (int j=min(n,jobs[i].deadline) -1;j>=0;j--){
      if (slots [j]==0){
        slots[j]=1;
        result[j]=jobs[i].id;
        totalprofit += jobs[i].profit;
        break;
        }
        }
        }
        cout <<"Scheduled Jobs: ";
        for (int i=0;i<n;i++){
          if (result[i] != -1){
            cout<<"j" <<result[i]<<" ";
            }
            }
            cout<< "\nTotal Profit: "<<totalprofit<<endl;
            return 0;
}