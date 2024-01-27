// Infix to Postfix
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int priority(char ch){
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/') return 2;
    else return 3;
}
string solve(string val1,string val2,char ch){
    //we have to store postfix in the ans
    //postfix is ->  v1 v2 op
    string s="";
    s+=val1;
    s+=val2;
    s.push_back(ch);
    return s;
}
int main(){
    string s;//infix expression
    getline(cin,s);
    //we need two stacks, 1 for vals, 1 for ops
    stack<string> val;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        //check if s[i] is a digit (0-9)
        if(s[i]>=48 && s[i]<=57){//digit
            val.push(to_string(s[i]-48));//ascii-ascii
        }
        // check if s[i] is an alphabet
        else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            string str="";
            str.push_back(s[i]);
            val.push(str);
        }
        else{ // s[i] it is -> *,/,+,-
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    //work
                    char ch=op.top();
                    op.pop();
                    string val2=val.top();
                    val.pop();
                    string val1=val.top();
                    val.pop();
                    string ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();// opening bracket ko bhi uda diya
            }
            else if(priority(s[i])>priority(op.top())) op.push(s[i]);
            else{//work , priority(s[i]) <= priority(op.top())
                while(op.size()>0 && priority(s[i]) <= priority(op.top())){
                    // i have to do val1 op val2
                    char ch=op.top();
                    op.pop();
                    string val2=val.top();
                    val.pop();
                    string val1=val.top();
                    val.pop();
                    string ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // the operator stack can have vals.
    // so make it empty
    while(op.size()>0){
        //work
        char ch=op.top();
        op.pop();
        string val2=val.top();
        val.pop();
        string val1=val.top();
        val.pop();
        string ans=solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top()<<endl;
}