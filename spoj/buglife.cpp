#include <iostream>
#include <vector>
using namespace std;
bool found(vector<int> &arr,int x,int y)
{
	vector<int> opx,opy;
	for(int i=0;i<(arr.size());i++)
	{
		if(arr[i]==x)
		opx.push_back(arr[i+1]);
		else if(arr[i]==y)
		opy.push_back(arr[i+1]);
		else if(arr[i+1]==x)
		opx.push_back(arr[i]);
		else if(arr[i+1]==y)
		opy.push_back(arr[i]);
		i++;
	}
	for(int i=0;i<opx.size();i++)
		for(int j=0;j<opy.size();j++)
		{
			if(opx[i]==opy[j])
			return true;
		}
	return false;
}
int main()
{
	int no_of_scenario,n_interactions,n_bugs,bugx,bugy,i;
	cin>>no_of_scenario;
	for(int z=0;z<no_of_scenario;z++)
	{
		cin>>n_bugs;
		cin>>n_interactions;
		vector<int> arr;
		i=0;
		while(i<n_interactions)
		{
			cin>>bugx;
			cin>>bugy;
			if(bugx==bugy)
			break;
			else
			if(found(arr,bugx,bugy))
			break;
			else
			{	arr.push_back(bugx);
				arr.push_back(bugy);
			}
			i++;
		}
		cout<<"Scenario #"<<(z+1)<<":"<<endl;
		if(i==n_interactions)
		cout<<"No suspicious bugs found!"<<endl;
		else 
		cout<<"Suspicious bugs found!"<<endl;
	}
}
