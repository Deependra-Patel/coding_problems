#include <iostream>
#include <string>
using namespace std;
#define modi 1000000007
int main(){
	int ntest;
	cin>>ntest;
	int temp = ntest;
	while(ntest--){
		string l, h;
		cin>>l>>h;
		int n = l.length();
		long long sum = 0;
		int carry = 0;
		int* arr = new int[n];
		for(int i=n-1; i>=0; i--){
			if(h[i]-carry>=l[i]){
				arr[i] = h[i]-l[i]-carry;
				carry = 0;
			}
			else {
				arr[i] = 26 + h[i] - l[i] - carry;
				carry = 1;
			}
		}
		long long multi = 1;
		for(int i=n-1; i>=0; i--){
			//	cout<<arr[n-i-1]<<" ";
			sum += multi*arr[i];
			sum = sum%modi;
			multi = (multi*26)%modi;
		}
		cout<<"Case "<<temp-ntest<<": "<<sum-1<<endl;
	}
}
