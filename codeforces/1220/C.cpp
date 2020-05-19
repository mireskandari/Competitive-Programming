#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v) v.begin(),v.end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    Tree<char> t;
    for (auto c : s) {
        cout << (t.order_of_key(c) > 0 ? "Ann" : "Mike") << '\n';
        t.insert(c);
    }
    return 0;
}