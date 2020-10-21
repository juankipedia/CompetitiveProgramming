#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
const ulli M = 1099511627776, S0 = 1611516670, START = 350125310, LOOP_LEN = 182129209, BLOCK_LEN = 10000000;
 
ulli BC[] = {1, 5004364, 10006017, 15011683, 20012408, 25031296, 30040232, 35042602, 40042828, 45056959, 50056831, 55056278, 60057168, 65062411, 70077204, 75074286, 80089334, 85076566, 90060817, 95067617, 100089173, 105080524, 
110081437, 115071718, 120091493, 125100277, 130104566, 135114812, 140110603, 145118771, 150119937, 155117508, 160106698, 165108248, 170101751, 175085228, 175147925};
 
 
ulli SBC[] = {S0, 14370604200, 38312507972, 83247916001, 167560117600, 325792000029, 622741120791, 937671934, 13107719600, 35943599742, 78801945498, 159234898681, 310147452612, 593347802479, 295485408, 11901266043, 33681833440, 74557284385, 151258542280, 295206636642, 565345342287, 1072245719964, 
10752835534, 31526654920, 70512551867, 143676929598, 280954481302, 538597935120, 1022069337683, 9655676328, 29466751902, 66642908733, 136417090706, 267367793078, 513106623864, 974224246230, 504569};
 
ulli AC[] = {0, 4989280, 9983340, 14984746, 19988258, 24980216, 29971111, 34971436, 39962817, 44967154, 49973217, 54964748, 59985790, 64989687, 69988721, 74980113, 79977390, 84979857, 89965024, 91029303};
 
ulli SAC[] = {504569, 11347485539, 32642495446, 72602097447, 147587443420, 288298871304, 552368191773, 1047888951810, 10220443016, 30528043633, 68635199979, 140147722236, 274358274209, 526208071652, 998851889969, 9149377535, 28517085197, 64866014746, 133077343444, 1099510022851};

ulli S(ulli Sp){
    return (Sp + (Sp >> 20ULL) + 12345ULL) % M;
}
 
pair<ulli, ulli> find_start_len(){
    ulli St = S0, Sh = S(S(S0)), start = 0, len = 1;;
    while(St != Sh){
        Sh = S(S(Sh));
        St = S(St);
    }
    St = S0;
    Sh = S(S(Sh));
    while(St != Sh){
        St = S(St);
        Sh = S(Sh);
        start++;
    }
 
    Sh = S(St);
    while(Sh != St){
        Sh = S(Sh);
        len ++;
    }
    return {start, len};
}
 
void print_even_counts(){
    ulli cnt  = 0, Si = 504569;
    for(ulli i = 1, j = 1, k = 0; i < LOOP_LEN; i++){
        Si = S(Si);
        if(Si % 2 == 0) cnt++;
        if(j == BLOCK_LEN){
            cout << Si << ", ";
            j = 0;
            if(k == 20){
                cout << endl;
                k = 0;
            }
            k++;
        }
        j++;
    }
    cout << Si << endl;
}
 
ulli n;
 
void naive_sol(ulli n){
    ulli Si = S0, cnt = 1;
    for(ulli i = 0; i < n; i++){
        Si = S(Si);
        if(Si % 2 == 0) cnt ++;
    }
    cout << cnt << endl;
}
 
int main(){
    //print_even_counts();
    cin >> n;
    if(n == 0){cout << 0 << endl; return 0;}
    n--;
    //naive_sol(n);
    if(n < START){
        ulli np = n / BLOCK_LEN, ans = 0, Si;
        Si = SBC[np];
        ans += BC[np];
        n -= np * BLOCK_LEN;
        for(ulli i = 0; i < n; i++){
            Si = S(Si);
            if(Si % 2ULL == 0ULL) ans++;
        }
        cout << ans << endl;
    }
    else if(n > START){
        ulli ans = 175147925, np, Si;
        n -= START - 1;
        np = n / LOOP_LEN;
        ans += np * 91029304;
        n -= (n / LOOP_LEN) * LOOP_LEN;
        np = n / BLOCK_LEN;
        Si = SAC[np];
        ans += AC[np];
        n -= np * BLOCK_LEN;
        //naive_sol((np * BLOCK_LEN) + START - 1 );
        //cout << Si << endl; 
        for(ulli i = 0; i < n; i++){
            Si = S(Si);
            if(Si % 2ULL == 0ULL) ans++;
        }
        
        cout << ans << endl;
    }
    else{
        cout << 175147925 + 1 << endl;
    }
    return 0;
}

