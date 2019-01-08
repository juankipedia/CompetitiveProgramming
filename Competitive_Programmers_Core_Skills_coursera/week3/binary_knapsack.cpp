#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct thing {
    int w_i, val;
    bool operator < (const thing& other) const {
        return w_i < other.w_i;
    }
};

int main() {
    cin.sync_with_stdio(false); cin.tie(0);
    int n, W;
    cin >> n >> W;

    vector<thing> wt;
    for (int i = 0; i < n; ++i) {
        int w_i, val;
        cin >> w_i >> val;
        wt.push_back({w_i, val});
    }

    sort(wt.begin(), wt.end());
    reverse(wt.begin(), wt.end());

    int res = 0;
    vector<int> c;

    for (int power = 0; power <= 30; ++power) {
        int w_i = 1 << power;
        while (wt.size() > 0 && wt.back().w_i == w_i) {
            c.push_back(wt.back().val);
            wt.pop_back();
        }
        sort(c.begin(), c.end());
        if (W & w_i) {
            if (c.size() > 0) {
                res += c.back();
                c.pop_back();
            }
        }
        vector<int> n_c;
        while (c.size() >= 2) {
            int c_v = c.back();
            c.pop_back();
            c_v += c.back();
            c.pop_back();
            n_c.push_back(c_v);
        }
        if (c.size() >= 1) {
            n_c.push_back(c.back());
            c.pop_back();
        }
        c = n_c;
    }
    cout << res << '\n';
    return 0;
}

