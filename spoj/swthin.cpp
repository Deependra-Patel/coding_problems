#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct point{
	int x,y;
	bool areinline(point p2, point p3){
		return (x*(p2.y-p3.y)-y*(p2.x-p3.x)+p2.x*p3.y-p3.x*p2.y==0);
	}
	point(){}
	point(int x1, int y1){
		x=x1;
		y=y1;
	}
};
struct rtree{
	point p;
	vector<rtree*> inlin;
	rtree(){}
	rtree(point p1){
		p=p1;
	}
	void insert(point p1){
		for(unsigned int i=0; i<inlin.size(); i++){
			if(p.areinline(p1,((*inlin[i]).p))){
				inlin[i]->insert(p1);
				break;
			}
		}
		rtree* temp=new rtree(p1);
		inlin.push_back(temp);
	}
	void printt(){
		cout<<"x "<<p.x<<" y "<<p.y<<endl;
		for(int i=0; i<inlin.size(); i++){
			inlin[i]->printt();
			cout<<endl;
		}
	}	
	int depth(){
		int maxi=0;
		for(int i=0; i<inlin.size(); i++){
			maxi=max(inlin[i]->depth(), maxi);
		}
		return (maxi+1);
	}
};
int main(){
	int n,it=1;
	cin>>n;
	while(n!=0){
		rtree* root=new rtree();
		int x, y;
		cin>>x>>y;
		point temp(x,y);
		rtree* tempt=new rtree(temp);
		root->inlin.push_back(tempt);
		for(int i=1; i<n; i++){
			scanf("%d %d",&x,&y);
			point temp(x,y);
			for(unsigned int j=0; j<root->inlin.size(); j++){
				root->inlin[j]->insert(temp);
			}
			rtree* tempt=new rtree(temp);
			root->inlin.push_back(tempt);		
		}
		int dept=root->depth()-1;
		if(dept>=4)
		printf("Photo %d: %d points eliminated\n",it,dept);
		else printf("Photo %d: 0 points eliminated\n",it);
		it++;
		cin>>n;
	}
}
