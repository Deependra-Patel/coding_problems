#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
	int startt, endt;
	interval(int startt, int endt){
		this->startt=startt;
		this->endt=endt;
	}
	interval(){};
	bool operator<(const interval* other){
		return (endt<other->endt);
	}
	void printi(){
		cout<<startt<<" "<<endt<<endl;
	}
};

bool custom_sorter(interval* const& lhs, interval* const& rhs) {
    return ((lhs->endt)<(rhs->endt));
}

int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		interval ** arr=new interval*[n];
		for(int i=0; i<n; i++){
			int m1, m2;
			cin>>m1>>m2;
			interval* temp=new interval(m1, m2);
			arr[i]=temp;/*
			arr[i]->startt=m1;
			arr[i]->endt=m2;*/
		}
		std::sort(arr, arr+n, &custom_sorter);
		int ans=0;
		int last=-1;
		for(int i=0; i<n; i++){
			interval cur=*arr[i];
			if(cur.startt>=last){
				ans++;
				last=cur.endt;
			}
		}
		cout<<ans<<endl;
		/*for(int i=0; i<n; i++){
			//arr[i]->printi();
		}*/
	}
}