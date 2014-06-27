#include <iostream>
#include <vector>
using namespace std;
struct dual{
	int path_length;
	int treasure;
	dual(){
	}
	dual(int path_length, int treasure){
		this->path_length=path_length;
		this->treasure=treasure;
	}
};
int nt;

dual compute(vector<vector<char> > mat, int x, int y){
	int n=mat[0].size();
	dual cur;
	cur.path_length=0;
	cur.treasure=0;
	if(x==n-1 && y==n-1)
		return cur;
	if(mat[x][y]=='i')
		mat[x][y]='j';
	else if(mat[x][y]=='j' || mat[x][y]=='#' || x>n-1 || x<0 || y>n-1 || y<0)
		return dual(100000000, -1);
	else if(mat[x][y]=='.')
		mat[x][y]='i';
	else if(mat[x][y]=='*'){
		mat[x][y]='i';
		cur.treasure=1;
	}
	dual v1=compute(mat, x+1, y);
	dual v2=compute(mat, 1, y+1);
	dual v3=compute(mat, x-1, y);
	dual v4=compute(mat, x, y-1);
	return v1;
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		vector<vector<char> > mat;
		nt=0;
		for(int i=0; i<n; i++){
			vector<char> v;
			for(int j=0; j<n; j++){
				cin>>v[j];
				if(v[j]=='*')
					nt++;
			}
			mat.push_back(v);
		}
	}
}