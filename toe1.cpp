#include <iostream>
#include <string>
using namespace std;
bool checkdg(char arr[3][3], char x){
  int ans=0;
  if(arr[0][0]==x && arr[1][1]==x && arr[2][2]==x)
    ans++;
  if(arr[0][2]==x && arr[1][1]==x && arr[2][0]==x)
    ans++;
  for(int i=0; i<3; i++){
    if(arr[i][0]==x && arr[i][1]==x && arr[i][2]==x)
      ans++;
     if(arr[0][i]==x && arr[1][i]==x && arr[2][i]==x)
      ans++;
  }
  if((arr[0][0]==x && arr[1][1]==x && arr[2][2]==x) && (arr[0][2]==x && arr[1][1]==x && arr[2][0]==x))
    ans--;
  else if((arr[0][0]==x && arr[0][1]==x && arr[0][2]==x) && (arr[0][2]==x && arr[1][2]==x && arr[2][2]==x))
    ans--;
  else if((arr[0][2]==x && arr[1][2]==x && arr[2][2]==x) && (arr[2][2]==x && arr[2][1]==x && arr[2][0]==x))
    ans--;
  else if((arr[2][2]==x && arr[2][1]==x && arr[2][0]==x) && (arr[2][0]==x && arr[1][0]==x && arr[0][0]==x))
    ans--;
  else if((arr[2][0]==x && arr[1][0]==x && arr[0][0]==x) && (arr[0][0]==x && arr[0][1]==x && arr[0][2]==x))
    ans--; 
  return ans;
}

int main(){
  int ntest;
  cin>>ntest;
  while(ntest--){
    char arr[3][3];
    cin>>arr[0]>>arr[1]>>arr[2];
    bool ans=true;
    int cntx=0, cnto=0;
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
	if(arr[i][j]=='X')
	  cntx++;
	else if(arr[i][j]=='O')
	  cnto++;
      }
    }
    //cout<<cntx<<" "<<cnto<<endl;
    if(!(cntx-cnto==0 || cntx-cnto==1))
      ans=false;
    else {
      int retx=checkdg(arr, 'X');
      int rety=checkdg(arr, 'O');
      //cout<<retx<<" "<<rety<<endl;
      if(retx>1 || rety>1)
	ans=false;
      if(retx==1 && rety==1)
	ans=false;
      if(retx==1 && cntx-cnto!=1)
	ans=false;
      if(rety==1 && cntx!=cnto)
	ans=false;
    }
    if(ans)
      cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}