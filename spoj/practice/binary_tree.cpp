#include <iostream>
using namespace std;
struct btree
{
	float val;
	btree* left;
	btree* right;
	
	btree()
	{}
	btree(float x)
	{
		val=x;
		left=NULL;
		right=NULL;
	}
	/*void insert(btree* node, float x)
	{
		if((*node).val<x)
		{
			if((*node).right==NULL)
			{
				btree* temp=new btree(x);
				(*node).right=temp;
			}
			else
			insert((*node).right,x);
		}
		else if(x<(*node).val)
		{
			if((*node).left==NULL)
			{
				btree* temp=new btree(x);
				(*node).left=temp;
			}
			else
			insert((*node).left,x);
		}
	}*/
	void insert(float x)
	{
		if(val<x)
		{
			if(right==NULL)
			{
				btree* temp=new btree(x);
				right=temp;
			}
			else
			(*right).insert(x);
		}
		else if(x<val)
		{
			if(left==NULL)
			{
				btree* temp=new btree(x);
				left=temp;
			}
			else
			(*left).insert(x);
		}
	}
	bool find(float x)
	{
		if(val==x)
		return true;
		else
		if(x<val)
		{
			if(left==NULL)
			return false;
			else
			return (*left).find(x);
		}
		else
		{
			if(right==NULL)
			return false;
			else
			return (*right).find(x);
		}
	}

	void printt()
	{
		if(left!=NULL)
		(*left).printt();
		cout<<val<<" ";
		if(right!=NULL)
		(*right).printt();
	}
};
btree* right_most(btree* node)
{
	if((*node).right==NULL)
	return node;
	else
	return(right_most((*node).right));
}
void delete1(btree* node, float x)
{
	if(node!=NULL)
	{
		if((*node).val==x)
		{
			if((*node).left==NULL && (*node).right==NULL)
			{
				cout<<"reached";
				delete node;
			}
			else 
			{
								cout<<"reached2";

				btree* rmst=right_most((*node).left);
				float rmst_val=(*rmst).val;
				(*node).val=rmst_val;
				delete1((*node).left, rmst_val);
			}
		}
		else if((*node).val<=x)
		{				cout<<"reached3";

		delete1((*node).right, x);
	}
		else
		{
							cout<<"reached4";
 delete1((*node).left, x);
	}
	}
}
int main()
{
	btree* root=new btree(12);
	float x;
	while(1)
	{
		cin>>x;
		if(x==1)
		(*root).printt();
		else if(x==0)
		break;
		else if(x==11)
		{
			cin>>x;
			delete1(root,x);
			cout<<"fuck";
		}
		else
		(*root).insert(x);
	}
}

