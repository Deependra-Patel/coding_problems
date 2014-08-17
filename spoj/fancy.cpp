#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
  int ntest;
  cin>>ntest;
  while(ntest--){
    string s;
    cin>>s;
    int power=0;
    int len=1;
    char older=s[0];
    for(int i=1; i<s.length(); i++){
      if(s[i]==older){
	len++;
      }
      else {
	power+=len-1;
	older=s[i];
	len=1;
      }
    }
    power+=len-1;
    cout<<pow(2,power)<<endl;
  }
}
  
  
