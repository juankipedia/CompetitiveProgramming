# include <bits/stdc++.h>
using namespace std;
string a, p;

int f(int i, int j){
    if(i >= a.size()) return 1;
    if(j >= p.size()) return -1;

    int ans = -1;
    if(a[i] == p[j]) ans = f(i + 1, j + 1);

    int res = f(i, j + 1);
    if(res != -1 && ans != -1) ans += res;
    else if(res != -1 && ans == -1) ans = res;

    return ans;

}

int main(){
    a = "acm";
    p = "academy of computer makers";

    cout << f(0, 0) << endl;
}