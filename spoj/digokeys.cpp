#include <iostream>
#include <list>
using namespace std;
struct node{
	int index;
	list<int> next;
	node(int val){
		index = val;
	}
	void add_next(int ind){
		next.push_back(ind);
	}
};
struct mypair{
	int len;
	list<int> indices;
	/*pair(int len, int index){
		this.len = len;
		this.index = index;
	}*/
};  
#define MAX 10000000
mypair* bfs(node** arr, int cur_ind, int n){
	if(cur_ind == n)
		return 0;
	list<int> next = arr[cur_ind-1]->next;
	list<int>::iterator it = next.begin();
	mypair* ans = new mypair();
	mypair* temp;
	ans->len = MAX;
	while(it!=next.end()){
		int next_one = *it;
		if(arr[next_one-1]->index!=-1){
			temp = bfs(arr, next_one, n);
			if(temp->len < ans->len){
				ans = temp;
			}
		}
		it++;
	}
	ans->indices.push_back(cur_ind);
	ans->len++;
	return ans;
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		node ** arr = new node*[n];
		for(int i=0; i<n-1; i++){
			node* temp = new node(i);
			int no;
			cin>>no;
			for(int j=0; j<no; j++){
				int next;
				cin>>next;
				temp->add_next(next);
			}
			arr[i] = temp;
		}
		node* temp = new node(n);
		arr[n-1] = temp;
		mypair* ans = bfs(arr, 1, n);
		if(ans->len==MAX)
			cout<<-1<<endl;
		else {	
			list<int>::iterator it= ans->indices.end();
			while(it!=ans->indices.begin()){
				cout<<*it<<" ";
				it--;
			}
			cout<<endl;
		}
	}
}
