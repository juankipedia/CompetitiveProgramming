# include <bits/stdc++.h>

using namespace std;

int main(){
    string w;
    cin >> w;
    if(w.length() % 2 == 0){
        reverse(w.begin(), w.begin() + w.length() / 2);
        reverse(w.begin() + w.length() / 2, w.end());
    }
    else {
        reverse(w.begin(), w.begin() + w.length() / 2);
        reverse(w.begin() + w.length() / 2 + 1, w.end());
    }
    cout << w << "\n";
    return 0;
}