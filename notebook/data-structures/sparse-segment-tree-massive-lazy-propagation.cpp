/**
 * 
 * SPARSE SEGMENT TREE FOR MASSIVE OPERATIONS WITH LAZY PROPAGATION
 * 
 * Used when size of initial array (N) is too big and cannot be loaded in memory.
 * This implementation uses only necessary memory
 * 
 * for example:
 *  assign value v to all elements on the segment from l to r. (sta)
 *  find the sum on the segment from l to r. (st)
 *  
 *  note: additional operation should be distributive.
 *  
 * REQUIRED:
 *      - operation
 *      - join
 * VARIABLES:
 *      st: segment tree value.
 *      sta: lazy propagated segment tree value for additional operations.
 *      stb: to know if a given node of the segment tree has an operation (sta) to be propagated.
 *   
 * */

# define NEUTRAL 0

int N;

struct Node{
    Node *left = nullptr, *right = nullptr;
    lli st = 0, sta = 0;
    bool stb = false;
    int ss, se;

    Node(int ss, int se): ss(ss), se(se){}

    int mid(){ return ss + (se - ss) / 2; }
    
    lli join(lli lval, lli rval){
    }

    void operation(){

    }

    void propagate(){
        if(left == nullptr && right == nullptr){
            left = new Node(ss, mid());
            right = new Node(mid() + 1, se);
        }
        if(!stb) return;
        operation(); // sets value for st using value in sta.
        stb = false;
        if(ss == se) return;
        left->sta = right->sta = sta;
        left->stb = right->stb = true;
    }

    void update(int qs, int qe, lli val){
        propagate();
        if(ss > qe || se < qs) return;
        if(qs <= ss && se <= qe){
            stb = true;
            sta = val;
            propagate();
            return;
        }
        left->update(qs, qe, val);
        right->update(qs, qe, val);
        st = join(left->st, right->st);
    }

    lli get(int qs, int qe){
        propagate();
        if(qs <= ss && se <= qe) return st;
        if(ss > qe || se < qs) return NEUTRAL;
        return join(left->get(qs, qe), right->get(qs, qe));
    }
};