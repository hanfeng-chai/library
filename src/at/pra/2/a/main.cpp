#define PROBLEM "https://atcoder.jp/contests/practice2/tasks/practice2_a"
#include <bits/stdc++.h>
#include "atcoder/dsu"

int main() {
    int n, q;
    std::cin >> n >> q;
    atcoder::dsu dsu(n);
    for (int i = 0; i < q; ++i) {
        int t, a, b;
        std::cin >> t >> a >> b;
        if (t == 0) {
            // merge
            dsu.merge(a, b);
        } else {
            // query
            std::cout << dsu.same(a, b) << '\n';
        }
    }
}
