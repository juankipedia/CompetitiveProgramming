#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int max = 0, ocurr = 0, d;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > max){
            max = a[i];
            ocurr = 1;
            d = i;
        }
        else if(a[i] == max and ocurr != 3){
            ocurr++;
            if(ocurr == 3)
                d = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != 0 and i != d) cout << ' ';
        if(i != d) cout << a[i];
    }
    cout << endl;

    return 0;
}