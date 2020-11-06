#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int TRIE_LEN = 1000005;

int n, trie[TRIE_LEN][26], cnt[TRIE_LEN];
string dictionary[100005], queries[100005], w;

int main(){
    io_boost;
    while(cin >> n && n != -1){

        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        int nodes = 1;
        int total = 0;
        for(int i = 0; i < n; i++) cin >> dictionary[i], total += dictionary[i].size();
        for(int i = 0; i < n; i++) cin >> queries[i], total += queries[i].size();
        
        for(int i = 0; i < n; i++){
            auto & s = dictionary[i];
            int cur = 0;
            for(char c: s){
                int cc = c - 'A';
                if(!trie[cur][cc]) trie[cur][cc] = nodes++;
                cur = trie[cur][cc]; 
                cnt[cur]++;
            }
        }

        for(int i = 0; i < n; i++){
            auto & s = queries[i];
            int cur = 0;
            for(char c: s){
                int cc = c - 'A';
                if(!trie[cur][cc]) trie[cur][cc] = nodes++;
                cur = trie[cur][cc]; 
                cnt[cur]--;
            }
        }

        int count = 0;
        for(int i = 1; i < nodes; i++) count += abs(cnt[i]);

        cout << (total - count) / 2 << endl;
    }
    return 0;
}