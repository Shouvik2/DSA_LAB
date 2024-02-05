#include<bits/stdc++.h>
using namespace std;
int fibo (int n){
    if(n==1 || n==2)return 1; 
    int ans1 = fibo(n-1);
    int ans2 = fibo(n-2);
    int ans = ans1 + ans2;
    return ans;
}
int main (){
    int x;
    cout<<"Enter a number : ";
    cin>>x;
    fibo(x);
}