#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		char ch[10];
		scanf("%s", ch);
		string in(ch);
		int sum=0;
		for(int i=0; i<in.length(); i++){
			sum+=in[i]-'0';
		}
		while(sum>=10){
			int temp=0;
			while(sum>0){
				temp+=sum%10;
				sum/=10;
			}
			sum=temp;
		}
		printf("%d \n", sum);
	}
}
								
