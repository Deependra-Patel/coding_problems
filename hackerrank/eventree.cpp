#include <iostream>
#include <list>
using namespace std;
struct children{
	list <int> mylist;
};
int calc(children* vertices, int n, int i){
	int size=vertices[i].size();
	if(size==0 || size%2!=0)
		return -1;
	list<int>::iterator it;
	for(it=vertices[i].mylist.begin(); it!=vertices[i].mylist.end(); it++){
		int child_no = *it;
		int val=calc(vertices, n, child_no);
		if(val)
	}
}
int main(){
	int n, m;
	cin>>n>>m;
	children  vertices[n];
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		vertices[a-1].mylist.push_back(b-1);
		vertices[b-1].mylist.push_back(a-1);	
	}
	for(int i=0; i<n; i++){
		children temp=vertices[i];
		cout<<i<<endl;
		list<int>::iterator it;
		for(it=temp.mylist.begin(); it!=temp.mylist.end(); it++){
			cout<<*it<<" ";
		}
	}
}