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






//segment tree for range query using lazy propogation technique
class SEGTreeLazy{
    vector<int> seg, lazy;
public:
    SEGTreeLazy(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    };
public:
    void build(int ind, int low, int high, int nums[]) {
        if(low == high) {
            seg[ind] = nums[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(ind * 2 + 1, low, mid, nums);
        build(ind * 2 + 2, mid + 1, high, nums);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
public:
    void update(int ind, int low, int high, int l, int r, int val) {
        //update the prev remaining updates && propogate downwards
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            //propogate downwards for remaining elements to be updated
            if(low != high) {
                lazy[ind * 2 + 1] += lazy[ind];
                lazy[ind * 2 + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        //no overlaps
        if(r < low || l > high) return;

        //complete overlap
        if(l <= low && high <= r) {
            seg[ind] += (high - low + 1) * val;
            //if low != high, it means children exists
            if(low != high) {
                lazy[ind * 2 + 1] += val;
                lazy[ind * 2 + 2] += val;
            }
            return;
        }

        //partial overlap
        int mid = (low + high) >> 1;
        update(ind * 2 + 1, low, mid, l, r, val);
        update(ind * 2 + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
public:
    int query(int ind, int low, int high, int l, int r) {
        //update if any updates are remaining 
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[ind * 2 + 1] += lazy[ind];
                lazy[ind * 2 + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        //no overlap
        if(high < l || r < low) {
            return 0;
        }

        //complete overlap
        if(l <= low && high <= r) return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(ind * 2 + 1, low, mid, l, r);
        int right = query(ind * 2 + 2, mid + 1, high, l, r);
        return left + right;
    }
};
