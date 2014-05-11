#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;
int main(){
	int ntest;
	scanf("%d",&ntest);
	for(int z=0; z<ntest; z++){
		int ndigit;
		scanf("%d", &ndigit);
		int* arr=new int[ndigit];
		for(int i=0; i<ndigit; i++)
		scanf("%d",&arr[i]);

		int index,i,j;
		for(i=ndigit-1; i>=1; i--){
			if(arr[i-1]<arr[i]){
				if(i==ndigit-1){
					int temp=arr[i-1];
					arr[i-1]=arr[i];
					arr[i]=temp;
				} else 
				for(j=i+1; j<ndigit; j++){
					if(arr[j]<=arr[i-1]){
						int temp=arr[j-1];
						arr[j-1]=arr[i-1];
						arr[i-1]=temp;
						break;
					}
				}
				if(j==ndigit){
					int temp=arr[j-1];
					arr[j-1]=arr[i-1];
					arr[i-1]=temp;
				}
				index=i-1;
				break;
			}
		}
		if(i==0)
		printf("-1 \n");
		else{
			for(int i=0; i<=index; i++)
			printf("%d",arr[i]);
			for(int i=ndigit-1; i>index; i--)
			printf("%d", arr[i]);
			printf("\n");
		}
	}
}
