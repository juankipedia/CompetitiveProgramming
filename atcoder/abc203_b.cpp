# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, K;

int main(){
    cin >> N >> K;
    int sum = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= K; j++)
            sum += stoi(to_string(i) + "0" + to_string(j));
    cout << sum << endl;
    return 0;
}