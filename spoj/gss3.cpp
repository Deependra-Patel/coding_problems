#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int n;
int* maxi;
int* total;
int* maxiFront;
int* maxiBack;

struct fourD{
	int mxi, ttal, mxiFront, mxiBack;
	fourD(int a, int b, int c, int d){
		mxi = a;
		ttal = b;
		mxiFront = c;
		mxiBack = d;
	}
	fourD(){}
};

fourD getFour(int index){
	return fourD(maxi[index], total[index], maxiFront[index], maxiBack[index]);
}


int mid(int a, int b){ return (a+b)/2;}
void fillTree(int* arr, int ss, int se, int index){
	if(ss == se){
		maxi[index] = total[index] = maxiFront[index] = maxiBack[index] = arr[ss];
	}
	else {
		int l = 2*index +1;
		int r = l + 1;
		fillTree(arr, ss, mid(ss, se), l);
		fillTree(arr, mid(ss, se)+1, se, r);
		total[index] = total[l] + total[r];
		maxiFront[index] = max(maxiFront[l], total[l] + maxiFront[r]);
		maxiBack[index] = max(maxiBack[r], total[r] + maxiBack[l]);
		maxi[index] = max(max(maxi[l], maxi[r]), maxiBack[l]+maxiFront[r]);
	}
}

fourD findMax(int i, int j, int ss, int se, int index){
	fourD f;
	//	cout<<i<<" "<<j<<" ";
	if(i<=ss && se<=j){
		return getFour(index);
	}
	else if(i>se || j<ss){
		//		cout<<"d";
		return fourD(-1000000000, 0, -1000000000, -1000000000);
	}
	else {
			fourD l = findMax(i, j, ss, mid(ss, se), 2*index+1);
			fourD r = findMax(i, j, mid(ss, se)+1, se, 2*index+2);
			if(l.mxi == -1000000000){
				return r;
			}
			else if(r.mxi == -1000000000){
				return l;
			}
			else {
				f.mxiFront = max(l.mxiFront, l.ttal+r.mxiFront);
				f.mxiBack = max(l.mxiBack + r.ttal, r.mxiBack);
				f.ttal = l.ttal + r.ttal;
				f.mxi = max(max(l.mxi, r.mxi), l.mxiBack+r.mxiFront);
			}
			return f;
	}
}

void updateTree(int ss, int se, int index, int i, int val){
	if(i == ss && i == se){
		maxi[index] = total[index] = maxiFront[index] = maxiBack[index] = val;
	}
	else if(i < ss || i>se)
		return;
	else {
		int l = 2*index +1;
		int r = l + 1;
		updateTree(ss, mid(ss, se), l, i, val);
		updateTree(mid(ss, se)+1, se, r, i, val);
		total[index] = total[l] + total[r];
		maxiFront[index] = max(maxiFront[l], total[l] + maxiFront[r]);
		maxiBack[index] = max(maxiBack[r], total[r] + maxiBack[l]);
		maxi[index] = max(max(maxi[l], maxi[r]), maxiBack[l]+maxiFront[r]);
	}		
}


int main(){
	cin>>n;
	int size = pow(2, (ceil(log2(n))+1)) - 1;
	maxi = new int[size];
	maxiFront = new int[size];
	maxiBack = new int[size];
	total = new int[size];
	int* arr = new int[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	fillTree(arr, 0, n-1, 0);
	int m;
	cin>>m;
	/*	for(int i=0; i<size; i++)
		cout<<maxi[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<size; i++)
		cout<<total[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<size; i++)
		cout<<maxiFront[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<size; i++)
		cout<<maxiBack[i]<<" ";
	*/
	while(m--){
		int x, y, t;
		//		cin>>x>>y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1){
			fourD f = findMax(x-1, y-1, 0, n-1, 0);
			//cout<<f.mxi<<" "<<f.ttal<<" "<<f.mxiFront<<" "<<f.mxiBack<<endl;
			//cout<<f.mxi<<endl;
			printf("%d\n", f.mxi);
		}
		else updateTree(0, n-1, 0, x-1, y);
	}
}
