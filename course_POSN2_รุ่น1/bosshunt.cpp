#include<bits/stdc++.h>

using namespace std;

struct boss {
    int s , p , w ;
    bool operator < (const boss & rhs)const {
        return p < rhs.p ;
    }
};

boss arr[100001] ;

int dp[100001]  , n ; 

int solve(int idx , boss temp){

    int l = 0 , r = idx , start = temp.s;

    while(l < r){
        int mid = (l + r + 1) >> 1 ;
        if(arr[mid].p >= start){
            r = mid - 1 ;
        }
        else {
            l = mid ;
        }
    }

    return dp[l] ;
};

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i].s >> arr[i].p >> arr[i].w ;
    }

    sort(arr + 1 , arr + n + 1) ;

    for(int i = 1 ; i <= n ; i ++ ){
        dp[i] = max(dp[i - 1] , arr[i].w + solve(i - 1 , arr[i])) ;
    }

    cout << dp[n] ;

    return 0 ;
}