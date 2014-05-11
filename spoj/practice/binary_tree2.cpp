#include <iostream>
using namespace std;
struct btree
{
	bool leaf;
	float val;
	btree left;
	btree right;
};
int main()
{
	btree root;
	root.leaf=false;
	cout<<(root.left==NULL);
}
