#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;
#define mod 1000000007
int calcRoot(char *arr, int size){
	
}

int main(){
	string str;
	cin>>str;
	while(str!="*"){		
		cin>>str;
		char tab2[str.length()];
		strcpy(tab2, str.c_str());
		calcRoot(tab2, str.length());
	}
}
