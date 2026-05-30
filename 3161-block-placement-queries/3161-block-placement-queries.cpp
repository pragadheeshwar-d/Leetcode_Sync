
const int INF = 1e9 + 5;

class Node {
    public:
    int leftmost = INF;
    int rightmost = -INF;
    int max_gap = 0;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;
    
    Node merge(const Node& left, const Node& right) {
        Node res;
        if (left.leftmost == INF) {
            return right;
        }
        if (right.leftmost == INF) {
            return left;
        }
        res.leftmost = left.leftmost;
        res.rightmost = right.rightmost;
        res.max_gap = max({left.max_gap, right.max_gap, right.leftmost - left.rightmost});
        return res;
    }
    
    void update(int idx, int pos, int l, int r, int node) {
        if (l == r) {
            tree[node].leftmost = pos;
            tree[node].rightmost = pos;
            tree[node].max_gap = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(idx, pos, l, mid, node * 2);
        } else {
            update(idx, pos, mid + 1, r, node * 2 + 1);
        }
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    
    Node query(int ql, int qr, int l, int r, int node) {
        if (qr < l || ql > r) {
            return Node();
        }
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        Node left = query(ql, qr, l, mid, node * 2);
        Node right = query(ql, qr, mid + 1, r, node * 2 + 1);
        return merge(left, right);
    }
    
public:
    SegmentTree(int _n) : n(_n), tree(4 * (_n + 1)) {}
    
    void update(int idx, int pos) {
        update(idx, pos, 0, n, 1);
    }
    
    Node getQuery(int ql, int qr) {
        return query(ql, qr, 0, n, 1);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAX = 50010;
        SegmentTree st(MAX);
        vector<bool> results;
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                st.update(x, x);
            } else {
                int x = q[1];
                int sz = q[2];
                Node node = st.getQuery(0, x);
                bool can;
                if (node.leftmost == INF) {
                    can = (x >= sz);
                } else {
                    int max_free = max({node.max_gap, node.leftmost - 0, x - node.rightmost});
                    can = (max_free >= sz);
                }
                results.push_back(can);
            }
        }
        return results;
    }
};