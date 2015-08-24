#include <iostream>
using namespace std;
int minWt[22][80];
int getMinWt(int ox, int ni, int info[][3], int n){
	//	cout<<ox<<" "<<ni<<endl;
	if(ox<=0 && ni<=0)
		return 0;
	if(ox <= 0)
		ox = 0;
	else if(ni <= 0)
		ni = 0;
	if(minWt[ox][ni]!=0)
		return minWt[ox][ni];
	int mini = info[0][2] +
		getMinWt(ox - info[0][0], ni - info[0][1], info, n);
	for(int i=1; i<n; i++){
		mini = min(mini,
				   info[i][2]+getMinWt(ox-info[i][0], ni-info[i][1], info,
							n));
	}
	minWt[ox][ni] = mini;
	cout<<"ox "<<ox<<" ni "<<ni<<" mini "<<mini<<endl;
	return mini;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int ox, ni;
		cin>>ox>>ni;
		int n;
		cin>>n;
		int info[n][3];
		for(int i=0; i<n; i++){
			cin>>info[i][0]>>info[i][1]>>info[i][2];
		}
		cout<<getMinWt(ox, ni, info, n)<<endl;
	}
}
