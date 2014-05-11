#include <iostream>
using namespace std;

struct tree
{
	int val;
	int bal_factor;
	tree* left;
	tree* right;
	
	tree()
	{}
	tree(int value)
	{
		val=value;
		bal_factor=0;
		left=NULL;
		right=NULL;
	}
};
void printt(tree* t) //inorder printing of tree
{
	if(t!=NULL)
	{
		printt(t->left);
		cout<<t->val<<endl;
		printt(t->right);
	}
}
tree* insert(tree *&t, int value, bool &inc_height)
{
	bool h_incresed=false;
	if(t==NULL)
	{
		t=new tree(value);
		inc_height=true;
		return t;
	}
	else if(value<(t->val))
	{
		t->left=insert((t->left), value, h_incresed);
		if(!h_incresed)
		{
			inc_height=false;
			return t;
		} 
		else if(t->bal_factor!=1)
		{
			t->bal_factor--;
			inc_height=(t->bal_factor==-1);
			return t;
		}
		else 
		{
			t->bal_factor=0;
			inc_height=false;
			if(value<(t->left)->val)    //LL case
			t=right_rotation(t);
			else
			{
				t->left=right_rotation(t->left);
				t->left->bal_factor=0;
				t=right_rotation(t);
			} 
			return t;			
		}	
	}
	
	else if((t->val)<value)
	{
		t->right=insert((t->right), value, h_incresed);
		if(!h_incresed)
		{
			inc_height=false;
			return t;
		} 
		else if(t->bal_factor!=-1)
		{
			t->bal_factor--;
			inc_height=(t->bal_factor==-1);
			return t;
		}
		else 
		{
			t->bal_factor=0;
			inc_height=false;
			if((t->right)->val<value)    //RR case
			t=left_rotation(t);
			else
			{
				t->right=right_rotation(t->right);
				t->right->bal_factor=0;
				t=left_rotation(t);
			} 
			return t;			
		}	
	}
	else return t;
}
tree* left_rotation(tree *t)
{
	if(t!=NULL && t->right!=NULL)
		{
			tree* tright=t->right;
			t->right=tright->left;
			tright->left=t;
			return tright;
		}
	else return t;
}

tree* right_rotation(tree *t)
{
	if(t!=NULL && t->left!=NULL)
		{
			tree* tleft=t->left;
			t->left=tleft->right;
			tleft->right=t;
			return tleft;
		}
	else return t;
}
int main()
{
	tree* root=new tree();
	root=NULL;
	bool t;
	root=insert(root,10, t);
	//cout<<"10";
	//insert(root, 2);
	//insert(root, 15);
	//insert(root, 13);
	printt(root);
	//printt(root->left);
}
