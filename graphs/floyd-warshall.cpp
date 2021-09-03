/**
 * FLOYD WARSHALL.
 * 
 * Find shortest paths between all possible pair of vertices.
 * 
 * V: number of vertices.
 * time complexity: O(V^3)
 * 
 * */

const int MAXN = 100000;
const int oo = numeric_limits<int>::max();
int g[MAXN][MAXN], N;

void floyd_warshall(){
    int dist[N][N];
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            dist[i][j] = g[i][j];
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
  
    // If dist[i][j] = oo then there is no path from i to j
}