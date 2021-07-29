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
 *      - set_children
 *      - operation
 *      - join
 *      - NEUTRAL
 * 
 *      For assignment and sum, (assignment is the additional operation):
 * 
 *          T NEUTRAL(){ return 0; }
 *          T join(T lval, T rval){
 *              return lval + rval;
 *          }         
 *          void operation(){
 *              st = (se - ss + 1) * sta;
 *          }
 *          void set_children(T val){
 *              if(ss == se) return;
 *              left->sta = right->sta = val;
 *              left->stb = right->stb = true;
 *          }
 *              
 *      For addition and minimum, (addition is the additional operation):
 * 
 *          T NEUTRAL(){ return oo; }
 *          T join(T lval, T rval){
 *              return min(lval, rval);
 *          }         
 *          void operation(){
 *              st += sta;
 *          }
 *          void set_children(T val){
 *              if(ss == se) return;
 *              left->sta += val;
 *              right->sta += val;
 *              left->stb = right->stb = true;
 *          }
 *
 * VARIABLES:
 *      st: segment tree value.
 *      sta: lazy propagated segment tree value for additional operations.
 *      stb: to know if a given node of the segment tree has an operation (sta) to be propagated.
 *   
 * */

template<class T> struct Node{
    Node *left = nullptr, *right = nullptr;
    T st = 0, sta = 0;
    bool stb = false;
    int ss, se;

    Node(int ss, int se): ss(ss), se(se){}

    int mid(){ return (se + ss) / 2; }
    T NEUTRAL(){ return 0; }
    
    T join(T lval, T rval){
    }

    void operation(){

    }

    void set_children(T val){

    }
    void propagate(){
        if(left == nullptr && right == nullptr){
            left = new Node<T>(ss, mid());
            right = new Node<T>(mid() + 1, se);
        }
        if(!stb) return;
        operation(); // sets value for st using value in sta.
        stb = false;
        set_children(sta);
        sta = 0;
    }

    void update(int qs, int qe, T val){
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

    T get(int qs, int qe){
        propagate();
        if(qs <= ss && se <= qe) return st;
        if(ss > qe || se < qs) return NEUTRAL();
        return join(left->get(qs, qe), right->get(qs, qe));
    }
};
