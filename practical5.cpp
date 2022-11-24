#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

void askChoice(){
    cout<<"\n1.Infix To Postfix";
    cout<<"\n2.Infix To Prefix";
    cout<<"\n3. Postfix Evaluation";
    cout<<"\n4. Exit";
    cout<<"\nEnter choice: ";
}
string reverseStr(string s){
    string res = "";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i] == '(')
            res += ')';
        else if(s[i] == ')')
            res += '(';
        else
            res += s[i];
    }
    return res;
}

int priority(char ch){
    if(ch=='+' || ch=='-')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 1;

    return 0;
}

string convert(string infix){
    stack <int>s;
    string postfix = "";
    int i=0;

    while(i<infix.length()){
        if(infix[i]>='a'&&infix[i]<='z'||infix[i]>='A'&&infix[i]<'Z'){
            postfix += infix[i++];

        }else if(infix[i] == '('){
            s.push(infix[i++]);

        }else if(infix[i] == ')'){
            while(s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }else{
            while(!s.empty() && priority(s.top()) >= priority(infix[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i++]);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
//Postfix Evaluation
float evalPostfix(string postfix){
    int i=0;
    stack <float>s;
    while(i < postfix.length()){
        if(postfix[i]>='0' && postfix[i]<= '9'){
            s.push((int(postfix[i++])-'0'));
        }
        else{
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            switch(postfix[i]){
            case '+':
                s.push((a + b));
                break;
            case '-':
                s.push((a - b));
                break;
            case '*':
                s.push((a * b));
                break;
            case '/':
                s.push((a / b));
                break;
            case '^':
                s.push(pow(a,b));
                break;
            default:
                return -1;
            }
            i++;
        }
    }
    return (s.top());
}
//Driver Code
int main(){
    string infix,prefix,postfix;
    int ch;
    do{
        askChoice();
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\nEnter infix string: ";
            cin>>infix;
            cout<<"\nInfix:\n"<<infix<<"\n\nPostfix:\n"<<convert(infix)<<endl;
            break;
        case 2:
            cout<<"Enter infix string: ";
            cin>>infix;
            cout<<"\nInfix:\n"<<infix;
            infix = reverseStr(infix);
            prefix = convert(infix);

            prefix = reverseStr(prefix);
            cout<<"\n\nPrefix:\n"<<prefix;
            break;
        case 3:
            cout<<"\nEnter postfix string to be evaluated: ";
            cin>>postfix;
            cout<<evalPostfix(postfix)<<endl;
            break;
        case 4:
            break;
        }
    cout<<"\n---------------------------\n";
    }while(ch!=4);

    return 0;
}
