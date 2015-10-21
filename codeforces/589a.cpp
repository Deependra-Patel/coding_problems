#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct my{
	string original, converted;
};

bool cmp(my a, my b){
	return a.converted < b.converted;
}

string convert(string str){
	int l = str.length();
	string front, back;
	front = back = "";
	bool found = false;
	for(int i=0; i<l; i++){
		str[i] = tolower(str[i]);
		if(found)
			back += str[i];
		else if(str[i] == '@'){
			found = true;			
		}
		else front += str[i];
	}
	if(back == "bmail.com"){
		int sl = front.length();
		string temp = "";
		for(int i=0; i<sl; i++){
			if(front[i] != '.')
				temp += front[i];
		}
		front = temp;
		int ind = front.find('+');
		if(ind != string::npos){
			front = front.substr(0, ind);
		}	   
	}
	return front+"@"+back;
}
int main(){
	int n;
	cin>>n;
	vector<my> inp;
	for(int i=0; i<n; i++){
		string str;
		cin>>str;
		my x;
		x.original = str;
		x.converted = convert(str);
		inp.push_back(x);
	}
	//cout<<"Dd"<<endl;
	sort(inp.begin(), inp.end(), &cmp);
	//cout<<"ff"<<endl;
	int cnt = 0;
	string cur = inp[0].converted;
	vector<vector <string> > ans;
	vector<string> temp;
	ans.push_back(temp);
	ans[0].push_back(inp[0].original);
	for(int i=1; i<n; i++){
		if(inp[i].converted == cur){
			ans[cnt].push_back(inp[i].original);
		}
		else {
			cur = inp[i].converted;
			vector<string> temp;
			ans.push_back(temp);
			cnt ++;
			ans[cnt].push_back(inp[i].original);
		}
	}

	int l = ans.size();
	cout<<l<<endl;
	for(int i=0; i<l; i++){
		int m = ans[i].size();
		cout<<m<<" ";
		for(int j =0; j<m; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	//	cout<<endl;
}
