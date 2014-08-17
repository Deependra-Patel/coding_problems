#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int a, b;
  cin>>a>>b;
  while(a!=-1 && b!=-1){
    int temp;
    if(a>b){
      temp=b;
      b=a;
      a=temp;
    }
    int ans;
    ans=max(a,b);
    if(a*b==0){
      cout<<ans<<endl;
      cin>>a>>b;
      continue;
    }
    for(int i=0; i<=b; i++){
      double x=b-i;
      if(b-i>=a){
      	int temp=ceil(x/a);
      	int tans=max(i,temp);
      	ans=min(tans, ans);
      }
      else break;
    }

    cout<<ans<<endl;
    cin>>a>>b;
  }
}
