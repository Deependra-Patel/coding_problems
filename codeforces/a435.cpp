#include <iostream>
#include <string>
using namespace std;
int main(){
	int m, n;
	cin>>n>>m;
	int count=0;
	int temp=0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		temp+=x;
		if(temp>m){
			temp=x;
			count++;
		}
	}
	if(temp!=0)
		count++;
	cout<<count<<endl;
}