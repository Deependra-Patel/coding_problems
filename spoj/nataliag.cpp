#include <iostream>
#include <vector>
#include <string>
using namespace std;


int findout(int i, int j, vector<vector <char> > mat, int mini[], int c){
	int index=c*i+j;
	if(i==-1 || i==mat.size() || j==-1 || j==mat[0].size() || mat[i][j]=='*')
		return 10000;
	else if(mini[index]!=-1){
		//cout<<i<<j;
		return mini[index];
	}
	else {
		if(mat[i][j]=='#')
			{	
				mini[index]=0;
				return 0;
			}
		else {
			mat[i][j]='*';
			int i1=10000;
			int i2=10000;
			int i3=10000;
			int i4=10000;
			if(mat[i+1][j]!='*'){
				i1=findout(i+1,j,mat,mini, c);
			}
			if(mat[i][j+1]!='*')
				i2=findout(i,j+1,mat,mini,c);
			if(mat[i-1][j]!='*')
				i3=findout(i-1,j,mat, mini, c);
			if(mat[i][j-1]!='*')
				i4=findout(i, j-1, mat, mini, c);

			int temp= 1+min(min(i1, i2), min(i3, i4));
			mini[index]=temp;
			return temp;
		}
	}
}

int main()
{
	/* code */
	int z;
	cin>>z;
	for(int i=0; i<z; i++){
		int m, n;
		cin>>m>>n;
		vector<vector<char> > v;
		int mini[m*n];
		int x1, x2;
		for(int p=0; p<m; p++){
			std::vector<char> temp;
			vector<int> temp2;
			string s;
			cin>>s;
			for(int q=0; q<n; q++){
				char ch=s[q];
				temp.push_back(ch);
				mini[p*n+q]=-1;
				//temp2.push_back(10000);
				if(ch=='$'){
					x1=p;
					x2=q;
				}
			}
			//mini.push_back(temp2);
			v.push_back(temp);
		}
		cout<<"gh";
		int x=findout(x1, x2, v, mini, n);
		/*for(int i=0; i<m*n; i++){
			cout<<mini[i]<<endl;
		}*/
		if(x>=10000)
			cout<<-1;
		else cout<<x;
		cout<<endl;
	}
	return 0;
}