#include <bits/stdc++.h>
using namespace std;
 
# define fast_io std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long int lli;
 
int N, M, a[400001], m[400001], lcp[400001];
vector<int> s;
pair<pair<int, int>, int> v[400001], r[400001]; 
 
void rs(){
    int c[N] = {0}, p[N] = {0};
    for(int i = 0; i < N; i++)
        c[v[i].first.first]++;
    for(int i = 1; i < N; i++) p[i] = p[i - 1] + c[i - 1];
    for(int i = 0; i < N; i++)
        r[p[v[i].first.first]++] = v[i];
    for(int i = 0; i < N; i++) v[i] = r[i];
}
 
int main(){
    fast_io;
    cin >> N >> M;
    int si;
    for(int i = 0; i < N; i++){
        cin >> si;
        s.push_back(si);
    }
    s.push_back(0);
    N++;
    for(int i = 0; i < N; i++) a[i] = i;
    sort(a, a + N, [](int i, int j){
        return s[i] < s[j];
    });
 
    m[a[0]] = 0;
    for(int i = 1; i < N; i++)
        if(s[a[i]] == s[a[i - 1]])  m[a[i]] = m[a[i - 1]];
        else m[a[i]] = m[a[i - 1]] + 1;
 
    lli k = 0;
    for(; (1ull << k) < N; k ++){
        for(int i = 0; i < N; i++)
            v[i] = {{m[(a[i] - (1ull << k)  + N) % N],  m[a[i]]}, (a[i] - (1ull << k)  + N) % N};
        rs();
        for(int i = 0; i < N; i++) a[i] = v[i].second;
        m[a[0]] = 0;
        for(int l = 1; l < N; l++){
            int i = v[l].first.first, j = v[l].first.second, ii = v[l - 1].first.first, jj = v[l - 1].first.second;
            if(i == ii && j == jj) m[a[l]] = m[a[l - 1]];
            else m[a[l]] = m[a[l - 1]] + 1;
        }
    }

    for(int i = 0; i < N; i++) m[a[i]] = i;

    int K = 0;
    for(int i = 0; i < N - 1; i++){
        int pi = m[i]; int j = a[pi - 1];
        while(s[i + K] == s[j + K]) K++;
        lcp[pi] = K;
        K = max(K - 1, 0);
    }


    {
        priority_queue<pair<lli, int>> pq;
        set<int> pos;
        for(int i = 1; i < N; i++){
            pq.push({lcp[i], i});
            pos.insert(i);
        }

        lli maxi = 0, len = 0;
        int pp = 0;
        while(!pq.empty()){
            auto k = pq.top();
            pos.erase(k.second);
            auto it = pos.lower_bound(k.second);
            lli l, r;
            if(it != pos.end()) r = *it;
            else r = N;

            if(it == pos.begin()) l = -1;
            else{
                it--;
                l = *it;
            }
            
            if((r - l) * k.first > maxi){
                maxi = (r - l) * k.first;
                len = k.first;
                pp = k.second; 
            }
            pq.pop();
        }

        if((N - 1) > maxi){
            len = N - 1;
            pp = m[0];
            maxi = N - 1;
        }

        if(maxi){
            cout << maxi << endl << len << endl;
            pp = a[pp];
            for(int i = pp; i < (pp + len); i++)
                cout << s[i] << " ";
            cout << endl;
        }
        else cout << 1 << endl << 1 << endl << s[0] << endl;
    }



    return 0;
}