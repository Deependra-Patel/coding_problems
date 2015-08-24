#include <iostream>
using namespace std;
int main(){
	string str;
	cin>>str;
	while(str!="0"){
		int n;
		n = str.length();
		long long int ans = 1;
		long long int  ans0;
		if (n>=2){
			if((str[1]-'0' == 0)|| (str[0]-'0' > 2 || (str[0]-'0'==2 && str[1]-'0'>6))){
				ans = 1;
			}
			else ans = 2;
		}
		ans0 = 1;
		for(int i=2; i<n; i++){
			int x = str[i] - '0';
			int x0 = str[i-1] - '0';
			if((x!=0) && ((x0 < 2 && x0!=0)  || (x0 == 2 && x<=6))){
				int tempAns = ans;
				ans = ans0 + ans;
				ans0 = tempAns;
			}
			else {
				ans0 = ans;
			}
		}
		cout<<ans<<endl;
		cin>>str;
	}
}
