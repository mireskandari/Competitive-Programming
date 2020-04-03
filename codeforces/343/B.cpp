#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
	T val;
	Node* p;
    Node() {
        val = 0;
        p = nullptr;
    }
};
template<typename T>
struct Stack {
	Node<T>* top;
	int size;
	
    Stack() {
        top = nullptr;
        size = 0;
    }

	void push(T x) {
		Node<T>* n = new Node<T>;
		n->val = x;
		n->p = top;
		top = n;
		size++;
        // cerr << size << '\n';
	}
	
	void pop() {
		assert(size != 0);
		size--;
        Node<T>* p = top->p;
		delete top;
        top = p;
	}
	
	T get_top() {
        assert(size != 0);
		return top->val;
	}

    bool empty() {
        return size == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack<char> my_stack;
    string s;
    cin >> s;
    my_stack.push(s[0]);
    bool f = true;
    for (auto c : s) {
        if (f) f = false;
        else {
            if (!my_stack.empty()) {
                if (c == '+' && my_stack.get_top() == '+') {
                    my_stack.pop();
                    continue;
                    // cerr << "hello";
                } 

                else if (c == '-' && my_stack.get_top() == '-') {
                    my_stack.pop();
                    continue;
                    // cerr << "HELLO";
                }
            }
            my_stack.push(c);
        }
    }
    if (!my_stack.empty()) cout << "NO";
    else cout << "YES";
    // cout << my_stack.get_top();
    return 0;
}