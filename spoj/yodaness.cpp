#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
long long merge(long long* arr1, long long* arr2, long long* merged, long long len1, long long len2){
  long long ind1=0, ind2=0;
  long long inversions=0;
  while(ind1<len1 && ind2<len2){
    if(arr1[ind1]<arr2[ind2]){
      merged[ind1+ind2]=arr1[ind1];
      ind1++;
    }
    else {
      merged[ind1+ind2]=arr2[ind2];
      ind2++;
      inversions+=len1-ind1;
    }
  }/*
  if(ind1<len1){
    merged[ind1+ind2]=arr1[ind1];
    ind1++;
    }*/  
  while(ind1<len1){
    merged[ind1+ind2]=arr1[ind1];
    ind1++;
    //inversions+=len2;
  }
  while(ind2<len2){
    merged[ind1+ind2]=arr2[ind2];
    ind2++;
  }
  //cout<<inversions<<"haha";
  return inversions;
}

long long inv_pair(long long* arr, long long n){
  if(n==1){
    return 0;
  }
  long long half=n/2;
  // long long mid=arr[half];
  long long i1, i2, sum=0;
  i1=inv_pair(arr, half);
  i2=inv_pair(arr+half, n-half);
  long long* temp=new long long[n];
  sum+=i1+i2+merge(arr, arr+half, temp, half, n-half);
  for(long long i=0; i<n; i++)
    arr[i]=temp[i];
  return sum;
}
int main(){
  long long ntest;
  cin>>ntest;
  while(ntest--){
    long long n;
    cin>>n;
    long long * arr=new long long[n];
    for(long long i=0; i<n; i++){
      cin>>arr[i];
    }
    //for(long long i=0; i<n; i++)
    //  cout<<arr[i]<<endl;
    cout<<inv_pair(arr, n)<<endl;
    //cout<<"after"<<endl;
    // for(long long i=0; i<n; i++)
    // cout<<arr[i]<<endl;
  }
}
