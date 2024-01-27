// Postfix Evaluation
#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;
int solve(int val1,int val2,int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else if(ch=='/') return val1/val2;
    else return pow(val1,val2);
}
int main(){
    string s;//Postfix expression
    getline(cin,s);
    //we need one stack -> values
    stack<int> val;
    for(int i=0;i<s.length();i++){
        //check if s[i] is a digit (0-9)
        if(s[i]>=48 && s[i]<=57){//digit
            val.push(s[i]-48);//ascii-ascii
        }
        else{ // s[i] it is -> ^,*,/,+,-
            // kaam
            int val2=val.top();
            val.pop();
            int val1=val.top();
            val.pop();
            int ans=solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
}