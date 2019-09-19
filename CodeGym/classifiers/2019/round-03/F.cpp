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
       
    int n, s, ps, pu;
    int t[40], lastt[41], sp[36], un[12];
    int memo[40][1026];
    bool memob[40][1026];
     
    int f(int i, ulli msk, int isp, int iun){
        if(i == 2 * n * (s+1)) return 0;
        else if(memob[i][msk]) return memo[i][msk];
        else{
            memob[i][msk] = true;
            int ret;
            int p = t[i];
            if(p <= n){
                ret = std::numeric_limits<int>::min();
                if(not((1 << p - 1) & msk)) 
                    ret = un[iun] + f(i + 1, msk | (1 << p - 1), isp, iun + 1);
                if(((1 << p - 1) & msk) or i != lastt[p])
                    ret = max(ret, sp[isp] + f(i + 1, msk, isp + 1, iun));
                memo[i][msk] = ret;
                return ret;
            }
            else{
                ret = std::numeric_limits<int>::max();
                if(not((1 << p - 1) & msk))
                    ret = - un[iun] + f(i + 1, msk | (1 << p - 1), isp, iun + 1);
                if(((1 << p - 1) & msk) or i != lastt[p])
                    ret = min(ret, -sp[isp] + f(i + 1, msk, isp + 1, iun));
                memo[i][msk] = ret;
                return ret;
            }
        }
    }
     
    int main() {
        cin >> n >> s;
        for(int i = 0; i < 2 * n * (s + 1); i++) cin >> t[i];
        cin >> ps;
        for(int i = 0; i < ps; i++) cin >> sp[i];
        sort(sp, sp+ps, std::greater<int>());
        cin >> pu;
        for(int i = 0; i < pu; i++) cin >> un[i];
        sort(un, un+pu, std::greater<int>());
        for(int i=0; i < 2*n*(s+1); i++) lastt[t[i]] = i;
        cout << f(0, 0, 0, 0) << endl;
        return 0;
    }