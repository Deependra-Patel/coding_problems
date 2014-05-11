#include <iostream> 
#include <string>
using namespace std;
int main()
{int n,last;long long b;string s;cin>>n;for(int z=0;z<n;z++){cin>>s;int d=s[s.size()-1]-'0';cin>>b;int t=b%4;if(b==0)cout<<1;else if(d==1||d==6||d==0||d==5)cout<<d;else if(d==9){if(b%2==0)cout<<1;else cout<<9;}else if(d==8){if(t==1)cout<<8;else if(t==2) cout<<4;else if(t==3) cout<<2;else cout<<6;}else if(d==2){if(t==1)cout<<2;else if(t==2)cout<<4;else if(t==3)cout<<8;else cout<<6;}else if(d==3)
{if(t==1)cout<<3;else if(t==2)cout<<9;else if(t==3)cout<<7;else cout<<1;}else if(d==4){if(b%2==1) cout<<4;else cout<<6;}else if(d==7){if(t==1)cout<<7;else if(t==2)cout<<9;else if(t==3)cout<<3;else cout<<1;}cout<<endl;}}

