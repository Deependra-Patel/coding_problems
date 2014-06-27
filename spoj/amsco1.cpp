#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	while(cin>>str){
		string perm="";
		vector<vector<string> > vec;
		bool per=true;
		for(int i=0; i<str.length(); i++){
			if(str[i]==' ')
				per=false;
			else if(per){
				perm+=str[i];
			}
		}
	}
	//cout<<"done";
}