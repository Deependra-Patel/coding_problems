#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void adjust(int a[],int l){
	int carry=1;
	while(carry!=0){
		int temp=a[l]+carry;
		a[l]=temp%10;
		carry=temp/10;
		l--;
	}
}
int main(){
	string str;
	cin>>str;
	while(str!="-1"){
		int ans[32],carry=0,temp;
		if(str.length()==1 && str[0]=='0')
		cout<<'0'<<endl;
		else{
		str[str.length()-1]--;
		for(unsigned int i=0; i<str.length(); i++){
			temp=(str[i]-'0'+carry*10);
			ans[i]=(temp/9);	
			carry=temp%9;
		}

		adjust(ans, str.length()-1);
		unsigned int i;
		if(ans[0]==0)
		i=1;
		else i=0;
		for(;i<str.length();i++)
		cout<<ans[i];
		cout<<endl;
		}
		cin>>str;
	}
}
