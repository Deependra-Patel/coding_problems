#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int x, icap, ncap;
	scanf("%d",&x);
	scanf("%d",&icap);
	scanf("%d",&ncap);
	int* arr=new int[x+1];
	for(int i=1;i<=x;i++){
		if(i==icap)
		continue;
		else{
			int x;
			scanf("%d",&x);
			arr[i]=x;
		}
	}
	int curr=ncap;
	int bindex=arr[ncap];
	
	int b2index;
	if(bindex==icap)
	arr[bindex]=curr;
	while(bindex!=icap)
	{
		b2index=arr[bindex];
		if(b2index==icap)
		{
			arr[icap]=bindex;
			arr[bindex]=curr;
			break;
		}
		arr[bindex]=curr;
		curr=bindex;
		bindex=b2index;
	}
	for(int i=1;i<=x;i++){
		if(i==ncap)
		continue;
		else printf("%d ",arr[i]);
	}
	
}
