#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli n, q, trie[5000005][26], max_words[5000005], words[5000005], nodes = 1;
string s;

void insert(){
    lli cur = 0;
    stack<lli> stck;
    for(char c: s){
        lli cc = c - 'a';
        if(trie[cur][cc] == 0) trie[cur][cc] = nodes++;
        cur = trie[cur][cc];
        stck.push(cur);
    }
    words[cur]++;
    while(!stck.empty()){
        max_words[stck.top()] = max(words[cur], max_words[stck.top()]);
        stck.pop();
    }
}

void count_words(){
    lli cur = 0;
    for(char c: s){
        lli cc = c - 'a';
        if(trie[cur][cc] == 0){
            cout << -1 << endl;
            return;
        }
        cur = trie[cur][cc];
    }
    string ans = s;
    while(true){
        lli c = -1;
        lli maxi = words[cur];
        for(lli i = 0; i < 26; i++){
            if(max_words[trie[cur][i]] > maxi){
                maxi = max_words[trie[cur][i]];
                c = i;
            }
        }
        if(c == -1) break;
        else{
            ans += c + 'a';
            cur = trie[cur][c];
        }
    }
    
    cout << ans << " " << max_words[cur] << endl;
}

int main(){
    io_boost;
    cin >> n;
    while(n--){
        cin >> s;
        insert();
    }
    cin >> q;
    while(q--){
        cin >> s;
        count_words();
    }
    
    return 0;
}