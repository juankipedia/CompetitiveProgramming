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

vector<int> g[100000];
int n, m, p[100000], U, V, arr[100000];
bool visited[100000];


int f(vector<int> &a, vector<int> &b){
	for(const int &e: a)
		arr[e] = 1;
	int ret = 0;
    for(const int &e: b)
		ret += arr[e];
	for(const int &e: a)
		arr[e] = 0;
	return ret;
}

void dfs(int v, vector<int> &a, vector<int> &b){
	if(visited[v]) return;
	visited[v] = true;
	a.push_back(v);
	b.push_back(p[v]);
	for(const int &u: g[v])
		dfs(u, a, b);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < m; i++){
        cin >> U >> V;
        U--; V--;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    int r = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> a, b;
            dfs(i, a, b);
            r += f(a, b);
        }
    }
    cout << r << endl;
    return 0;
}