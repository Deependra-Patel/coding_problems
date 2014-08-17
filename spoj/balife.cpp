#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int n;
  while(n!=-1){
    int* arr=new int[n];
    int sum=0;
    for(int i=0; i<n; i++){
      cin>>arr[i];
      sum+=arr[i];
    }
    if(sum%n!=0)
      cout<<-1<<endl;
    else {
      int avg=sum/n;
      int ans=0;
      int tmp_sum=0;
      for(int i=0; i<n; i++){
	


      }
    }
    cin>>n;
  }
}
