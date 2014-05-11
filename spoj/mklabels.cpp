#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,counter=1;
	cin>>n;
	while(n!=0){
		long long ans=(long long)pow(n, n-2);
		cout<<"Case "<<counter<<", N = "<<n<<", # of different labelings = "<<ans<<endl;
		cin>>n;
		counter++;
	}
}
