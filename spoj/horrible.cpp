#include <iostream>
using namespace std;
struct node
{
	node* lnode;
	node* rnode;
	int n_elements_below;
	int l_elements_left;
	int add;
	node()
	{}
	node(int n, int add1)
	{
		n_elements_below=n;
		add=add1;
	}
	void addv(int p, int q, int v)
	{
		if(n_elements_below==1)
		add+=v;
		else
		if(p==0 && q==(n_elements_below-1))
		add=add+v;
		else if(q<l_elements_left)
		(*lnode).addv(p, q, v);
		else if(p>=l_elements_left)
		(*rnode).addv(p-l_elements_left, q-l_elements_left, v);
		else 
		{
			(*lnode).addv(p, l_elements_left-1, v);
			(*rnode).addv(0, q-l_elements_left, v);
		}
	}
	int sum(int p, int q)
	{
		int extra=add*(q-p+1);
		if(p==0 && q==(n_elements_below-1))
		return add*n_elements_below;
		else if(q<l_elements_left)
		return (extra+(*lnode).sum(p, q));
		else if(p>=l_elements_left)
		return (extra+(*rnode).sum(p-l_elements_left, q-l_elements_left));
		else 
		return (extra+(*lnode).sum(p, l_elements_left-1)+(*rnode).sum(0, q-l_elements_left));
	}
	int ret_i(int i)
	{
		if(i==0)
		return add;
		else if(i<l_elements_left)
		return (add+(*lnode).ret_i(i));
		else return (add+(*rnode).ret_i(i-l_elements_left));
	}
};
int calc_ln(int n)
{
	int l=1;
	while(n>l)
	{
		l*=2;
	}
	return l/2;
}
node* makenode(int n)
{
	node* temp=new node(n, 0);
	if(n!=1)
	{
		int c=calc_ln(n);
		(*temp).lnode=makenode(c);
		(*temp).rnode=makenode(n-c);
		(*temp).l_elements_left=c;
	}
	return temp;
}

int main()
{
	int nt;
	cin>>nt;
	for(int z=0;z<nt;z++)
	{
		int n, n_commands;
		cin>>n>>n_commands;
		node* root=makenode(n);
		for(int i=0;i<n_commands;i++)
		{
			int c;
			cin>>c;
			if(c==0)
			{
				int p, q, v;
				cin>>p>>q>>v;
				(*root).addv(p-1, q-1, v);
			}
			else if(c==1)
			{
				int p, q;
				cin>>p>>q;
				cout<<(*root).sum(p-1, q-1)<<endl;
			}
			else if(c==2)
			{
				int i;
				cin>>i;
				cout<<(*root).ret_i(i-1);
			}
		}
	}
}


