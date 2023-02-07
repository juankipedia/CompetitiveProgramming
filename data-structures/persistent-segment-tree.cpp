template<class T> struct Node {
    Node *left, *right;
    T v;
    Node() : left(this), right(this), v(0){}
    Node(Node *left, Node *right, T v) : left(left), right(right), v(v){}

    Node* update(int l, int r, int i, T val){
        if(l == r) return new Node(nullptr, nullptr, v + val);
        int m = (l + r) / 2;
        if(i <= m) return new Node(left->update(l, m, i, val), right, v + val);
        return new Node(left, right->update(m + 1, r, i, val), v + val);
    }

    T get(int ss, int se, int qs, int qe){
        if(qs <= ss && se <= qe) return v;
        if(ss > qe || se < qs) return 0; 
        int m = (ss + se) / 2;
        return left->get(ss, m, qs, qe) + right->get(m + 1, se, qs, qe);
    }
};
