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
const lli INF = numeric_limits<lli>::min();
lli A[50000], N, Q, a, b;
lli STP[1500000], STS[1500000], STM[1500000], STT[1500000];

void get_max(const vector<lli> &a, const vector<lli> &b, vector<lli> &ans){
    ans[0] = max(a[0], a[3] + b[0]);
    ans[1] = max(b[1], b[3] + a[1]);
    ans[2] = max(max(a[2], b[2]), a[1] + b[0]);
    ans[3] = a[3] + b[3];
}

int get_mid(int s, int e){
    return s + (e - s) / 2;
}

vector<lli> construct(int ss, int se, int si){
    if(se == ss){
        STP[si] = STS[si] = STM[si] = STT[si] = A[ss];
        return {STP[si], STS[si], STM[si], STT[si]};
    }

    int MID = get_mid(ss, se);

    vector<lli> L = construct(ss, MID, 2 * si + 1);
    vector<lli> R = construct(MID + 1, se, 2 * si + 2);

    vector<lli> ans = {0, 0, 0, 0};
    get_max(L, R, ans);
    STP[si] = ans[0]; STS[si] = ans[1]; STM[si] = ans[2]; STT[si] = ans[3];
    return ans;
}

vector<lli> sum(int ss, int se, int l, int r, int si){ 
    if(l <= ss && se <= r) return {STP[si], STS[si], STM[si], STT[si]};
    if(l > se || r < ss) return {};

    int MID = get_mid(ss, se);
    vector<lli> L = sum(ss, MID, l, r, 2 * si + 1);
    vector<lli> R = sum(MID + 1, se, l, r, 2 * si + 2);

    if(L.size() == 0) return R;
    if(R.size() == 0) return L;

    vector<lli> ans = {0, 0, 0, 0};
    get_max(L, R, ans);

    return ans;
}

lli sum(int l, int r){
    vector<lli> ans = sum(0, N - 1, l, r, 0);
    lli res = max(ans[0], ans[1]);
    res = max(ans[2], max(ans[3], res));
    return res;
}

int main() {
    io_boost;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    construct(0, N - 1, 0);
    cin >> Q;
    while(Q --){
        cin >> a >> b;
        a--; b--;
        cout << sum(a, b) << endl;
    }
    return 0;
}