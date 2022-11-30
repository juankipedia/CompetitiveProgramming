/**
 * 
 * SPARSE SEGMENT TREE FOR MASSIVE OPERATIONS WITH LAZY PROPAGATION
 * 
 *  Example:
 *  assign value v to all elements on the segment from l to r. (lazy)
 *  find the sum on the segment from l to r. (st)
 *  
 *  note: lazy operation must be distributive.
 *  
 **/

template<class T> struct Node{
    Node *left = nullptr, *right = nullptr;
    T st = 0, lazy = 0;
    bool tag = false;
    int ss, se;

    Node(int ss, int se): ss(ss), se(se){}

    int mid(){ return (se + ss) / 2; }
    T NEUTRAL(){ return 0; }
    
    void push_down(){
        if(left == nullptr && right == nullptr){
            left = new Node<T>(ss, mid());
            right = new Node<T>(mid() + 1, se);
        }
        if(tag){
            left->st = lazy * (mid() - ss + 1);
            right->st = lazy * (se - mid());
            left->lazy = right->lazy = lazy;
            left->tag = right->tag = 1;
            tag = 0;
        }
    }
 
    void update(int qs, int qe, T val){
        if(ss > qe || se < qs) return;
        if(qs <= ss && se <= qe){
            st = val * (se - ss + 1);
            lazy = val;
            tag = 1;
            return;
        }
        push_down();
        left->update(qs, qe, val);
        right->update(qs, qe, val);
        st = left->st + right->st;
    }
 
    T get(int qs, int qe){
        if(qs <= ss && se <= qe) return st;
        if(ss > qe || se < qs) return NEUTRAL();
        push_down();
        return left->get(qs, qe) + right->get(qs, qe);
    }
 
};
