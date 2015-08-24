#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k, t;
    cin>>n>>k>>t;
	bool* arr = new bool[n];
	string str;
	vector<int> pos1;
	cin>>str;
    for(int i=0; i<n; i++){
		arr[i] = str[i] == '1';
        if(arr[i])
            pos1.push_back(i);
    }
	int s = pos1.size();
    for(int i=0; i<s; i++){
        int pos = pos1[i];
        while(pos-k>=0 && t){
            if(arr[pos - k])
                break;
            pos -= k; 
            t--;
        }
        arr[pos1[i]] = false;
        arr[pos] = true;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}
