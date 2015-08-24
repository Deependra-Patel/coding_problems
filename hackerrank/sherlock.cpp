#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double l, s1, s2;
    cin>>l>>s1>>s2;
    int t;
    cin>>t;
    while(t--){
        double q;
        cin>>q;
        cout<<(sqrt(2)*l-sqrt(2*q))/abs(s1-s2)<<endl;
    }
    return 0;
}

