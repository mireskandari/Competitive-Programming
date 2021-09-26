#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MD = 1000 * 1000 * 1000 + 9;

struct Mint {
	int a;

	Mint(int a_ = 0) : a(a_) {}

	Mint &operator+=(Mint o) {
		a += o.a;
		if (a >= MD) {
			a -= MD;
		}
		return *this;
	}

	Mint &operator-=(Mint o) {
		a -= o.a;
		if (a < 0) {
			a += MD;
		}
		return *this;
	}

	Mint &operator*=(Mint o) {
		a = 1ll * a * o.a % MD;
		return *this;
	}

	Mint operator+(Mint o) {
		o += *this;
		return o;
	}

	Mint operator-(Mint o) {
		return (Mint(*this) -= o);
	}

	Mint operator*(Mint o) {
		o *= *this;
		return o;
	}
};

constexpr int N = 3e5 + 10;

struct Node {
	Mint sum, b0, b1;
};

Node t[N << 2];

int n, m, a[N];
Mint fib[N];

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c].sum = a[b];
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c].sum = t[l].sum + t[r].sum;
}

Mint get_fib(Mint b0, Mint b1, int i) {
	if (i < 2) {
		return i ? b1 : b0;
	}
	return b1 * fib[i - 1] + b0 * fib[i - 2];
}

inline void push(int c, int b, int e) {
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (t[c].b0.a != 0 || t[c].b1.a != 0) {
		t[l].b0 += t[c].b0;
		t[l].b1 += t[c].b1;
		t[l].sum += get_fib(t[c].b0, t[c].b1, m - b + 1) - t[c].b1;
		t[r].b0 += get_fib(t[c].b0, t[c].b1, m - b);
		t[r].b1 += get_fib(t[c].b0, t[c].b1, m - b + 1);
		t[r].sum += get_fib(t[c].b0, t[c].b1, e - b + 1) - get_fib(t[c].b0, t[c].b1, m - b + 1);
		t[c].b0 = t[c].b1 = 0;
	}
}

void show_node(int c, int b, int e) {
	cerr << b + 1 << ' ' << e << ": " << t[c].sum.a << ' ' << t[c].b0.a << ' ' << t[c].b1.a << '\n';
}

void update(int c, int b, int e, int u, int v) {
	if (u >= e || v <= b) {
		return;
	}
	if (u <= b && e <= v) {
		if (e - b == 1) {
			t[c].sum += fib[b - u];
		} else {
			t[c].sum += fib[e - u + 1] - fib[b - u + 1];
			t[c].b0 += fib[b - u];
			t[c].b1 += fib[b - u + 1];
		}
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, b, e);
	/*cerr << "BEFORE UPDATE: \n";
	show_node(l, b, m);
	show_node(r, m, e);*/
	update(l, b, m, u, v);
	update(r, m, e, u, v);
	/*cerr << "AFTER UPDATE: \n";
	show_node(l, b, m);
	show_node(r, m, e);*/
	t[c].sum = t[l].sum + t[r].sum;
}

Mint query(int c, int b, int e, int u, int v) {
	if (u >= e || v <= b) {
		return Mint(0);
	}
	if (u <= b && e <= v) {
		return t[c].sum;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	push(c, b, e);
	return query(l, b, m, u, v) + query(r, m, e, u, v);
}

void show(int c, int b, int e) {
	show_node(c, b, e);
	if (e - b == 1) {
		return;
	}
	int m = (b + e) >> 1;
	show(c << 1, b, m);
	show(c << 1 | 1, m, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fib[0] = fib[1] = 1;
	for (int i = 2; i < N; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	//cerr << get_fib(1, 1, 2).a << ' ' << get_fib(1, 2, 1).a << ' ' << get_fib(1, 2, 3).a << '\n';
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	build(1, 0, n);

	while (m--) {
		int op, l, r;
		cin >> op >> l >> r;
		--l;
		if (op == 1) {
			update(1, 0, n, l, r);	
		} else {
			cout << query(1, 0, n, l, r).a << '\n';
		}
		//cerr << "SHOWING:\n";
		//show(1, 0, n);
		//cerr << "\n\n\n";
	}
}