#include <iostream>
#include <vector>
using namespace std;
struct num
{
	int val, start, end, freq;
	/*void printt()
	{
		cout<<val<<" "<<freq<<" "<<start<<" "<<end<<endl;
	}*/
};
int findmax(vector<num*> vec, int a, int b, int fp)
{
	if(fp>=vec.size())
	return 0;
	if(a>(*vec[fp]).end)
	return findmax(vec,a,b,fp+1);
	else 
	if((*vec[fp]).start>b)
	return 0;
	else
	if((*vec[fp]).start>=a && (*vec[fp]).end<=b)
	return max((*vec[fp]).freq,findmax(vec, a, b, fp+1));
	else
	if((*vec[fp]).start>=a)
	return (b-(*vec[fp]).start+1);
	else
	if((*vec[fp]).end<=b)
	return max((a-(*vec[fp]).end+1),findmax(vec,a,b,fp+1));
	else 
	return -1;
}

int main()
{
	int n, n_query;
	cin>>n;
	while(n!=0)
	{
		vector<num*> vec;
		cin>>n_query;
		int x,y;
		cin>>x;
		num* temp=new num();
		(*temp).start=1;
		(*temp).val=x;
		(*temp).freq=1;
		vec.push_back(temp);
		for(int z=2;z<=n;z++)
		{
			cin>>y;
			if(x==y)
			{
				(*vec[vec.size()-1]).freq++;
			}
			else
			{
				(*vec[vec.size()-1]).end=z-1;				
				num* temp=new num();
				(*temp).val=y;
				(*temp).freq=1;
				(*temp).start=z;
				vec.push_back(temp);
				x=y;
			}
		}
		(*vec[vec.size()-1]).end=n;
		//for(int i=0;i<vec.size();i++)
		//(*vec[i]).printt();
		for(int i=0;i<n_query;i++)
		{
			int a, b;
			cin>>a>>b;			
			cout<<findmax(vec, a, b, 0)<<endl;
		}
		
		cin>>n;
	}
}
