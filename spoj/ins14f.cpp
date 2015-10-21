#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define mode 1000000007
int main(){
	int ntest;
	cin>>ntest;
	int** cache = new int*[1000];
	int p = 1000;
	for(int i=0; i<p; i++){
		cache[i] = new int[p];
		cache[i][i] = i+1; 			
		for(int j=i+1; j<p; j++){
			cache[i][j] = (cache[i][j-1]*(j+1))%mode;
		}
	}
	
	/*	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++)
			cout<<cache[i][j]<<" ";
		cout<<endl;
		}*/
	while(ntest--){
		long long n, k;
		cin>>n>>k;
		unsigned long long ans;
		int i;
		int l = n-k+1;					
		if(l<=p){
			i = p+1;
			if(n<=p)
				ans = cache[l-1][n-1];
			else {
				ans = cache[l-1][p-1];
				for(; i<=n; i++){
					ans *= i;
					ans = ans%mode;
					cout<<i<<n<<endl;
					break;
				}
			}							
		}
		else {
			i = l;
			ans = 1; 
			for(; i<=n; i++){
				ans *= i;
				ans = ans%mode;
			}
		}
		cout<<ans<<endl;
	}
}
