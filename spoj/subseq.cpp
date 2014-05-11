#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,len,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		vector<int> v;
		int freq=0,index1=0,sum=0;
		cin>>len;
		for(int j=0;j<len;j++)
		{
			cin>>x;
			v.push_back(x);
		}
		for(int i=0;i<len;i++)
		{
			if(v[i]==47)
			{
					sum=0;
					index1++;
					freq++;
					continue;
			}
			sum+=v[i];
			if(sum==47)
			{
				sum=sum-v[index1];	
				index1++;
				freq++;
			}
			else if(sum>47)
			{
				sum=sum-v[index1];
				index1++;
			}
			cout<<sum;
		}
		cout<<freq<<endl;
	}
}
