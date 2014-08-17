#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int temp=n%10;
  if(temp==0)
    cout<<2<<endl;
  else {
    cout<<1<<endl<<temp<<endl;
  }
}
