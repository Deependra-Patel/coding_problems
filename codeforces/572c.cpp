#include <iostream>
using namespace std;
int ***arr;

int a1, b1, c1;
int ways(int a, int b, int c, int l){
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(l<0)
		return 0;
	if(arr[a-a1][b-b1][c-c1] != -1)
		return 0;
	int sum =0;
	if(a+b>c && a+c>b && b+c>a)
		sum = 1;
	if(l!=0)
		sum += ways(a+1, b, c, l-1)+ ways(a,b+1,c, l-1)+ways(a, b, c+1, l-1);
	arr[a-a1][b-b1][c-c1] = sum;
	return sum;
}

int main(){
	int a, b, c, l;
	cin>>a>>b>>c>>l;
	l++;
	arr = new int**[l];
	for(int i=0; i<l; i++){
		arr[i] = new int*[l];
		for(int j=0; j<l; j++){
			arr[i][j] = new int[l];
			for(int k =0; k<l; k++)
				arr[i][j][k] = -1;
		}
	}
	a1 = a;
	b1 = b;
	c1 = c;
	//cout<<"dfd"<<endl;
	cout<<ways(a, b, c, l-1)<<endl;
}
