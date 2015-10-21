#include <iostream>
using namespace  std;
int main(){
	int n;
	cin>>n;
	int* a1 = new int[n-1];
	int* a2 = new int[n-1];
	int* pre1 = new int[n];
	int* post2 = new int[n];
	int* b = new int[n];
	pre1[0] = post2[n-1] = 0;
	for(int i=0; i<n-1; i++){
		cin>>a1[i];
	}
	for(int i=0; i<n-1; i++){
		cin>>a2[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	for(int i=1; i<n; i++){
		pre1[i] = pre1[i-1] + a1[i-1];
		int j = n-i-1;
		post2[j] = post2[j+1] + a2[j];
		//cout<<post2[j]<<" ";
	}
	int ans = 999999999;
	for(int i=0; i<n; i++){
		int p1 = b[i] + pre1[i] + post2[i];
		//cout<<p1<<" ";
		for(int j=0;j<n; j++){
			if(i == j)
				continue;
			int p2 = b[j] + pre1[j] + post2[j];
			ans = min(ans, p1+p2);
		}
	}
	cout<<ans<<endl;
}
