#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pillar{
	int height;
	int index;
	bool done;
	int death;
	void print(){
		cout<<"index "<<index<<" height"<<height<<" death"<<death<<" done"<<done<<endl;
	}
};

bool cmp(const pillar*a, const pillar* b){
	if(a->done && !b->done)
		return false;
	else if(!a->done && b->done)
		return true;
	return (min(a->death,a->height) < min(b->height, b->death));
}

int main(){
	int n;
	cin>>n;
	pillar** arr = new pillar*[n];
	pillar** cpy = new pillar*[n];
	for(int i=0; i<n; i++){
		pillar* x = new pillar();
		x->index = i;
		x->done = false;
		cin>>(x->height);
		x->death = min(x->height, min(i+1, n-i));
		arr[i] = x;
		cpy[i] = x;
	}
	sort(cpy, cpy+n, cmp);
		
	for(int i=0; i<n; i++){
		pillar* low = cpy[0];
		if(low->done)
			break;
		low->done = true;
		int index = low->index;
		int de = low->height+1;
		for(int j=index-1; j>=0; j--, de++){
			if(arr[j]->death > de){
				arr[j]->death = de;
			}
			else break;
		}
		de = low->height+1;
		//cout<<index<<endl;
		for(int j=index+1; j<n; j++, de++){
			if(arr[j]->death > de){
				arr[j]->death = de;
			}
			else break;
		}
		//cout<<index<<endl;
		sort(cpy, cpy+n, cmp);
	}
	int maxi= 0;
	for(int i=0; i<n; i++){
		//		arr[i]->print();
		maxi = max(maxi, arr[i]->death);
	}
	cout<<maxi<<endl;
}
