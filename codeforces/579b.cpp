#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct team{
	int a1, a2;
	int strength;
	team(){
	}
	team(int a3, int a4, int x){
		a1 = a3;
		a2 = a4;
		strength = x;
	}
	void print(){
		cout<<strength<<" "<<a1<<a2<<endl;
	}
	/*
	bool operator<(team* team2){
		return strength>team2->strength;
		}*/
};

struct lessT{
	bool operator()(team* a, team* b){
		if(a->strength < b->strength)
			return false;
		return true;
	}
};

int main(){
	int n;
	cin>>n;
	team** teams = new team*[n*(2*n-1)];
	int p = 0;
	for(int i=1; i<=2*n; i++){
		for(int j=1; j<i; j++){
			int str;
			cin>>str;
			//cout<<"dd"<<i<<endl;
			teams[p] = new team(i, j, str);
			p++;
		}
	}
	sort(teams, teams+n*(2*n-1), lessT());
	int* done = new int[2*n];
	int* allot = new int[2*n];
	for(int i=0; i<2*n; i++)
		done[i] = false;
	for(int i=0; i<n*(2*n-1); i++){
		//	teams[i]->print();
		team* cur = teams[i];
		if(done[cur->a1-1] || done[cur->a2-1])
			continue;
		else {
			allot[cur->a2-1] = cur->a1;
			allot[cur->a1-1] = cur->a2;
			done[cur->a1-1] = done[cur->a2-1] = true;
		}
		//		teams[i]->print();
	}
	for(int i=0; i<2*n; i++){
		cout<<allot[i]<<" ";
	}
	cout<<endl;
}
