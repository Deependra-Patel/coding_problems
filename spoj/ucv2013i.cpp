#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double  r,N;
	double alpha,R;
	while(true)
	{	
		cin>>r;
		cin>>N;
		if(r==0 && N==0)
		break;
		alpha=M_PI/(2*N);
		R=r/sin(alpha);
		cout<< fixed;
		cout<<setprecision(2)<<R<<endl;
	}
	return 0;
}
