#include <iostream>
#include <vector>
using namespace std;
string l1, l2;
int n;
#define maxi 1000000000
int minSwitch(int lane, int i, vector<vector<int> > &arr){
	//cout<<"here"<<endl;
	if(i>n-1)
		return maxi;
	if(lane == 1 && arr[i][0]!=-2)
		return arr[i][0];
	
	if(lane == 2 && arr[i][1]!=-2)
		return arr[i][1];

	if(lane == 1){
		if(l1[i]=='#'){
			arr[i][0] = maxi;
			return maxi;
		}
	}
	else if(lane == 2){
		if(l2[i]=='#'){
			arr[i][1] = maxi;
			return maxi;
		}
	}
	
	if(i == n-1){
		return 0;
	}
	
	else {
		if(lane == 1){
			int temp = min(min(minSwitch(1, i+1, arr),
							   minSwitch(2, i, arr)+1),
						   minSwitch(2, i+1, arr)+1);
			arr[i][0] = temp;
			return temp;
		}
		else{
			int temp = min(min(minSwitch(2, i+1, arr),
							   minSwitch(1, i, arr)+1),
						   minSwitch(1, i+1, arr)+1);
			arr[i][1] = temp;
			return temp;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>l1>>l2;
		n = l1.length();
		//	int** arr = new int*[n];
		vector<vector<int> > arr;
		for(int i=0; i<n; i++) {
			vector<int> temp(2);
			temp[0] = temp[1] = -2;
			arr.push_back(temp);
			//arr[i] = new int[2];
			//	arr[i][0] = arr[i][1] = -2;
		}
		//	cout<<"dfd"<<arr[0][0]<<"dfd"<<endl;
		int x = minSwitch(1, 0, arr);
		int y = minSwitch(2, 0, arr);
		if(x == maxi && y == maxi)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl<<min(x, y)<<endl;
	}
}
