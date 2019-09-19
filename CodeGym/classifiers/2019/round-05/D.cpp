    #include <bits/stdc++.h>
     
    template <typename T>
    using v_t = std::vector<T>;
     
    using type_t = int64_t;
    using utype_t = uint64_t;
    using str_t = std::string;
     
    using std::cin;
    using std::cout;
     
    constexpr char endl = '\n';
     
    template <typename T>
    void debug(T val) { cout << val << endl; }
    template <typename T, typename... TT>
    void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }
     
    template <typename T, typename U>
    using p_t = std::pair<T, U>;
     
    template <typename T>
    using s_t = std::set<T>;
    template <typename T>
     
    s_t<p_t<int, int>> blocked{
        {9, 2}, {9, 3}, {9, 10}, {9, 11}, {10, 2}, {10, 11}, {6, 6}, {6, 7}, {7, 6}, {7, 7}};
     
    type_t crossed_x{3}, crossed_y{3};
     
    int main()
    {
        std::ios_base::sync_with_stdio(false);
     
        type_t L;
     
        cin >> L;
     
        while (--L != -1)
        {
            type_t r, c;
            std::string moves;
     
            cin >> r >> c;
     
            if (r == 9 || r == 10)
            {
                r += 2;
                moves += "DD";
            }
     
            if (r == 6 || r == 7)
            {
                r -= 2;
                moves += "UU";
            }
     
            while (r != 3 && c > 1)
            {
                --c;
                moves += "L";
            }
     
            while (r != 3)
            {
                if (r > 3)
                {
                    --r;
                    moves += "U";
                }
                else
                {
                    ++r;
                    moves += "D";
                }
            }
     
            while (c != 3 && c != 10)
            {
                if (c > 3)
                {
                    --c;
                    moves += "L";
                }
                else
                {
                    ++c;
                    moves += "R";
                }
            }
     
            cout << moves.size() << endl
                 << moves << endl;
        }
     
        return 0;
    }