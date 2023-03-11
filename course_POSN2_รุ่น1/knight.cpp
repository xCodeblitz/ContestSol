#include<bits/stdc++.h>

using namespace std;

struct coordinate {
    int x , y ;
};

int graph[1001][1001] , m , n ;
coordinate dir[8]  = { {-2 , 1} , {-1 , 2} , {1 , 2} , {2 , 1} , {2 , -1} , {1 , -2} , {-1 , -2} , {-2 ,-1} };

int bfs(coordinate src , coordinate dest){

    for(int i = 1 ; i <= 1000 ; i ++ ){
        for(int j = 1 ; j <= 1000 ; j ++ ){
            graph[i][j] = INT_MAX ;
        }
    }

    queue<coordinate>q ;
    graph[src.x][src.y] = 0 ;
    q.push(src) ;

    while(!q.empty()){

        auto temp = q.front();
        q.pop() ;

        if(temp.x == dest.x && temp.y == dest.y){
            break ;
        }

        for(int i = 0 ; i < 8 ; i ++ ){
            int nowx = temp.x + dir[i].x , nowy = temp.y + dir[i].y ;
            if(nowx <= 0 || nowy <= 0 || nowx > m || nowy > n)continue ;
            if(graph[nowx][nowy] <= graph[temp.x][temp.y] + 1)continue ;
            graph[nowx][nowy] = graph[temp.x][temp.y] + 1;
            q.push({nowx , nowy}) ;
        }
    }

    return graph[dest.x][dest.y] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    coordinate a , b , c ;

    cin >> m >> n >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y ;

    cout << bfs(a , b) + bfs(b , c) ;

    return 0 ;
}