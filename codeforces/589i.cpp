#include <iostream>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	int x = n/k;
	int* cnt = new int[k];
	for(int i=0; i<k; i++) cnt[i] = 0;
	int sum = 0;
	for(int i=0; i<n; i++){
		int color;
		cin>>color;
		cnt[color-1]++;
		if(cnt[color-1]>x){
			sum++;
		}
	}
	cout<<sum<<endl;
}
