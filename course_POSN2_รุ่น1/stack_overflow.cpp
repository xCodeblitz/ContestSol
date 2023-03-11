#include<bits/stdc++.h>
#define st first
#define nd second
#define ll long long
#define vec vector
using namespace std;
const int N = 2e5+2;
int n, t, x, check, ans;
string ss;
stack<int>s;
void calc(){
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if((b==1 && a==2 && x==3) || (b==2 && a==1 && x==1) || (b==3 && a==1 && x==2) || (b==1 && a==1 && x==3)){
        check=1;
        ans+=3;
    }
    else{
        s.push(b);
        s.push(a);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> ss;
    for(int i=0; i<n; i++){
        x = ss[i]-'0';
        check=0;
        if(!s.empty() && x==2 && s.top()==2){
            s.pop();
            check=1;
            ans+=2;
        }
        else if(s.size()>=2){
            calc();
        }
        if(!check) s.push(x);
    }
    cout << ans << '\n';    
    
}