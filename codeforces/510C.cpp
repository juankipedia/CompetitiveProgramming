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

int N, l;
string n[100000];
vector<int> g[26];

bool has_cycle_(int u, bool stack[], bool visited[]){
    if(!visited[u]){
        visited[u] = true;
        stack[u] = true;
        for(const int &v: g[u]){
            if(!visited[v] && has_cycle_(v, stack, visited))
                return true;
            else if(stack[v])
                return true;
        }
    }
    stack[u] = false;
    return false;
}

bool has_cycle(){
    bool stack[26] = {false}, visited[26] = {false};
    for(int i = 0; i < 26; i++)
        if(has_cycle_(i, stack, visited))
            return true;
    return false;
}

void print_(int u, stack<int> &s, bool visited[]){
    visited[u] = true;
    for(const int &v: g[u])
        if(!visited[v]) print_(v, s, visited);
    s.push(u);
}

void print(){
    stack<int> s;
    bool visited[26] = {false};
    for(int i = 0; i < 26; i++)
        if(!visited[i])
            print_(i, s, visited);
    while(!s.empty()){
        cout << (char)(s.top() + 'a');
        s.pop();
    }
    cout << endl;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> n[i];
    for(int i = 0; i < N - 1; i++){
        l = n[i].size();        
        for(int j = 0; j < l; j++){
            if(j == n[i + 1].size()){
                cout << "Impossible" << endl;
                return 0;
            }
            else if(n[i][j] != n[i + 1][j]){
                g[n[i][j] - 'a'].push_back(n[i + 1][j] - 'a');
                break;
            }
        }
    }
    if(has_cycle()) cout << "Impossible" << endl;
    else print();
    
    return 0;
}