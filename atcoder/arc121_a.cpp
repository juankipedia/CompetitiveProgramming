# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N;

int main(){
    cin >> N;
    vector<pair<lli, int>> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i].first >> y[i].first, x[i].second = i, y[i].second = i;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<tuple<lli, int, int>> ans;
    for(int i = 0; i < N; i++)
        ans.push_back({abs(x[i].first - x[N - 1].first), x[i].second, x[N - 1].second}),
        ans.push_back({abs(x[i].first - x[N - 2].first), x[i].second, x[N - 2].second}),
        ans.push_back({abs(y[i].first - y[N - 1].first), y[i].second, y[N - 1].second}),
        ans.push_back({abs(y[i].first - y[N - 2].first), y[i].second, y[N - 2].second});

    sort(ans.begin(), ans.end());
    int pos = ans.size() - 2;
    while(get<1>(ans[pos]) == get<1>(ans[ans.size() - 1]) &&
    get<2>(ans[pos]) == get<2>(ans[ans.size() - 1])) pos--;
    //cout << get<1>(ans[pos]) << " " << get<1>(ans[ans.size() - 1]) << " " << get<2>(ans[pos]) <<" " << get<2>(ans[ans.size() - 1]) << endl;
    cout << get<0>(ans[pos]) << endl;
    return 0;
}