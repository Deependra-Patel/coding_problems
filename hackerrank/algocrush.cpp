#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
#include <iomanip>
using namespace std;
struct tree{
	long long add;
	int i, j;
	tree* left;
	tree* right;
	tree(){}
	tree(tree* a, tree* b, int a1, int b1){
		left=a;
		right=b;
		i=a1;
		j=b1;
	}
};
void postorder(tree* p, int indent=0)
{
    if(p != NULL) {
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
         cout<<"("<<p->i<<","<<p->j<<")"<< "\n ";
        if(p->left) postorder(p->left, indent+4);
        if(p->right) postorder(p->right, indent+4);
    }
}
long long maxi(tree* mytree){
	if(mytree==NULL)
		return 0;
	else return (mytree->add + max(maxi(mytree->left), maxi(mytree->right)));
}

void insert(tree* mytree, int k, int a, int b){
	int mid=a+(b-a-1)/2;
	if(mytree->i==a && mytree->j==b)
		mytree->add=k;
	else if(b<=mid)
		insert(mytree->left, k, a, b);
	else if(a>mid)
		insert(mytree->right, k, a, b);
	else {
		insert(mytree->left, k, a, mid);
		insert(mytree->right, k, mid+1, b);
	}	
}

tree* make_tree(int i, int j){
	if(i==j){
		return (new tree(NULL, NULL, i, j));
	}
	else {
		int mid=i+(j-i-1)/2;
		tree* lefti=make_tree(i, mid);
		tree* righti=make_tree(mid+1, j);
		return (new tree(lefti, righti, i, j));
	}
}

int main(){
	long long n,m;
	cin>>n>>m;
	tree* final=make_tree(1, n);
	postorder(final);
	// while(m--){
	// 	int a, b, k;
	// 	cin>>a>>b>>k;
	// 	insert(final,k, a, b);
	// }
	cout<<maxi(final)<<endl;
}