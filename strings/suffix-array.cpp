/**
 * SUFFIX ARRAY:
 * A suffix array will contain integers that represent the starting 
 * indexes of the all the suffixes of a given string, after the 
 * aforementioned suffixes are sorted.
 * 
 * For example if we have the string "abaab", the suffix array for this string will be:
 *  2. aab
 *  3. ab
 *  0. abaab
 *  4. b
 *  1. baab
 * 
 * Time complexity: O(nlg(n))
 *
 **/

struct SufixArray{
    
    struct SparseTable{
        int N, LOG2N;
        vector<int> lg2;
        vector<vector<int>> st;
    
        void build(vector<int> &a){
            N = a.size();
            LOG2N = log2(N) + 2;
            lg2.assign(N + 1, 0);
            st.assign(N, vector<int>(LOG2N, 0));
            lg2[1] = 0;
            for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
            for(int i = 0; i < N; i++) st[i][0] = a[i];
            for(int j = 1; j <= LOG2N; j++)
                for(int i = 0; i + (1 << j) <= N; i++)
                    st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
        int minimum(int L, int R){
            int lg = lg2[R - L + 1];
            return min(st[L][lg], st[R - (1 << lg) + 1][lg]);
        }
    };

    int n;
    vector<int> p, lcp; // sorted suffixes
    vector<int> mp;
    SparseTable st;

    SufixArray(string s) : n(s.size() + 1){
        s += "$";
        p.assign(n, 0);
        mp.assign(n, 0);
        lcp.assign(n - 1, 0);
        build(s);
        lcp_build(s);
        for(int i = 0; i < n; i++) mp[p[i]] = i;
        st.build(lcp);
    }

    void build(const string &s){
        const int alphabet = 256;
        vector<int> c(n), cnt(max(alphabet, n), 0);
        for(int i = 0; i < n; i++) cnt[s[i]]++;
        for(int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
        for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for(int i = 1; i < n; i++){
            if(s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for(int h = 0; (1 << h) < n; h++){
            for(int i = 0; i < n; i++){
                pn[i] = p[i] - (1 << h);
                if(pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
            for(int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
            for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for(int i = 1; i < n; i++){
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if(cur != prev)
                    classes++;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
    }

    void lcp_build(const string &s){
        int n = s.size();
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++) rank[p[i]] = i;
        int k = 0;
        for(int i = 0; i < n; i++){
            if(rank[i] == n - 1){
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
            if(k) k--;
        }
    }

    int get_lcp(int i, int j){
        int l = mp[i], r = mp[j];
        if(r < l) swap(l, r);
        assert(l != r);
        return st.minimum(l, r - 1);
    }
};