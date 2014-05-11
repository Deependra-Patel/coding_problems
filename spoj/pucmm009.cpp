#include <iostream>
using namespace std;
long long gcd(long long a, long long b){
	if(b==0)
	return a;
	else return gcd(b, a%b);
}

int main(){
	int count=0;
	int a[5];
	for(int i=1234; i<=98765; i++){
		if(i%495==0){
			int tep=i,cot=0;
			while(tep>0){
				a[cot]=tep%10;
				cot++;
				tep/=10;
			}
			bool flag=false;
			for(int p=0; p<cot ;p++){
				for(int q=p+1; q<cot; q++){
					if(a[p]==a[q]){
						flag=true;
						break;
					}
				}
				if(flag)
				break;
			}
			if(!flag)
			count++;
		}
	}
	cout<<10*9*8*7*6;
	int d=gcd(30240,count);
	cout<<(count/d)<<"/"<<(30240/d)<<endl;
}
