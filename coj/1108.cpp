#include <iostream>

using namespace std;

unsigned int min (unsigned int a, unsigned int b) { return a < b ? a : b; }
unsigned int max (unsigned int a, unsigned int b) { return a > b ? a : b; }

int main () {
    unsigned int n;
    unsigned int sc[4] = {0};
    
    cin >> n;
    unsigned int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sc[s[i]]++;
    }
    unsigned int s12 = 0, s13 = 0, s21 = 0, s31 = 0, s23 = 0, s32 = 0;
    for (unsigned int i = 0; i < sc[1]; i++){
        if (s[i] == 2) s12++;
        if (s[i] == 3) s13++;
    }
    
    for (unsigned int i = sc[1]; i < sc[1]+sc[2]; i++){
        if (s[i] == 1) s21++;
        if (s[i] == 3) s23++;
    }
    
    for (unsigned int i = sc[1]+sc[2]; i < sc[1]+sc[2]+sc[3]; i++){
        if (s[i] == 1) s31++;
        if (s[i] == 2) s32++;
    }
    
    cout << min(s12, s21) + min(s13, s31) + min(s23, s32) + 2 * (max(s12, s21) - min(s12, s21)) << endl;
    return 0;
}