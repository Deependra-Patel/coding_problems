#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	for(int i=0; i<ntest; i++){
		map<int , int> sl;
		int n, m, r;
		cin>>n>>m>>r;
		for(int j=0; j<m; j++){
			int i1, i2;
			cin>>i1>>i2;
			sl[i1]=i2;
		}
		int pos1=1, pos2=1;
		bool pointer1=true;
		int win=0;
		
		for(int j=0; j<r; j++){
			int roll;
			cin>>roll;
			if(win==0){
			if(pointer1){
				pos1+=roll;
				pointer1=false;
				if(pos1>n){
					pos1-=roll;
				} else{
					while(sl[pos1]!=0){
						int next=sl[pos1];
						pos1=next;
						pointer1=true;
					}
					if(pos1==pos2){
						pointer1=true;
						pos2=1;
					}
					if(win==2)
					pointer1=true;

					if(pos1==n){
						win=1;
						pointer1=false;
					}
				}
				if(roll==6)
				pointer1=true;
			} else {
				pos2+=roll;
				pointer1=true;
				if(pos2>n){
					pos2-=roll;
				} else{
					while(sl[pos2]!=0){
						int next=sl[pos2];
						pos2=next;
						pointer1=false;
					}
					if(pos1==pos2){
						pos1=1;
						pointer1=false;
					}
					if(win==1)
					pointer1=false;
					
					if(pos2==n){
						win=2;
						pointer1=true;
					}
				}
				if(roll==6)
				pointer1=false;
			}}
		}
		cout<<win<<" "<<pos1<<" "<<pos2<<endl;
	}
}
