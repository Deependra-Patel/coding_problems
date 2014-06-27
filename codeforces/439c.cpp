#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
#include <iomanip>
#include <algorithm>
using namespace std;
int main(){
	int n, k, p;
	cin>>n>>k>>p;
	int * arr=new int[n];
	vector<int> even;
	vector<int> odd;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]%2==0)
			even.push_back(arr[i]);
		else 
			odd.push_back(arr[i]);
	}
	bool poss=true;
	int ne=even.size();
	int no=odd.size();
	if(ne+no/2<p)
		poss=false;
	else if(k-p>no)
		poss=false;
	else if((k-p)%2==1 && no%2==0)
		poss=false;
	}
}