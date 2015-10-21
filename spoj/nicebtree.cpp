#include <iostream>
#include <string>
using namespace std;

int getDepth(string str){
	//cout<<str<<endl;
	if(str.length() == 1)
		return 0;
	else {
		string left, right;
		left = "";
		right = "";
		int lc = 0;
		int nc = 0;
		int i;
		for(i=1; i<str.length(); i++){
			if(str[i] == 'l')
				lc++;
			else nc++;
			if(nc+1==lc){
				left = str.substr(1, nc+lc);
				right = str.substr(i+1);
				//cout<<left<<" "<<right<<endl;
				break;
			}
		}
		//if(i== str.length()) return -1;
		return max(getDepth(left), getDepth(right))+1;
	}
}

int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		string str;
		cin>>str;
		cout<<getDepth(str)<<endl;
	}
}
