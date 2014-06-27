#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
using namespace std;
int arr[32];
int main(){
	int sum, limit;
	cin>>sum>>limit;
	if(limit<sum)
		cout<<-1<<endl;
	else {
		arr[0]=1;
		for(int i=1; i<32; i++)
			arr[i]*=arr[i-1]*2;
		while(sum!=0){
			int divi=-1;
			for(int i=0; i<32; i++){
				if(sum>=2*arr[i])
					divi=arr[i];
			}
			int temp=sum+sum%divi;

			
		}
	}
}