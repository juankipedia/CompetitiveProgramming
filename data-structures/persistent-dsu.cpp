/**
 * PERSISTENT DSU
 * 
 * Use save function in order to start saving history of operations.
 * If you want to return at the last check point use rollback function, once you've
 * rolled back the DSU to some checkpoint, that check point is lost, for each rollback
 * there must be one check point previously setted.
 * 
 **/


struct DSU{

    struct operation{
        int a, b, la, lb;
    };

    int n, comp = n;
    vector<int> p, len;
    bool checkpoint = 0;
    stack<operation> history;
    DSU(int n) : n(n){
        p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
        len.assign(n + 10, 1);
    }
    
    int find(int n){ return p[n] == n ? n : find(p[n]); }
    
    void join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(len[a] < len[b]) swap(a, b);
        if(checkpoint) history.push({a, b, len[a], len[b]});
        len[a] += len[b];
        p[b] = a;
        comp--;
    }

    void rollback(){
        while(!history.empty()){
            auto [a, b, la, lb] = history.top();
            history.pop();
            if(a == -1){
                if(history.empty()) checkpoint = 0;
                return;
            }
            p[b] = b;
            comp++;
            len[a] = la;
            len[b] = lb;
        }
        checkpoint = 0;
    }

    void save(){
        checkpoint = 1;
        history.push({-1, -1, -1});
    }
};