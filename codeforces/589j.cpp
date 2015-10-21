#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	char** arr = new char*[n];
	int movex[] = {0, 1, 0, -1};
	int movey[] = {-1, 0, 1, 0};
	int dir;
	int x, y;
	for(int i=0; i<n; i++){
		arr[i] = new char[m];
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
			char cur = arr[i][j];
			if(cur != '*' && cur!='.'){
				y = i;
				x = j;
				if(cur == 'U') dir = 0;
				if(cur == 'R') dir = 1;
				if(cur == 'D') dir = 2;
				if(cur == 'L') dir = 3;
			}
		}
	}
	int sum = 1;
	int howmany = 1000001;
	while(howmany){
		howmany--;
		int newx = x+movex[dir];
		int newy = y+movey[dir];
		if(newx>=0 && newx<m && newy>=0 && newy<n && arr[newy][newx]!='*'){
			x = newx;
			y = newy;
			if(arr[y][x] == '.')
				sum++;
			arr[newy][newx] = '-';
		}
		else {
			int i;
			for(i=1; i<=3; i++){
				int tempdir = (dir+i)%4;
				newx = x+movex[tempdir];
				newy = y+movey[tempdir];
				if(newx>=0 && newx<m && newy>=0 && newy<n && arr[newy][newx]!='*'){
					x = newx;
					y = newy;
					if(arr[y][x] == '.')
						sum++;
					arr[newy][newx] = '-';
					dir = tempdir;
					break;
				}
			}
			//	else break;
		}
	}
	//	cout<<howmany;
	cout<<sum<<endl;

}
