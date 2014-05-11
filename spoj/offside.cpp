#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	while(!((a==0)&&(b==0))){
		
		int mina=100000000, min1b=100000000, min2b=100000000, temp;
		for(int i=0; i<a;i++){
			cin>>temp;
			mina=min(mina, temp);
		}
		for(int i=0; i<b;i++){
			cin>>temp;
			if(min1b>temp){
				min2b=min1b;
				min1b=temp;
			}
			else if(min2b>temp)
				min2b=temp;
		}
		if(min2b>mina)
		cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		
		cin>>a>>b;
	}
}

