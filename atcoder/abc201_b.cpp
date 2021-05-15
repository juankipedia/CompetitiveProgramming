# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

pair<int, string> m[1005];
int N;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> m[i].second >> m[i].first;
    }
    sort(m, m + N);
    cout << m[N - 2].second << endl;
    return 0;
}