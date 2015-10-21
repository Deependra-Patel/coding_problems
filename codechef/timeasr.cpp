#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double absd(double a){
	if(a>0)
		return a;
	else return -a;
}

int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
	    double a;
		scanf("%lf", &a);
		for(int i=0; i<720; i++){
			double temp = absd(6*(i%60) - double(i)/2);
			if(temp > 180)
				temp = 360 - temp;
			if(absd(a-temp) <= double(1)/120){
				//cout<<abs(0.4-0.7);//6*(i%60);// - double(i/2);
				if(i/60 <= 9){
					if(i%60 < 10)
						printf("0%d:0%d\n", i/60, i%60);
					else printf("0%d:%d\n", i/60, i%60);
				}
				else {
					if(i%60 < 10)
						printf("%d:0%d\n", i/60, i%60);
					else printf("%d:%d\n", i/60, i%60);
				}
			}
		}
	}
}
