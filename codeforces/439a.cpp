#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
#include <iomanip>
using namespace std;
int main(){
	int n, d;
	cin>>n>>d;
	int sum=0;
	int temp=n;
	while(temp--){
		int x;
		cin>>x;
		sum+=x;
	}
	if(sum+(n-1)*10>d)
		cout<<-1<<endl;
	else {
		cout<<(d-sum)/5<<endl;
	}
}