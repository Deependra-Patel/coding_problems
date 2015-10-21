#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	bool** arr = new bool*[n];
	int* rel = new int[n];
	for(int i=0; i<n; i++){
		rel[i] =  0;
		arr[i] = new bool[n];
			for(int j=0; j<n; j++){
				arr[i][j] = false;
			}
			
	}
	vector<int> av, bv;

  
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		av.push_back(a-1);
		bv.push_back(b-1);
		rel[a-1]++;
		rel[b-1]++;
		arr[a-1][b-1] = true;
		arr[b-1][a-1] = true;
	}
	int mini = 1000000000;
	/*	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
		}*/
	for(int i=0; i<m ;i++){
		int a = av[i];
		int b = bv[i];
		int temp = rel[a]+rel[b];
		//
		for(int j=0; j<n; j++){
			if(arr[j][a] && arr[j][b]){
				//		cout<<"erere";
				mini = min(mini, temp+ rel[j]);
			}
		}
	}
	if(mini == 1000000000)
		cout<<-1<<endl;
	else cout<<mini-6<<endl;
}
