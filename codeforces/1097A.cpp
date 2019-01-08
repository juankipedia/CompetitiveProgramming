#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main() {
    string tc;
    cin >> tc;
    char r1,s1, r2,s2, r3,s3, r4,s4, r5,s5;
    getchar();
    scanf("%c%c %c%c %c%c %c%c %c%c", &r1,&s1, &r2,&s2, &r3,&s3, &r4,&s4, &r5,&s5);
    unordered_set<char> c;
    c.insert(r1);c.insert(r2);c.insert(r3);c.insert(r4);c.insert(r5);
    c.insert(s1);c.insert(s2);c.insert(s3);c.insert(s4);c.insert(s5);
    if(c.find(tc[0]) != c.end() || c.find(tc[1]) != c.end())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}