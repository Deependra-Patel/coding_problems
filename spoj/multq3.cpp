#include <iostream>
using namespace std;
struct tree
{
	tree* lt;
	tree* rt;
	int d0, d1, d2, il, ir;
	void printleaf()
	{
		if(lt==NULL)
		cout<<d0<<endl;
		else
		{
			(*lt).printleaf();
			(*rt).printleaf();
		}
	}
	void add1(int a, int b)
	{
		if(lt==NULL && rt==NULL)
		{
			if(d0==1)
			{
				d1=1;
				d0=0;
			}
			else 
			if(d1==1)
			{
				d1=0;
				d2=1;
			}
			else 
			if(d2==1)
			{
				d2=0;
				d0=1;
			}
		}
		else if(a>il)
		{
			(*rt).add1(a-il-1,b-il-1);
			d0=(*lt).d0+(*rt).d0;
			d1=(*lt).d1+(*rt).d1;
			d2=(*lt).d2+(*rt).d2;
		}
		else 
		if(b<=il)
		{
			(*lt).add1(a,b);
			d0=(*lt).d0+(*rt).d0;
			d1=(*lt).d1+(*rt).d1;
			d2=(*lt).d2+(*rt).d2;
		}
		else
		if(a==0 && b==ir)
		{
			int temp0;
			temp0=d0;
			d0=d2;
			d2=d1;
			d1=temp0;
		}
		else 
		{
			(*lt).add1(a,il);
			(*rt).add1(0,b-il-1);
			d0=(*lt).d0+(*rt).d0;
			d1=(*lt).d1+(*rt).d1;
			d2=(*lt).d2+(*rt).d2;
		}
	}
	int div3(int a, int b)
	{
		if(a==0 && b==ir)
		return d0;
		else
		if(a>il)
		return (*rt).div3(a-il-1,b-il-1);
		else 
		if(b<=il)
		return (*lt).div3(a,b);
		else
		return ((*lt).div3(a,il)+(*rt).div3(0,b-il-1));
	}
};
int leftn(int x)
{
	int l=1;
	while(x>l)
	{
		l=l*2;
	}
	return l/2;
}

tree* maketree(int n)
{
	tree* t=new tree();
	(*t).d0=n;
	(*t).d1=0;
	(*t).d2=0;
	if(n!=1)
	{
		int ln=leftn(n);
		(*t).il=ln-1;
		(*t).ir=n-1;
		(*t).lt=maketree(ln);
		(*t).rt=maketree(n-ln);
	}
	return t;
}
int main()
{
	int n, q;
	cin>>n>>q;
	tree* node;
	node=maketree(n);
	int c, a, b;
	for(int i=0;i<q;i++)
	{
		cin>>c>>a>>b;
		if(c==0)
		(*node).add1(a,b);
		else
		cout<<(*node).div3(a,b)<<endl;
		(*node).printleaf();
	}
	
}
