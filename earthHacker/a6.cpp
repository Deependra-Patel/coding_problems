#include <iostream>
#include <map>

using namespace std;
int main(){
    int test;
    cin>>test;
    for(int i=0; i<test; i++){
        int n, q;
        cin>>n>>q;
        map<int, int> map;
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            map[x] = j;
        }
        for(int j=0; j<q; j++){
            int a, b;
            cin>>a>>b;
            int x, y;
            x = map[a]-1;
            y = map[b]-1;
            int cnt = 0;
            bool notAncestor = true;

            if(y>=x){
                while(y>x){
                    y = (y-1)/2;
                    cnt++;
                }
                if(x == y)
                    notAncestor = false;
            }

            if(notAncestor){
                cout<<"not an ancestor"<<endl;
            }
            else {
                cout<<cnt<<"-ancestor"<<endl;
            }
        }
    }
}
