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
const double INF = numeric_limits<double>::max();

int m, n, in, ti;
double x[15][15], p[15], a[15], per, mp[32768];
int mt[32768];

double dis(ulli bm, int i){
    double d = 1;
    for(int j = 0; j < m; j ++)
        if(!(bm & (1 << j))) d *= x[j][i];

    return d;
}

double f(ulli bm){
    double mini = INF, fs;
    ulli nbm;
    if(mt[bm] == ti) return mp[bm];
    mt[bm] = ti;
    for(int i = 0; i < m; i ++){
        if(!(bm & (1 << i))){
            nbm = bm | (1 << i);
            fs = f(nbm);
            if(fs == INF)
                mini = min(mini, p[i]);
            else
                mini = min(mini, p[i] * dis(nbm, i) + fs);
        }
    }
    
    mp[bm] = mini;
    return mini;
}

int main() {
    while(cin >> m && m != 0){
        ti++;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++) x[i][j] = 1;
        for(int i = 0; i < m; i++){
            scanf("%lf %lf %d", &p[i], &a[i], &n);
            for(int j = 0; j < n; j++){
                scanf("%d %lf", &in, &per);
                in --;
                x[i][in] *= (100 - per) / 100; 
            }
        }
        f(0);
        double mini = INF, area;
        for(int bm = 0; bm < ((1 << m) - 1); bm++){
            area = 0;
            for(int i = 0; i < m; i++)
                if(!(bm & (1 << i)))
                    area += a[i];
            mini = min(mp[bm] / area, mini);
        }
        printf("%.4lf\n", mini);
    }
    return 0;
}