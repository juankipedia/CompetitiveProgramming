/**
 * 
 * MO's Algorithm.
 * 
 * Answer queries over a segment [l, r] of the array. For example frequency of the most repeated element in the segment [l, r]
 * Requires: add(int i), del(int i), get_ans()
 * 
 * Time Complexity N * N / BLOCK_SIZE + BLOCK_SIZE * M  
 * 
 * */
 
struct Mos{

    struct Query{
        int l, r, idx;
    };

    int N, M, BLOCK_SIZE, l, r;

    vector<Query> queries;
    vector<lli> ans, a;

    vector<pair<lli, int>> b;
    vector<int> id;

    Mos(int n, int m){
        N = n;
        M = m;
        BLOCK_SIZE = sqrt(N);
        
        queries.assign(M, Query());
        ans.assign(M, 0);
        a.assign(N, 0);

        b.assign(N, {0, 0});
        id.assign(N, 0);
    }

    void add(int i){
    }

    void del(int i){
    }

    
    lli get_ans(){
        return 0;
    }
    
    void mos(){
        BLOCK_SIZE = sqrt(N);
        
        for(int i = 0; i < N; i++) b[i] = {a[i], i};
        sort(b.begin(), b.end());
        int cid = 0;
        for(int i = 0; i < N; i++){
            if(i != 0 && b[i - 1].first != b[i].first) cid++;
            id[b[i].second] = cid;
        }
        
        sort(queries.begin(), queries.end(), [&](const auto &a, const auto &b){
            if(a.l / BLOCK_SIZE  == b.l / BLOCK_SIZE) return a.r > b.r;
            else return a.l / BLOCK_SIZE < b.l / BLOCK_SIZE;
        });

        l = 0;
        r = -1;
        for(int i = 0; i < M; i++){
            while(r < queries[i].r) add(++r);
            while(l > queries[i].l) add(--l);
            while(r > queries[i].r) del(r--);
            while(l < queries[i].l) del(l++);
            ans[queries[i].idx] = get_ans();
        }
    }

};