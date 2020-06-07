#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) v.begin(),v.end()
#define X first
#define Y second

template<class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                Container const &x) {
    os << "{ ";
    for (auto &y : x) os << y << " ";
    return os << "}";
}

template<class X, class Y>
ostream& operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "[ " << p.first << ", " << p.second << " ]";
}

template<class Ch, class Tr, class Tuple, int N>
struct Tp {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {
        Tp<Ch, Tr, Tuple, N - 1>::print(os, t);
        os << std::get<N - 1>(t) << " ";
    }
};

template<class Ch, class Tr, class Tuple>
struct Tp<Ch, Tr, Tuple, 0> {
    static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {}
};

template<class Ch, class Tr, class... Args>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr> &os,
                tuple<Args...> const &t) {
    os << "[ ";
    Tp<Ch, Tr, tuple<Args...>, sizeof...(Args)>::print(os, t);
    return os << "]";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), pa(n), pb(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pa[--a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pb[--b[i]] = i;
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        {
            int difl = pa[i] - pb[i];
            if (difl < 0) l[i] = n + difl;
            else if (difl > 0) l[i] = difl;
        }
        {
            int difr = pb[i] - pa[i];
            if (difr < 0) r[i] = n + difr;
            else if (difr > 0) r[i] = difr;
        }
    }
    vector<int> cntl(n), cntr(n);
    for (int i = 0; i < n; i++) {
        cntl[l[i]]++;
        cntr[r[i]]++;
    }
    cout << max(*max_element(all(cntl)), *max_element(all(cntr)));
    return 0;
}