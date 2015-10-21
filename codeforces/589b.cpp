#include <iostream>
#include <algorithm>
using namespace  std;
struct rect{
	int l, w;
};
bool cmp(rect a, rect b){
	return a.l<b.l;
}

int main(){
	int n;
	cin>>n;
	rect* arr = new rect[n];
	for(int i=0; i<n; i++){
		int l, w;
		cin>>l>>w;
		rect temp;
		temp.l = max(l, w);
		temp.w = min(l, w);
		arr[i] = temp;
	}

	sort(arr, arr+n, &cmp);
	long long ml, mw, ms;
	ms = -1;
	int* postw = new int[n];
	for(int i=0; i<n; i++){
		int cnt = 1;
		for(int j=i+1; j<n; j++){
			if(arr[j].w >= arr[i].w)
				cnt++;
		}
		postw[i] = cnt;
	}
	
	for(int i=0; i<n; i++){
		long long curl = arr[i].l;
		for(int j=i; j<n; j++){
			long long curw = arr[j].w;
			if(postw[j]*curl*curw > ms){
				ms = postw[j]*curl*curw;
				ml = curl;
				mw = curw;
			}
		}
	}
	cout<<ms<<endl<<ml<<" "<<mw<<endl;
}
