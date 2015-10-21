#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		string arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		string max = "";
		for(int i=0; i<arr[0].length(); i++){
			for(int j=i; j<arr[0].length(); j++){
				string curr = arr[0].substr(i, j-i+1);
				int k;
				for(k=1; k<n; k++){
					int found = arr[k].find(curr);
					if(found == string::npos){
						break;
					}
				}
				if(k == n){
					if(curr.size()>max.size()){
						max = curr;
					}
					else if(curr.size() == max.size() && curr<max)
						max = curr;
				}
			}
		}
		cout<<max<<endl;
	}
}
