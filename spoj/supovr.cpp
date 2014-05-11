#include <iostream>
using namespace std;
int main(){
	int runs[3], out=0, nball=0, strike=0, whosout=-1;
	runs[0]=runs[1]=runs[2]=0;
	while(out!=2 && nball!=6){
		char in;
		cin>>in;
		if(in=='O'){
			nball++;
			out++;
			whosout=strike;
			if(out==1)
			strike=2;
		}
		else if(in=='N' || in=='W')
			continue;
		else {
			int r=in-'0';
			runs[strike]+=r;
			if(r%2==0){
				nball++;
			}
			else {
				nball++;
				if(out==0 && strike==0)
				strike=1;
				else if(out==0 && strike==1)
				strike=0;
				else if(out==1 && strike==1)
				strike=2;
				else if(out==1 && strike==2){
					if(whosout==1)
					strike=0;
					else 
					strike=1;
				}
				else if(out==1 && strike==0)
				strike=2;
			}
		}
	}
	cout<<runs[0]<<endl<<runs[1]<<endl<<runs[2];
}

			
