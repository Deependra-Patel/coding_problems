#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0; i<n; i++)
		arr[i] = 0;
	vector<int> arrI;
	for(int  i=0; i<n; i++){
		int t;
		cin>>t;
		arrI.push_back(t);
		if(t<=n)
			arr[t-1]++;
	}
	int index = 0;
	for(int i=0; i<n; i++){
		int x = arrI[i];
		if(x<=n && arr[x-1] == 1)
			cout<<x<<" ";
		else {
			if(x<=n)
				arr[x-1]--;
			while(arr[index]!=0){
				index++;
			}
			cout<<index+1<<" ";
			index++;
		}		
	}
}
