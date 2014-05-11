#include <iostream>
#include <algorithm>
using namespace std;
/*
struct tree{
	tree* lt;
	tree* rt;
	int mini, val;
	tree()
	{}
	tree(int val1){
		val=val1;
		lt=0;
		rt=0;
		mini=100000000;
	}
};
int min3(int a, int b, int c){
	return min(a, min(b,c));
}
void make(tree* &t, int x){
	if(t==NULL)
	t=new tree(x);
	else if(t->val<x)
	make(t->rt, x);
	else if(x<t->val)
	make(t->lt, x);
}
void check(tree* t, int x){
	if(t==0)
	{}
	else if(t->val==x)
	t->mini=0;
	else if(t->val<x){
	check(t->rt, x);
	if(t->rt!=0)
	t->mini=min3(t->mini, abs(t->val-x), t->rt->mini);
	else t->mini=min(t->mini, abs(t->val-x));
	}
	else if(t->val>x){
	check(t->lt, x);
	if(t->lt!=0)
	t->mini=min3(t->mini, abs(t->val-x), t->lt->mini);
	else t->mini=min(t->mini, abs(t->val-x));
	}
}
void printt(tree *t)
{
	if(t!=NULL)
	{
		cout<<t->val<<endl;
		printt(t->lt);
		printt(t->rt);	
	}
}


int main(){
	int ntest;
	cin>>ntest;
	for(int i=0;i<ntest;i++){
		int n1;
		cin>>n1;
		tree* root=new tree();
		root=0;
		for(int j=0;j<n1;j++){
			int x;
			cin>>x;
			make(root, x);
		}
		int n2, ans=100000000;
		cin>>n2;
		for(int j=0;j<n2;j++){
			int x;
			cin>>x;
			check(root, x);
			if(root->mini==0){
				ans=0;
				break;
			}
			else ans=min(ans, root->mini);
		}
		cout<<ans<<endl;
	}
}*/
int main(){
	int ntest;
	cin>>ntest;
	for(int i=0;i<ntest;i++){
		int n1;
		cin>>n1;
		int* a=new int[n1];
		for(int i=0; i<n1; i++)
		cin>>a[i];
		int n2, ans=100000000;
		cin>>n2;
		
		int* b=new int[n2];
		for(int i=0; i<n2; i++)
		cin>>b[i];
		for(int i=0;i<n1;i++){
			for(int j=0;j<n2;j++)
			ans=min(ans, abs(a[i]-b[j]));
		}
		cout<<ans<<endl;
	}
}


