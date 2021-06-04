# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 200005;
ulli N, K;
pair<ulli, ulli> AB[MAXN]; 

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> AB[i].first >> AB[i].second;
    sort(AB, AB + N);
    ulli pos = 0;
    for(int i = 0; i < N; i++){
        if(pos + K < AB[i].first) break;
        else{
            K -= AB[i].first - pos;
            pos = AB[i].first;
            K += AB[i].second;
        }
    }
    cout << pos + K << endl;
    return 0;
}