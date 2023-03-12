
const ll oo = 1e18;
int m, n;
vector<ll> dp_before(n), dp_cur(n);
ll C(int i, int j);

void compute(int l, int r, int optl, int optr){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<ll, int> best = {oo, -1};
    for(int k = optl; k <= min(mid, optr); k++)
        best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int solve(){
    for(int i = 0; i < n; i++) dp_before[i] = C(0, i);

    for(int i = 1; i < m; i++)
        compute(0, n - 1, 0, n - 1), 
        dp_before = dp_cur;

    return dp_before[n - 1];
}