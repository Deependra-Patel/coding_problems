#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void partition(vector <int>  ar) {
    int first=ar[0];
    list<int> left, right;
    for(int i=0; i<ar.size(); i++){
        if(first>ar[i])
            left.push_back(ar[i]);
        else if(first<ar[i])right.push_back(ar[i]);
    }
    list<int>::iterator il=left.begin();
    for(;il!=left.end(); il++){
        cout<<(*il)<<" ";
    }
    cout<<first<<" ";
    il=right.begin();
    for(;il!=right.end(); il++){
        cout<<(*il)<<" ";
    }
}
/* Tail starts here */
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

partition(_ar);
   
   return 0;
}
