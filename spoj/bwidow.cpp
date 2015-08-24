#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		int * r = new int[n];
		int * R = new int[n];
		bool * done = new bool[n];
		for(int i=0; i<n; i++){
			cin>>r[i];
			cin>>R[i];
			done[i] = false;
		}
		int ind = 0;
		for(int i=0; i<n; i++){
			if(R[ind]<R[i])
				ind = i;
		}
		//	int x = r[ind];
		/*done[ind]= true;
		bool fail = false;
		int maxi;
		//	cout<<x<<endl;
		for(int i=1; i<n; i++){
			int max = -1;
			for(int j=0; j<n; j++){
				if(!done[j] && max<R[j]){
					max = R[j];
					maxi = j;
				}
			}
			cout<<max<<" "<<maxi<<endl;
			if((max != -1) && x>R[maxi]){
				done[maxi] = true;
				x = r[maxi];
			}
			else {
				fail = true;
				break;
			}
			}*/
		bool fail = false;
		for(int i=0; i<n; i++){
			if(ind !=i){
				if(R[i]>=r[ind]){
					fail = true;
					break;
				}
			}
		}
		if(fail)
			cout<<-1<<endl;
		else cout<<ind+1<<endl;
	}
}
