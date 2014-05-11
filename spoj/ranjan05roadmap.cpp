#include <iostream>
#include <vector>
using namespace std;
struct tree
{
	vector<tree*> sons;
	tree* baap;
	int index;
	tree()
	{}
	tree(int ind1, tree* baap1)
	{
		index=ind1;
		baap=baap1;
	}
};
void printt(tree* root)
{
	if(root!=NULL)
	{
		cout<<"Index: "<<root->index<<endl;
		cout<<"bachcha index:";
		for(unsigned int i=0;i<root->sons.size();i++)
		cout<<root->sons[i]->index<<" "; 
		cout<<endl;
		for(unsigned int i=0;i<root->sons.size();i++)
		printt(root->sons[i]);
	}
}

//void insert(tree* root, )
int main()
{
	tree* p_of_ind[50001];

	int x, icap, ncap;
	cin>>x>>icap>>ncap;
	for(int i=1;i<=x;i++)
	p_of_ind[i]=NULL;
	
	p_of_ind[icap]=new tree(icap, NULL);
	
	for(int i=1;i<=x;i++)
	{
		if(i==icap)
		continue;
		else {
			int baap;
			cin>>baap;
			if(p_of_ind[i]==NULL)
			p_of_ind[i]=new tree(i, p_of_ind[baap]);
			else p_of_ind[i]->baap=p_of_ind[baap];
			
			if(p_of_ind[baap]==NULL)
			{
				p_of_ind[baap]=new tree(baap, NULL);
				p_of_ind[baap]->sons.push_back(p_of_ind[i]);
			}
			else p_of_ind[baap]->sons.push_back(p_of_ind[i]);
		}
	}
	//printt(p_of_ind[icap]);
	tree* current=p_of_ind[ncap];
	tree* oldcap=p_of_ind[icap];
	tree* oldbaap=current->baap;
	while(current!=oldcap)
	{
		if(oldbaap==oldcap)
		{
			oldbaap->baap=current;
			break;
		}
		else{
		tree* temp=oldbaap->baap;
		oldbaap->baap=current;
		current=oldbaap;
		oldbaap=temp;
		}
	}
	//printt(p_of_ind[ncap]);
	for(int i=1; i<=x;i++)
	{
		if(i==ncap)
		continue;
		else{
			cout<<p_of_ind[i]->baap->index<<endl;
		}
	}
}
