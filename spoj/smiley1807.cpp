#include <iostream>
#include <map>
using namespace  std;

int l;
string str;
map<char, int> charMap;
char numMap[] = {'1','8', '0', '7'};

void getMax(int** maxi){
	
	if(str[l-1] == '7')
		maxi[3][l-1] = 1;
	else maxi[3][l-1] = 0;
	maxi[0][l-1] = maxi[1][l-1] = maxi[2][l-1] = 0;
	
	for(int index=l-2; index>=0; index--){
		char ch = str[index];
		if(charMap[ch] != 3){
			int temp = max(maxi[charMap[ch]][index+1],
						   maxi[charMap[ch]+1][index+1]);
			if(temp != 0)
				temp++;			
			maxi[charMap[ch]][index] = temp;
			for(int i=0; i<4; i++){			
				if(i!=charMap[ch])maxi[i][index] = maxi[i][index+1];
			}
		}
		else {
			int temp = maxi[3][index+1];
			for(int i=0; i<4; i++){			
				if(i!=charMap[ch])maxi[i][index] = maxi[i][index+1];
			}
			maxi[3][index] = temp+1;
		}	 
	}
}

int main(){
	cin>>str;
	charMap['1'] = 0;
	charMap['8'] = 1;
	charMap['0'] = 2;
	charMap['7'] = 3;

	l = str.length();
	int** maxi = new int*[4];
	for(int i=0; i<4; i++){
		maxi[i] = new int[l];
		for(int j=0; j<l; j++)
			maxi[i][j] = -1;
	}
	getMax(maxi);
	/*	for(int i=0; i<4; i++){
		for(int j=0; j<l; j++)
			cout<<maxi[i][j]<<" ";
		cout<<endl;
		}
	*/cout<<maxi[0][0]<<endl;
}
