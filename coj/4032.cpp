#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ui;
typedef long long int li;

li binarySearch(ui arr[], li l, li r, li x) { 
   while (l < r){
            li m = floor((l + r) / 2);
            if (arr[m] < x) l = m + 1;
            else r = m;
    }
    return (arr[l] == x);
} 

int main() {
    li n, c = 0;
    cin >> n;
    ui a[n];
    set<li> s;
    for (li i = 0; i < n; ++i) cin >> a[i];
    for (li i = 0; i < n; ++i) if(binarySearch(a, 0, n - 1, a[i])) s.insert(a[i]);

    cout << s.size() << endl;
    for (const li &e: s) cout << e << endl;
    return 0;
}