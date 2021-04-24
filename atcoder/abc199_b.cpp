# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, A[100], B[100];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    int l = -1, r = numeric_limits<int>::max();
    int ans = -1;
    for(int i = 0; i < N; i++){
        if(A[i] > r || B[i] < l){
            ans = 0;
            break;
        }
        if(A[i] > l) l = A[i];
        if(B[i] < r) r = B[i];
    }
    if(!ans) cout << 0 << endl;
    else cout << r - l + 1 << endl;
    return 0;
}