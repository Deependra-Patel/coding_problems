#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	unsigned int n, k;
	scanf("%d", &n);
	scanf("%d",&k);
	vector<unsigned int> vec(n,0);
	for(unsigned int i=0;i<n;i++){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	unsigned int curr=0,next=0,currval,i,ans=0;
	while(curr!=n-1){
		currval=vec[curr];
		for(i=next+1; i<n; i++){
			if(vec[i]-currval==k){
				ans++;
				break;
			}
			else if(vec[i]-currval>k)
				break;
		}
			curr++;
			if(vec[i]==currval+k)
			next=i;
	}	
	cout<<ans<<endl;
}
