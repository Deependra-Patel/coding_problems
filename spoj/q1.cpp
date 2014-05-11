#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int z=1; z<=t; z++){
		int n;
		cin>>n;
		int maxx, minx, maxy, miny;
		maxx=maxy=-1;
		minx=miny=n;
		int freq=0;

		for(int i=0; i<n; i++){
			string s;
			cin>>s;
			for(int j=0; j<n; j++){
				char c=s[j];
				if(c=='#'){
					freq++;
					if(i<miny)
					miny=i;
					if(i>maxy)
					maxy=i;
					
					if(j<minx)
					minx=j;
					if(j>maxx)
					maxx=j;
				}
			}
		}
		cout<<"Case #"<<z;
		if(freq==(maxx-minx+1)*(maxy-miny+1) && (maxx-minx==maxy-miny))
		cout<<": YES"<<endl;
		else cout<<": NO"<<endl;
	}
}

					
				
			
					
				
