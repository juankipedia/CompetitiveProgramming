#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> pii;

int A[100000], N, STF[300000], STS[300000], q, a, b;
pii ret;
string qt;

int get_mid(int s, int e){
    return s + (e - s)/2;
}

pii get_max(const pii &r, const pii &l){
    if(r.first > l.first)
        return {r.first, max(r.second, l.first)};
    else
        return {l.first, max(r.first, l.second)};
}

pii construct(int ss, int se, int si){

    if(ss == se){
        STF[si] = A[ss];
        STS[si] = -1;
        return {STF[si], -1};
    }

    int mid = get_mid(ss, se);
    pii r = construct(ss, mid, 2  * si + 1), l = construct(mid + 1, se, 2  * si + 2), ans;
    ans = get_max(r, l);
    STF[si] = ans.first;
    STS[si] = ans.second; 
    return ans;
}

pii get_sum(int ss, int se, int si, int l, int r){
    if(l <= ss && se <= r)
        return {STF[si], STS[si]};
    if(r < ss || se < l)
        return {-1, -1};

    int mid = get_mid(ss, se);
    return get_max(get_sum(ss, mid, 2 * si + 1, l, r),
                get_sum(mid + 1, se, 2 * si + 2, l, r));
}

void update(int ss, int se, int si, int i, int val){
    if(i < ss || i > se)
        return;

    if(se == ss){
        A[i] = val;
        STF[si] = val;
        STS[si] = -1;
    }
    else{
        int mid = get_mid(ss, se);
        int l = 2 * si + 1, r = 2 * si + 2;
        update(ss, mid, l, i, val);
        update(mid + 1, se, r, i, val);
        pii ans = get_max({STF[l], STS[l]}, {STF[r], STS[r]});
        STF[si] = ans.first;
        STS[si] = ans.second;
    }
}

int main() {
    io_boost;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    construct(0, N - 1, 0);
    cin >> q;
    while(q --){
        cin >> qt >> a >> b;
        a--;
        if(qt == "U")
            update(0, N - 1, 0, a, b);
        else{
            b--;
            ret = get_sum(0, N - 1, 0, a, b);
            cout << ret.first + ret.second << endl;
        }
    }
    return 0;
}