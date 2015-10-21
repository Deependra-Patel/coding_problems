#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mypair{
	int index;
	int marks;
	bool operator<(const mypair &pair2) const{
		return marks<pair2.marks;
	}
};

int main(){
	int n, m;
	cin>>n>>m;
	vector<mypair> pairs;
	for(int i=0; i<n; i++){
		mypair current;
		cin>>current.marks;
		current.index = i+1;
		pairs.push_back(current);
	}
	sort(pairs.begin(), pairs.end());
	for(int i=0; i<m; i++){
		int a, b;
		int answer = 0;
		int count = 0;
				cin>>a>>b;
		for(int i=n-1; i>=n-4; i--){
			if(count == 2)
				break;
			mypair current = pairs[i];
			if(!(current.index == a || current.index == b)){
				answer += current.marks;
				count++;
			}
		}
		cout<<answer<<endl;
	}
}
