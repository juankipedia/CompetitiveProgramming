/**
 * FLOYD WARSHALL.
 * 
 * Find shortest paths between all possible pair of vertices.
 * 
 * V: number of vertices.
 * time complexity: O(V^3)
 * 
 * */

const int MAXN = 1000, oo = numeric_limits<int>::max();
int g[MAXN][MAXN], N, dist[MAXN][MAXN];

void floyd_warshall(){
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            dist[i][j] = g[i][j];
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
}