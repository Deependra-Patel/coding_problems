#include <iostream>
using namespace std;

int ans(arr[500][], mini[500][],int val, int i, int j, int r, int c){
	if(i==r && j==c)
		return 0;
	else {
		if(mini[i+1][j]<val+arr[i+1][j]){
			mini[i+1][j]=val+arr[i+1][j];
			

		}

	}

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>c>>r;
		int arr[500][500];
		int mini[500][500];
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				cin>>arr[i][j];
				mini[i][j]=-1000000;
				/* code */
			}
			/* code */
		}
		cout<<ans(arr, mini, 0, 0, 0, r, c)<<endl;
	}
}