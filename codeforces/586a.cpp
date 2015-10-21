#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum = 0;
	int last = 0;
	bool univ = false;
	while(n--){
		int x;
		cin>>x;
		if(x == 1){
			sum = 1;
			univ = true;
			last = 1;
			break;
		}
	}
	int tempsum = 0;
	while(n!=-1 && n--){
		int x;
		cin>>x;
		if(x == 0){
			if(univ && last == 0){
				tempsum --;
				univ = false;
			}
			else if(univ) tempsum++;
		}
		else {
			sum += tempsum+1;
			tempsum = 0;
			if(!univ){
				univ = true;
			}
		}
		last = x;
	}
	cout<<sum<<endl;
}
