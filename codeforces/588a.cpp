#include <iostream>
#include <vector>
using namespace  std;
int main(){
	int n;
	cin>>n;
	vector<int> a, p;
	for(int i=0; i<n ;i++){
		int a1, p1;
		cin>>a1>>p1;
		a.push_back(a1);
		p.push_back(p1);
	}
	int sum = 0;
	int mini = 10000000;
	for(int i=0; i<n; i++){
		mini = min(mini, p[i]);
		sum += a[i]*mini;
	}
	cout<<sum<<endl;
}
