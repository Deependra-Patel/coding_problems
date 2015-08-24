#include <iostream>
#include <stdio.h>
using namespace  std;
string str;
int i, j, k, l;
char getchar(int x){
	if(i<=x && x<=j){
		return str[i+j-x-1];
	}
	else return str[x-1]; 
}
int main(){
	cin>>str;
	int q;
	scanf("%d", &q);
	while(q--){
		//		cin>>i>>j>>k>>l;
		scanf("%d %d %d %d", &i, &j, &k, &l);
		bool pal = true;
		int x = l-1;
		for(int t=k-1; t<l;t++){
			if(t>(k+l)/2)
				break;
			if(getchar(t+1)!=getchar(x+1)){
				pal = false;
				break;
			}				
			x--;
		}
		if(pal)
			printf("Yes\n");
		else printf("No\n");
	}
}
