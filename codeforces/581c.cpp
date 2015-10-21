#include <iostream>
#include <algorithm>
using namespace std;
struct my{
	long long val, rem;
};
bool cmp(my left, my right){
	return left.rem > right.rem;
}

int main(){
	int n, k;
	cin>>n>>k;
	my* myarr = new my[n];
	//int* arr = new int[n];
	long long x = 0;
	long long rating = 0;
	for(int i=0; i<n ;i++) {
		int x;
		cin>>x;
		myarr[i].val = x;
		myarr[i].rem = x%10;
		rating += x/10;
	}
	sort(myarr, myarr+n, &cmp);
	for(int i=0; i<n; i++){
		if(myarr[i].rem!=0){
			int temp = 10-myarr[i].rem;
			//cout<<a[i];
			if(myarr[i].val+temp<=100 && k-temp>=0){
				k -= temp;
				myarr[i].val += temp;
				rating += 1;
			}
		}
		else break;
	}
	if(k>0){
		int diff = 0;
		for(int i=0; i<n; i++){
			diff += (100-myarr[i].val)/10;
		}
		if(k/10 > diff){
			rating += diff;
		}
		else rating += k/10;
	}
	cout<<rating<<endl;
}
