#include <iostream>
using namespace std;
struct bnode
{
	bnode* left;
	bnode* right;
	int val;
	bnode()
	{ }
	bnode(int val1)
	{
		val=val1;
		left=NULL;
		right=NULL;
	}
};
void insert(bnode* &t, int value)
{
	if(t==NULL)
	{
		t=new bnode(value);
	}
	else if(value<t->val)
	insert(t->left, value);
	else if(t->val<value)
	insert(t->right, value);
}

int rightmost(bnode* t)
{
	if(t->right==NULL)
	return t->val;
	else
	return rightmost(t->right);
}

void delete_val(bnode*& b, int value)
{
	if(b->val==value)
	{
		if(b->right==NULL)
		b=b->left;
		else if(b->left==NULL)
		b=b->right;
		else 
		{
			int temp=rightmost(b->left);
			delete_val(b->left, temp);
			b->val=temp;
		}
	}
	else if(b->val<value)
	delete_val(b->right, value);
	else if(value<b->val)
	delete_val(b->left, value);
}

void printt(bnode *t)
{
	if(t!=NULL)
	{
		printt(t->left);
		cout<<t->val<<endl;
		printt(t->right);	
	}
}

int main()
{
	bnode* root=new bnode();
	root=NULL;
	while(true)
	{
		int x;
		cin>>x;
		if(x==0)
		{
			cin>>x;
			delete_val(root, x);
		}
		else insert(root, x);
		cout<<"insrted";
		printt(root);
		cout<<endl;
	}
}
