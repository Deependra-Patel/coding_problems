#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define si 100001
int main(){
	int n, s;
	cin>>n>>s;
	int *sell = new int[si];
	int *buy = new int[si];
	for(int i=0; i<si; i++){
		sell[i] = buy[i] = 0;
	}
	vector<int> p1, p2;
	vector<int> q1, q2;
	for(int i=0; i<n; i++){
		char c;
		int p, q;
		cin>>c>>p>>q;
		if(c=='B'){
			buy[p] += q;			
		}
		else sell[p] += q;
	}
	int temp = s;
	for(int i=0; i<=si-1; i++){
		if(sell[i]!=0){
			temp--;
			p1.push_back(i);
			q1.push_back(sell[i]);
			if(temp == 0)
				break;
		}
	}
	reverse(p1.begin(), p1.end());
	reverse(q1.begin(), q1.end());

	temp = s;
	for(int i=si-1; i>=0; i--){
		if(buy[i]!=0){
			temp--;
			p2.push_back(i);
			q2.push_back(buy[i]);
			//cout<<"B"<<" "<<i<<" "<<buy[i]<<endl;
			if(temp == 0)
				break;
		}
	}
	for(int i=0; i<p1.size(); i++){
		cout<<"S"<<" "<<p1[i]<<" "<<q1[i]<<endl;
	}		
	for(int i=0; i<p2.size(); i++){
		cout<<"B"<<" "<<p2[i]<<" "<<q2[i]<<endl;
	}
}
