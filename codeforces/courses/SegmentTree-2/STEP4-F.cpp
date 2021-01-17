#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N;
string t;

struct Node{
    Node *left = nullptr, *right = nullptr;
    lli s = 0, h = 0, sta = 0;
    bool stb = false;
    int ss, se;

    Node(int ss, int se): ss(ss), se(se){}

    int mid(){ return ss + (se - ss) / 2; }
    
    void join(){
        s = left->s + right->s;
        h = max(left->h, left->s + right->h);
    }

    void operation(){
        h = s = (se - ss + 1) * sta;
    }

    void propagate(){
        if(left == nullptr && right == nullptr){
            left = new Node(ss, mid());
            right = new Node(mid() + 1, se);
        }
        if(!stb) return;
        operation(); // sets value for st[si] using value in sta[si].
        stb = false;
        if(ss == se) return;
        left->sta = right->sta = sta;
        left->stb = right->stb = true;
    }

    void update(int qs, int qe, lli val){
        propagate();
        if(ss > qe || se < qs) return;
        if(qs <= ss && se <= qe){
            stb = true;
            sta = val;
            propagate();
            return;
        }
        left->update(qs, qe, val);
        right->update(qs, qe, val);
        join();
    }

    lli get(lli H){
        propagate();
        if(ss == se){
            if(h > H) return ss - 1;
            else return ss;
        }
        left->propagate();
        if(left->h > H) return left->get(H);
        else return right->get(H - left->s); 
    }
};
 
int main(){
    io_boost;
    lli a, b, D, h;
    cin >> N;
    Node segtree(0, N - 1);
    while(cin >> t){
        if(t == "E") break;
        if(t == "Q"){
            cin >> h;
            cout << segtree.get(h) + 1 << endl;
        }
        else{
            cin >> a >> b >> D;
            a--; b--;
            segtree.update(a, b, D);
        }
    }
    
    return 0;
}