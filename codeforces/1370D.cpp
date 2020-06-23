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

int n, k;
lli a[200001];

bool check(lli x, bool f){
    int size = 0;    
    for(int i = 1; i <= n; i++){
        if(!f){
            size++;
            f = !f;
        }
        else{
            if(a[i] <= x){
                size++;
                f = !f;
            }
        }
    }
    return size >= k;
}

lli bs(){
    lli l = 1, h = 1e9;
    while(l < h){
        lli mid = l +  (h - l) / 2;
        if(check(mid, true) || check(mid, false)) h = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << bs() << endl; 
    return 0;
}