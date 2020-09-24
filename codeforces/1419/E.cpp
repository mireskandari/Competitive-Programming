#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> pf;
        map<int, bool> mark;
        pf.reserve(int(sqrt(n)));
        int nn = n;
        for (int sq = int(sqrt(n)), i = 2; i <= sq; ++i)
            if (nn % i == 0) {
                pf.emplace_back(i, 0);
                while (nn % i == 0) nn /= i, pf.back().second++;
            }
        if (nn > 1) pf.emplace_back(nn, 1);
        for (auto &p : pf) mark[p.first] = true;
        if (int(pf.size()) == 1) {
            for (int pw = 1, i = 0; i < pf[0].second; ++i) {
                pw *= pf[0].first;
                printf("%d ", pw);
            }
            puts("\n0");
            continue;
        }
        if (int(pf.size()) == 2 && pf[0].second == 1 && pf[1].second == 1) {
            printf("%d %d %d\n1\n", pf[0].first, pf[1].first, pf[0].first * pf[1].first);
            continue;
        }
        set<int> dv;
        nn = n;
        for (int sq = int(sqrt(n)), i = 1; i <= sq; ++i) 
            if (nn % i == 0) {
                if (!mark[i]) dv.emplace(i);
                if (nn / i != i && !mark[nn / i]) dv.emplace(nn / i);
            }
        dv.erase(1);
        if (int(pf.size()) == 2) {
            for (int pw = pf[0].first, i = 0; i < pf[0].second; ++i) {
                printf("%d ", pw);
                pw *= pf[0].first;
                dv.erase(pw);
            }
            printf("%d ", pf[0].first * pf[1].first);
            dv.erase(pf[0].first * pf[1].first);
            for (int pw = pf[1].first, i = 0; i < pf[1].second; ++i) {
                printf("%d ", pw);
                pw *= pf[1].first;
                dv.erase(pw);
            }
            while (!dv.empty()) {
                printf("%d ", *dv.begin());
                dv.erase(dv.begin());
            }
            puts("\n0");
            continue;
        }
        for (int i = 0; i < int(pf.size()); ++i) {
            int nex = (i + 1) % int(pf.size()), pre = i - 1 == -1 ? int(pf.size()) - 1 : i - 1;
            vector<int> to_remove;
            printf("%d ", pf[i].first);
            for (auto &j : dv)
                if (j % pf[i].first == 0 && j % (pf[i].first * pf[nex].first) != 0 && j % (pf[i].first * pf[pre].first) != 0)
                    to_remove.emplace_back(j);
            for (auto &j : to_remove) {
                printf("%d ", j);
                dv.erase(j);
            }
            to_remove.clear();
            for (auto &j : dv) 
                if (j != (pf[i].first * pf[nex].first) && j % (pf[i].first * pf[nex].first) == 0)
                    to_remove.emplace_back(j);
            printf("%d ", pf[i].first * pf[nex].first);
            for (auto &j : to_remove) {
                printf("%d ", j);
                dv.erase(j);
            }
        }
        printf("\n0\n");
    }
    return 0;
}


