#include <iostream>
using namespace std;

int* y0;//add
int* y1;//-2 passed, -1 unstable, 0+= stable

int* a;
int  n;
bool add;
int sumOfY(int x, bool add){
	//	cout<<x<<endl;
	if(x>n || x<=0)
		return 0;
	if(add){
		if(y0[x]>=1)
			return y0[x];
		if(y0[x] == -2){
			y0[x] = -1;
			return -1;
		}
		y0[x] = -2;
		int temp = sumOfY(x+a[x], !add);
		if(temp == -1){
			y0[x] = -1;
		}
		else y0[x] = a[x] + temp;
		return y0[x];
	}
	else {
		if(y1[x]>=1)
			return y1[x];
		if(y1[x] == -2){
			y1[x] = -1;
			return -1;
		}
		y1[x] = -2;
		int temp = sumOfY(x-a[x], !add);
		if(temp == -1){
			y1[x] = -1;
		}
		else y1[x] = a[x] + temp;
		return y1[x];
	}
}

int main(){
	cin>>n;
	a = new int[n+1];
	y0 = new int[n+1];
	y1 = new int[n+1];
	for(int i=2; i<=n; i++){
		cin>>a[i];
		y0[i] = y1[i] = 0;
	}
	
	y1[0] = 0;
	y0[1]=y1[1] = 0;
	for(int i=1; i<=n-1; i++){
		a[1] = i;
		y0[1] = -2;
		int temp = sumOfY(i+1, false);
		if(temp == -1)
			cout<<-1<<endl;
		else cout<<temp+i<<endl;
		if(y0[1] != -2){
			for(int i=0; i<=n; i++){
				y0[i] = y1[i] = 0;
			}				
		}
		//for(int i=1; i<=n; i++)
			//	cout<<y0[i]<<"  "<<y1[i]<<endl;
	}
}
