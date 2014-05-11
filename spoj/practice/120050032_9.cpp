#include <iostream>
using namespace std;
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <vector>
 struct account{
	set<string> list;
	long long bal;
	account()
	{}
	account(long long bal1){
		bal=bal1;
	}
};
int  main(){
	map<string, long long> order_by_no;
	map<long long,set<string> >order_by_bal;
	long long mini=1;
	char c;
	cin>>c;
	while(c!='E'){
		if(c=='T'){
			string no;
			long long add,old_bal,new_bal;
			cin>>no;
			cin>>add;
			
			old_bal=order_by_no[no];
			new_bal=old_bal+add;
			mini=min(mini, new_bal);
			order_by_no[no]=new_bal;
			set<string>::iterator it=order_by_bal[old_bal].find(no);
			
			if(it!=order_by_bal[old_bal].end())
			order_by_bal[old_bal].erase(it);
			
			if(new_bal!=0)
			order_by_bal[new_bal].insert(no);
			}
		else if(c=='Q'){
			string no;
			cin>>no;
			cout<<no<<" "<<order_by_no[no]<<endl;
		}
		else if(c=='L'){
			long long l;
			cin>>l;
			vector<string> all;
			set<string>::iterator it;

			for(long long x=mini;x<=l;x++){
				it=order_by_bal[x].begin();
				while(it!=order_by_bal[x].end()){
					all.push_back(*it);
					it++;
				}
			}
			sort(all.begin(),all.end());
			for(unsigned long long i=0; i<all.size();i++)
			cout<<all[i]<<" ";
			cout<<endl;
		}
		cin>>c;
	}
}


