#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
long long my[16];

long Npr(int n, int r)
{
   long result;

   result = factorial(n)/factorial(n-r);

   return result;
}

long factorial(int n)
{
   int i;
   long result = 1;

   for( i = 1 ; i <= n ; i++ )
      result = result*i;
  return result;
}

void init(){
	int power=0;
	long long val=1;
	while(power<=17){
		my[power]=9*(power+1)*val;
		val*=10;
		power++;
	}
	for(int i=1; i<16; i++)
		my[i]+=my[i-1];
	// for(int i=0; i<16; i++)
	// 	cout<<my[i]<<endl;
}
int num_dig(long long n){
	if(n<=9)
		return 1;
	else return 1+num_dig(n/10);
}
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int ntest;
	cin>>ntest;
	init();
	while(ntest--){
		long long n;
		cin>>n;
		long long ans=0;
		long long temp=n;
		int power=1;
		int num_digi=num_dig(n);
		if(n<=9)
			cout<<"1/10"<<endl;
		else{
			long long temp=my[num_digi-2]+num_digi*(n-pow(10,num_digi-1)+1);
			long long gc=gcd(temp, n*10);
			cout<<temp/gc<<"/"<<(n*10)/gc<<endl;
		}
	}
}
