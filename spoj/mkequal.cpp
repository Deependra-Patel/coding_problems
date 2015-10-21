#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long sum = 0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			sum += x;
		}
		if(sum%n != 0)
			cout<<n-1<<endl;
		else cout<<n<<endl;
	}
}
