#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int** dp;
int** dp2;
int n;
int calc(int index, int* arr,  int maxTill, int maxN){
	if(index >= n)
		return 0;
	if(dp[maxTill][index]!=-1)
		return dp[maxTill][index];
	int x = arr[index];
	if(x>maxN){
		return calc(index+1, arr, maxTill, maxN);
	}
	if(x>=maxTill){
		int ans = calc(index+1, arr, max(maxTill, x), maxN)+1;
		int ans2 = calc(index+1, arr, maxTill, maxN);
		dp[maxTill][index] = max(ans, ans2);		
	}
	else {
		int ans2 = calc(index+1, arr, maxTill, maxN);
		dp[maxTill][index] =  ans2;		
	}
	return dp[maxTill][index];
}
int calc2(int index, int* arr,  int minTill, int maxN){
	if(index >= n)
		return 0;
	if(dp2[minTill][index]!=-1)
		return dp2[minTill][index];
	int x = arr[index];
	if(x<maxN){
		return calc2(index+1, arr, minTill, maxN);
	}
	if(x>=minTill){
		int ans = calc2(index+1, arr, max(minTill, x), maxN)+1;
		int ans2 = calc2(index+1, arr, minTill, maxN);
		dp2[minTill][index] = max(ans, ans2);		
	}
	else {
		int ans2 = calc2(index+1, arr, minTill, maxN);
		dp2[minTill][index] =  ans2;		
	}
	return dp2[minTill][index];
}


int main(){
	int t;
	cin>>n>>t;
	int ans = 0;
	int* arr = new int[n];
	int* cnt = new int[300];
	for(int i=0; i<300; i++)
		cnt[i] = 0;
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
		cnt[arr[i]-1]++;
	}
	int maxN;
	int maxFreq = 0;
	for(int i=0; i<300; i++){
		if(maxFreq<=cnt[i]){
			maxFreq = cnt[i];
			maxN = i+1;
		}
	}
	dp = new int*[300];
	dp2 = new int*[300];
	for(int i=0; i<300; i++){
		dp[i] = new int[n];
		dp2[i] = new int[n];
		for(int j=0; j<n; j++){
			dp[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	ans = maxFreq*(t-2);
	//	cout<<maxN;
	int first = calc(0, arr,  0, maxN);
		
	if(t == 1){
		cout<<first<<endl;
	}
	else if(t==2){

	}
	else if(t>2){
		int last = calc2(0, arr,  0, maxN);
	//cout<<first<<endl;
		ans += first + last;
		cout<<ans<<endl;
	}

}
