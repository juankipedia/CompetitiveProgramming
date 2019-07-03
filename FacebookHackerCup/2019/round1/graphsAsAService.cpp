#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;
const int MAXM = 1000;
const int MAXN = 51;
const int INF  = 1e6 + 1;
int T, N, M, Xi, Yi, Zi; 
int g[MAXN][MAXN], dist[MAXN][MAXN];
tuple<int, int, int> r[MAXM];

void set_g(){
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= N; ++j){
			g[i][j] = INF;
		}
	}
}

void f_w(){  
    int i, j, k;  
    for (i = 1; i <= N; i++)  
        for (j = 1; j <= N; j++)  
            dist[i][j] = g[i][j];  

    for (k = 1; k <= N; k++){ 
        for (i = 1; i <= N; i++){  
            for (j = 1; j <= N; j++){ 
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }
}  


int main() {
	cin >> T;
	for(int k = 1; k <= T; k++){
		cin >> N >> M;
		set_g();
		for (int i = 0; i < M; ++i){
			cin >> Xi >> Yi >> Zi;
			g[Xi][Yi] = Zi;
			g[Yi][Xi] = Zi;
			r[i] = make_tuple(Xi, Yi, Zi);
		}
		f_w();
		bool f = true;
		for (int i = 0; i < M; ++i){
			if(dist[get<0>(r[i])][get<1>(r[i])] != get<2>(r[i])){
				cout << "Case #" << k << ": ";
				cout << "Impossible" << endl;
				f = false;
				break;
			}
		}
		if(f){
			cout << "Case #" << k << ": ";
			cout << M << endl;
			for (int i = 0; i < M; ++i)
				cout << get<0>(r[i]) << " " << get<1>(r[i]) << " " << get<2>(r[i]) << endl; 
		}
	}
    return 0;
}