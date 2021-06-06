# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N;

int main(){
    cin >> N;
    vector<lli> RGB[3];
    N = 2 * N;
    for(int i = 0; i < N; i++){
        string c;
        lli a;
        cin >> a >> c;
        if(c == "R") RGB[0].push_back(a);
        if(c == "G") RGB[1].push_back(a);
        if(c == "B") RGB[2].push_back(a);
    }
    for(int i = 0; i < 3; i++) sort(RGB[i].begin(), RGB[i].end());
    if(RGB[0].size() % 2 == 0 && 
       RGB[1].size() % 2 == 0 &&
       RGB[2].size() % 2 == 0)
       cout << 0 << endl;
    else{
        int a = -1, b = -1, c = -1;
        for(int i = 0; i < 3; i++)
            if(a == -1 && RGB[i].size() % 2) a = i;
            else if(a != -1 && RGB[i].size() % 2) b = i;
            else c = i;
        lli ans = numeric_limits<lli>::max();
        for(lli e: RGB[a]){
            lli f = lower_bound(RGB[b].begin(), RGB[b].end(), e) - RGB[b].begin();
            if(f == 0) ans = min(ans, abs(RGB[b][f] - e));
            else if(f != RGB[b].size()) ans = min({ans, abs(RGB[b][f] - e), abs(RGB[b][f - 1] - e)});
            else if(f == RGB[b].size()) ans = min(ans, abs(RGB[b][f - 1] - e));
        }
        lli ansi1 = numeric_limits<lli>::max(), ansi2 = numeric_limits<lli>::max();
        bool s = false;
        if(ans != 0 && RGB[c].size() != 0){
            s = true;
            int pos = -1;
            for(lli e: RGB[a]){
                int f = lower_bound(RGB[c].begin(), RGB[c].end(), e) - RGB[c].begin();
                if(f == 0){
                    if(ansi1 > abs(RGB[c][f] - e)) ansi1 = abs(RGB[c][f] - e), pos = f;
                }
                else if(f != RGB[c].size()){
                    if(ansi1 > abs(RGB[c][f] - e)) ansi1 = abs(RGB[c][f] - e), pos = f;
                    if(ansi1 > abs(RGB[c][f - 1] - e)) ansi1 = abs(RGB[c][f - 1] - e), pos = f - 1;
                }
                else if(f == RGB[c].size()){
                    if(ansi1 > abs(RGB[c][f - 1] - e)) ansi1 = abs(RGB[c][f - 1] - e), pos = f - 1;
                }
            }

            for(lli e: RGB[b]){
                int f = lower_bound(RGB[c].begin(), RGB[c].end(), e) - RGB[c].begin();
                if(f == 0){
                    if(f == pos) f++;
                    if(ansi2 > abs(RGB[c][f] - e)) ansi2 = abs(RGB[c][f] - e), pos = f;
                }
                else if(f != RGB[c].size()){
                    if(f != pos){
                        if(ansi2 > abs(RGB[c][f] - e)) ansi2 = abs(RGB[c][f] - e), pos = f;
                        if(ansi2 > abs(RGB[c][f - 1] - e)) ansi2 = abs(RGB[c][f - 1] - e), pos = f - 1;
                    }
                    else{
                        if(ansi2 > abs(RGB[c][f - 1] - e)) ansi2 = abs(RGB[c][f - 1] - e), pos = f - 1;
                        if(f + 1 != RGB[c].size() && ansi2 > abs(RGB[c][f + 1] - e)) ansi2 = abs(RGB[c][f + 1] - e), pos = f + 1;
                    }
                }
                else if(f == RGB[c].size()){
                    if(f - 1 == pos){
                        if(f - 2 >= 0){
                            if(ansi2 > abs(RGB[c][f - 2] - e)) ansi2 = abs(RGB[c][f - 2] - e), pos = f - 2;
                        }
                    } 
                    else if(ansi2 > abs(RGB[c][f - 1] - e)) ansi2 = abs(RGB[c][f - 1] - e), pos = f - 1;
                }
            }


        }
        if(s) cout << min(ans, ansi1 + ansi2) << endl;
        else cout << ans << endl;
    }
    return 0;
}