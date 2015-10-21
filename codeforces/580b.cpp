#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
struct friends{
	int m, f;
	bool operator<(friends* fr){
		return m<fr->m;
	}
	void print(){
		cout<<m<<" "<<f<<endl;
	}
};

bool cmp(friends * fr1, friends* fr2){
	return fr1->m<fr2->m;
}
int main(){
	int  n, d;
	cin>>n>>d;
	friends** frs = new friends*[n];
	for(int i=0; i<n; i++){
		frs[i] = new friends();
		cin>>frs[i]->m>>frs[i]->f;
	}
	sort(frs, frs+n, &cmp);
	long long curSum = frs[0]->f;
	int i=0;
	int j = 1;
	long long ans = curSum;
	//	for(int i=0; i<n; i++)
	//	frs[i]->print();
	while(i<n && j<n){
		if(frs[j]->m - frs[i]->m < d){
			curSum += frs[j]->f;
			j++;
			ans = max(ans, curSum);
		}
		else {
			curSum -= frs[i]->f;
			i++;
		}
	}
	cout<<ans<<endl;
}
