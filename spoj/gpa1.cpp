#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	int no;
	cin>>no;
	string s;
	int credits[6];
	int points[6];
	for(int z=0;z<no;z++)
	{
		for(int p=0;p<6;p++)
		cin>>credits[p];
		float pass=true;
		for(int i=0;i<6;i++)
		{
				float a1,a2,a3,a;
				cin>>s;
				if(s=="ab")
				a1=0;
				else
				a1=atof(s.c_str());
				
				cin>>s;
				if(s=="ab")
				a2=0;
				else
				a2=atof(s.c_str());
				cin>>s;
				if(s=="ab")
				a3=0;
				else
				a3=atof(s.c_str());
				
				if(a1>=a3&&a2>=a3)
				a=(a1+a2)*(45.0/40.0);
				else if(a1>=a2&&a3>=a2)
				a=(a1+a3)*(45.0/40.0);
				else if(a2>=a1&&a3>=a1)
				a=(a3+a2)*(45.0/40.0);
				float f;
				cin>>f;
				f=f/2;
				
				int p;
				float per;
				cin>>per;
				if(per<51)
				p=5;
				else if(per<61)
				p=4;
				else if(per<71)
				p=3;
				else if(per<81)
				p=2;
				else if(per<91)
				p=1;
				else p=0;
				
				int g;
				float sum=a+f+p;
				if(sum>=91)
				g=10;
				else
				if(sum>=81)
				g=9;
				else 
				if(sum>=71)
				g=8;
				else
				if(sum>=61)
				g=6;
				else
				if(sum>50)
				g=6;
				else
				if(sum==50)
				g=5;
				else
				{
					pass=false;
					g=0;
				}
				points[i]=g;
			}
			float sum=0,tot=0;
			for(int p=0;p<6;p++)
			{
				//cout<<points[p]<<endl;
				tot+=points[p]*credits[p];
				sum+=credits[p];
			}
			float answ=tot/sum;
			if(pass==false)
			cout<<"FAILED, ";
			else cout<<"PASSED, ";
			printf("%.2f",answ);
			cout<<endl;
	}
}

