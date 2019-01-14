#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, r, c, l;
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        l = (r - 1) * c + (c - 1) * r;
        if(l % 2)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }

    return 0;
}