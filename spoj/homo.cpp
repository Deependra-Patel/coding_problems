#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int, int> mymap;
	int morethan1=0,only1=0;
	if(n==0)
	printf("neither \n");
	for(int i=0; i<n; i++){
		char ch[10];
		scanf("%s", ch);
		string in(ch);
		int x;
		if(in=="insert")
			{				
							cin>>x;
							int freq=mymap[x]++;
							if(freq==0)
							only1++;
							else if(freq==1){
								morethan1++;
								only1--;
							}
			}
		else if(in=="delete")
			{				
							cin>>x;
							map<int, int>::iterator it;
							it=mymap.find(x);
							if(it!=mymap.end()){
								int freq=(*it).second--;
								if(freq==2){
									morethan1--;
									only1++;
								}
								else if(freq==1){
									only1--;
									mymap.erase(it);
								}
							}
			}
		if((morethan1==1 && only1>=1) || (morethan1>=2))
		printf("both \n");
		else if(morethan1==0 && only1>=2)
		printf("hetero \n");
		else if(morethan1>=1 && only1==0)
		printf("homo \n");
		else 
		printf("neither \n");
	}
}
								
