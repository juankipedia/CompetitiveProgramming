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

#define ms(obj,val) memset(obj,val,sizeof(obj))

const int MAXA = 10000001;
int p[MAXA], d1[500000], d2[500000], n, a[500000];
void fill(){
    for(int i = 1; i < MAXA; i++) p[i] = i;
    for(int i = 4; i < MAXA; i += 2) p[i] = 2;
    for(int i = 3; i * i < MAXA; i ++){
        if(p[i] == i){
            for(int j = i * i; j < MAXA; j += i)
                if(p[j] == j) p[j] = i;
        }
    }
}

void f(int ai, int i){
    map<int, int> fact;
    while(ai != 1){
        ++fact[p[ai]];
        ai /= p[ai];
    }
    if(fact.size() == 1) d2[i] = d1[i] = -1;
    else{
        d2[i] = 1;
        for(const auto &factr: fact) d2[i] *= factr.first;
        d1[i] = fact.begin()->first;
        d2[i] /= d1[i];
    }
}

int main(){
    io_boost;
    cin >> n;
    fill();
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) f(a[i], i);
    for(int i = 0; i < n; i++) cout << d1[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << d2[i] << " ";
    cout << endl;

    return 0;
}