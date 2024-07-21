#define PROBLEM "https://atcoder.jp/contests/practice2/tasks/practice2_b"
#include <bits/stdc++.h>
#include "atcoder/fenwicktree"

int main() {
    int n, q;
    std::cin >> n >> q;
    atcoder::fenwick_tree<long long> fwk(n);
    for (int p = 0; p < n; ++p) {
        int x;
        std::cin >> x;
        fwk.add(p, x);
    }
    for (int i = 0; i < q; ++i) {
        int t;
        std::cin >> t;
        if (t == 0) {
            // add
            int p, x;
            std::cin >> p >> x;
            fwk.add(p, x);
        } else {
            // sum
            int l, r;
            std::cin >> l >> r;
            long long sum = fwk.sum(l, r);
            std::cout << sum << '\n';
        }
    }
}
