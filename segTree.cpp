//This template is build to find min-element existing in a specific range 
class SGTree{
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1);
    };

    void build(int ind, int low, int high, int nums[]) {
        //When both are equals
        if(low == high) {
            seg[ind] = nums[low];
            return;
        }

        //calling for mids...
        int mid = (low + high) >> 1;
        build(ind * 2 + 1, low, mid, nums);
        build(ind * 2 + 2, mid + 1, high, nums);

        //calculating results...
        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        //no overlaps
        if(high < l || low > r) return INT_MAX;

        //complete overlap
        if(l <= low && high <= r) return seg[ind];

        //partially overlap
        int mid = (low + high) >> 1;
        int left = query(ind * 2 + 1, low, mid, l, r);
        int right = query(ind * 2 + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        //When both are equals
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if(i <= mid) update(ind * 2 + 1, low, mid, i, val);
        else update(ind * 2 + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }
};
