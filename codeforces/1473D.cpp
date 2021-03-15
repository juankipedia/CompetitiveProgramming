# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2e5 + 5, LOG2N = 18;

int lg2[MAXN + 1], N, M;

void build(std::function<int(int, int)> f, int st[][LOG2N + 1], int a[]){
    lg2[1] = 0;
    for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
    for(int i = 0; i < N; i++) st[i][0] = a[i];
    for(int j = 1; j <= LOG2N; j++)
        for(int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int minimum(int L, int R, int st[][LOG2N + 1]){
    int lg = lg2[R - L + 1];
    return min(st[L][lg], st[R - (1 << lg) + 1][lg]);
}

int maximum(int L, int R, int st[][LOG2N + 1]){
    int lg = lg2[R - L + 1];
    return max(st[L][lg], st[R - (1 << lg) + 1][lg]);
}

int t, sum[MAXN];
string s;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N >> M >> s;
        sum[0] = 0;
        N++;
        for(int i = 1; i < N; i++){
            sum[i] = sum[i - 1];
            if(s[i - 1] == '+') sum[i] += 1;
            else sum[i] += -1;
        }
        
        int mini[N][LOG2N + 1], maxi[N][LOG2N + 1];
        for(int i = 0; i < N; i++)
            for(int j = 0; j <= LOG2N + 1; j++)
                mini[i][j] = maxi[i][j] = 0;
        
        build([](int a, int b){return max(a, b);}, maxi, sum);
        build([](int a, int b){return min(a, b);}, mini, sum);
        
        int l, r;
        while(M--){
            cin >> l >> r;
            int lhs = 0, rhs = 0;


            set<int> ss;
            ss.insert(0);




            if(l > 1){
                ss.insert(maximum(1, l - 1, maxi));
                ss.insert(minimum(1, l - 1, mini));
            }
            if(r < N - 1){
                ss.insert(maximum(r + 1, N - 1, maxi) - (sum[r] - sum[l - 1]));
                ss.insert(minimum(r + 1, N - 1, mini) - (sum[r] - sum[l - 1]));

               // cout << (sum[r] - sum[l - 1]) << " " << maximum(r + 1, N, maxi) << minimum(r + 1, N, mini) << endl;
            }

            // for(int e: ss) cout << e << " ";
            // cout << endl;

            cout <<  *ss.rbegin() - *ss.begin() + 1 << endl; 
        }

    }
    return 0;
}