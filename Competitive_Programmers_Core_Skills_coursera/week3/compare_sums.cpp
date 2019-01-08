# include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long double a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    long double s_a = 0, s_b = 0;
    for (int i = 0; i < n; ++i){s_a += a[i]; s_b += b[i];}
    if (abs(s_a - s_b) < 1e-4)
        cout << "SUM(A)=SUM(B)" << endl;
    else if(s_a > s_b + 1e-4)
        cout << "SUM(A)>SUM(B)" << endl;
    else
        cout << "SUM(A)<SUM(B)" << endl;

    return 0;
}