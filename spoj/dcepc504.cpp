#include <iostream>
#include <math.h>
using namespace std;
bool calc(int n, int k){
	if(k == 1 && n == 1)
		return true;
	int l = ceil(log2(k));
	if(l<n-1){
		//	cout<<"here"<<l<<endl;
		return calc(n-1, k);
	}	
	bool val = calc(n-1, k - pow(2, (int)log2(k-1)));
	return !val;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		if(calc(n, k))
			cout<<"Male"<<endl;
		else cout<<"Female"<<endl;
	}
}
