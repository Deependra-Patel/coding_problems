#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct par{
	int index;
	int marks;
};
bool cmp(par p1, par p2){
	return p1.marks<p2.marks;
}
int main(){
	int n, m;
	cin>>n>>m;
	par* all = new par[n];
	for(int i=0; i<n; i++){
		par temp;
		cin>>temp.marks;
		temp.index = i+1;
		all[i] = temp;
	}
	sort(all, all+n, &cmp);
	for(int i=n-1; i>=0; i--){
		cout<<all[i].index<<" "<<all[i].marks<<endl;
		}
	for(int i=0; i<m; i++){
		int a, b;
		int sum = 0;
		int cnt = 0;
		scanf("%d%d", &a, &b);
		//		cin>>a>>b;
		for(int i=n-1; i>=n-1-3; i--){
			if(cnt == 2)
				break;
			par temp = all[i];
			if(temp.index == a || temp.index == b){
				continue;
			}
			else {
				sum += temp.marks;
				cnt++;
			}
		}
		printf("%d\n", sum);
	}
}
