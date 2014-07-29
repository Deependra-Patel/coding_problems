#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n!=0){
		//int n;
		//cin>>n;
		int * arr = new int[n+1];
		bool * implies = new bool[n+1];
		arr[1]=1;
		bool ans=true;
		for(int i=1; i<=n; i++){
			int j;
			string s;
			cin>>j>>s;
			if(j==i && s=="false"){
				ans=false;
				//cout<<"hi";
			}
			else {
				arr[i] = j;
				implies[i] = (s=="true");
			}
		}					
		if(ans){
			bool * fixed_val = new bool[n+1];
			fixed_val[1] = true;
			int cur_index = 1;
			int next_index = arr[cur_index];
			int group = -1;
			while(true){
				next_index = arr[cur_index];
				if(arr[next_index] <= -1 || next_index==cur_index){
					if(arr[next_index] == group){
//cout<<cur_index<<" n"<<next_index<<endl;
						if(fixed_val[cur_index]){
							if(implies[cur_index] != fixed_val[next_index]){
								ans=false;
								break;
							}
						}
						else {
							//cout<<cur_index;
							if(implies[cur_index] == fixed_val[next_index]){
								ans=false;
								break;
							}
						}
					}
					int i;		
					for(i=1; i<=n; i++){
						if(arr[i]>=1){
							cur_index = i;
							group --;
							fixed_val[cur_index] = true;
						}
					}
					if(i==n+1){
						//ans = true;
						break;
					}
				}
				else {
					//cout<<cur_index<<endl<<next_index<<endl;
					if(fixed_val[cur_index]){
						fixed_val[next_index] = implies[cur_index];
					}
					else fixed_val[next_index] = !implies[cur_index];
					arr[cur_index] = group;
					cur_index = next_index;
				}
			}
		}
			if(ans)	
				cout<<"NOT PARADOX"<<endl;
			else cout<<"PARADOX"<<endl;
		cin>>n;
	}
}
				
