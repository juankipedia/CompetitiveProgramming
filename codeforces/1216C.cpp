# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct Point{
    double x, y;
};

struct Square{
    Point l, t;
};


Square w, b1, b2;

bool belongs_to(double x, double y, Square &s){
    if(x >= s.l.x && x <= s.t.x && y >= s.l.y && y <= s.t.y) return true;
    return false;
}

int main(){
    cin >> w.l.x >> w.l.y >> w.t.x >> w.t.y;
    cin >> b1.l.x >> b1.l.y >> b1.t.x >> b1.t.y;
    cin >> b2.l.x >> b2.l.y >> b2.t.x >> b2.t.y;
    bool ok = false;
    for(double x = w.l.x; x <= w.t.x; x += 0.5)
        if(!belongs_to(x, w.l.y, b1) && !belongs_to(x, w.l.y, b2)) ok = true;
    for(double x = w.l.x; x <= w.t.x; x += 0.5)
        if(!belongs_to(x, w.t.y, b1) && !belongs_to(x, w.t.y, b2)) ok = true;
    for(double y = w.l.y; y <= w.t.y; y += 0.5)
        if(!belongs_to(w.l.x, y, b1) && !belongs_to(w.l.x, y, b2)) ok = true;
    for(double y = w.l.y; y <= w.t.y; y += 0.5)
        if(!belongs_to(w.t.x, y, b1) && !belongs_to(w.t.x, y, b2)) ok = true;
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}