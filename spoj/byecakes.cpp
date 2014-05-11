#include <iostream>
using namespace std;

int main(){
	int arr[8];
	bool done=false;
	while(true){
		for(int i=0; i<8; i++){
			cin>>arr[i];
			if(arr[i]==-1)
			done=true;
		}
		if(done)
		break;
		int maxcake=0;
	
		for(int i=0; i<4; i++){
			int div=arr[i]/arr[i+4];
			if(maxcake<=div){
				if(arr[i]%arr[i+4]==0)
				maxcake=div;
				else maxcake=div+1;
			}
		}
		
		for(int i=0; i<4; i++){
			cout<<maxcake*arr[i+4]-arr[i]<<" ";
		}
		cout<<endl;
	}
}
