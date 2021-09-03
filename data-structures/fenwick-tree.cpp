/**
 * FENWICK TREE
 * 
 * Let, f be some reversible function and a[] be an array of integers of length n.
 * Fenwick tree is a data structure which:
 * calculates the value of function f in the given range [l,r] (i.e. f(a[l], a[l + 1], …, a[r])) in O(log n) time;
 * updates the value of an element of a[] in O(log n) time;
 * requires O(n) memory, or in other words, exactly the same memory required for a;
 * 
 **/

struct FenwickTree{
    vector<lli> bit;
    int n;
    
    FenwickTree(int N){
        n = N;
        bit.assign(n, 0);        
    }
    
    FenwickTree(lli a[], int N){
        n = N;
        bit.assign(n, 0);
        for(int i = 0; i < n; i++)
            add(i, a[i]);
    }

    lli sum(int r){
        lli ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    lli sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(int i, lli delta){
        for(; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
};


/**
 * FENWICK TREE 2D
 * 
 * Let, f be some reversible function and a[][] be a n*m matrix.
 * Fenwick tree 2D is a data structure which:
 * calculates the value of function f in the given subsquare with opposite vertices at a[0][0] and a[x][y] in O(log (n*m)) time;
 * updates the value of an element of a[][] in O(log (n*m)) time;
 * requires O(n*m) memory, or in other words, exactly the same memory required for a[][];
 * 
 **/

struct FenwickTree2D {
    vector<vector<lli>> bit;
    int n, m;

    FenwickTree2D(int N, int M){
        n = N;
        m = M;
        bit.assign(n, vector<lli>(m, 0));
    }

    FenwickTree2D(vector<vector<lli>> &a, int N, int M){
        n = N;
        m = M;
        bit.assign(n, vector<lli>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                add(i, j, a[i][j]);
    }

    int sum(int x, int y){
        lli ret = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for(int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, lli delta){
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};