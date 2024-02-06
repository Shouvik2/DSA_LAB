#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi (int n,char s, char h, char d){
    if(n==0) return;
    towerOfHanoi(n-1,s,d,h);
    cout<< s <<" -> "<<d<<endl;
    towerOfHanoi(n-1,h,s,d);
    return ;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    towerOfHanoi (n,'A','B','C');
}