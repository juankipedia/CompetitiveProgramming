const int MAXR = 1e3, MAXC = 1e3;

int S[MAXR][MAXC], M[MAXR][MAXC], n, m;
 
void build(){
    for(int i = 0; i < m; i++) S[0][i] = M[0][i];
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++) S[i][j] = M[i][j] + S[i - 1][j];
    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++) S[i][j] += S[i][j - 1];
}

// get sum in the sub-matrix with oppsite vertices at (a, b), (c, d)
int query(int a, int b, int c, int d){
    int res = S[c][d];
    if(a > 0) res = res - S[a - 1][d];
    if(b > 0) res = res - S[c][b - 1];
    if(a > 0 && b > 0) res = res + S[a - 1][b - 1];
    return res;
}
