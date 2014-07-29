#include <iostream>
#include <string>
using namespace std;
int main(){
int ntest;
cin>>ntest;
while(ntest--){
string str;
cin>>str;
string new_str="";
new_str+=str[0];
for(int i=1; i<str.length(); i++){
if(str[i]==str[i-1])
continue;
else {new_str+=str[i];
//cout<<str[i]<<endl;
}
}
//cout<<new_str;
bool pal=true;
for(int i=0; i<new_str.length()/2; i++){
if(new_str[i]!=new_str[new_str.length()-1-i]){
pal=false;
break;
}}
if(pal)
cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}}
