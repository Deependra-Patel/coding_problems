#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int n;
		cin>>n;
		int* row=new int[n];
		int* col=new int[n];
		for(int p=0; p<n; p++){
			row[p]=0;
			col[p]=0;
		}
		
		int size=0;
		bool black=true;
		
		for(int l=0; l<n; l++){
			string s;
			cin>>s;
			for(int k=0; k<n; k++){
				char x;
				x=s[k];
				if(x=='#'){
					row[l]++;
					col[k]++;
				}
			}
		}
		bool got_last=true;
		int index;
		for(int p=0; p<n; p++){
			if(row[p]!=0){
				size=row[p];
				index=p;
				break;
			}
		}
		if(size==0)
		black=false;
		if(size!=0){
			int nrows=1;
			for(int p=index+1; p<n; p++){
				if(!got_last){
					if(row[p]!=0){
						black=false;
						break;
					}
				}
				
				else{
					if(row[p]!=0){
						nrows++;
						if(nrows>size){
							black=false;
							break;
						}
					}
					else got_last=false;
				}
			}
			
			int ncols=0;
			for(int p=0; p<n; p++){
				if(row[p]!=0){
					if(col[p]==size){
						ncols++;
						if(ncols>size){
							black=false;
							break;
						}
					}
					else {
						black=false;
						break;
					}
				}
			}
			if(nrows!=size || ncols!=size)
			black=false;
		}
		cout<<"Case #"<<i;
		if(black)
		cout<<" YES"<<endl;
		else cout<<" NO"<<endl;
	}
}

					
				
			
					
				
