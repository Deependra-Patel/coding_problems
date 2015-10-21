#include <iostream>
using namespace std;
long long int maxi = 4294967296ull-1;
int main(){
	int nt;
	cin>>nt;
	while(nt--){
		int n, k;
		cin>>n>>k;
		int ans = n-1;
		int ans2 = 0;
		if(k==0){
			cout<<-1<<endl;
			continue;
		}
		k--;
		if(k == 0){
			ans2 = 1;
		}
		else for(int i=31; i>=0; i--){
			if(ans>>i & 1){
				k--;				
				if(k == 0){
					ans2 = ans & (maxi<<i);
					if(i!=0) ans2+=1;
					break;
				}
			}
		}
		if(k!=0)
			ans2 = ans;
		cout<<ans2<<endl;
	}
}
