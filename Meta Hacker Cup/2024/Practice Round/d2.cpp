#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;


struct Treap {
  inline static mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
  inline static uniform_int_distribution<int> uniform = uniform_int_distribution();

  struct _Node {
    int node_val, subtree_val, delta, size, prio;
    _Node *l, *r;

    _Node(int val) : node_val(val), subtree_val(val),
      delta(0), size(1), prio(uniform(rng)),
      l(nullptr), r(nullptr) {}
    ~_Node() { delete l; delete r; }
  };
  typedef _Node* Node;

private:
  int get_subtree_val(Node v) { return v ? v->subtree_val : 0; }
  int get_size(Node v) { return v ? v->size : 0; }
  void apply_delta(Node v, int delta) {
    if (!v) return;
    v->delta += delta;
    v->node_val += delta;
    v->subtree_val += delta*get_size(v);
  }
  void push_delta(Node v) {
    if (!v) return;
    apply_delta(v->l, v->delta);
    apply_delta(v->r, v->delta);
    v->delta = 0;
  }
  void update(Node v) {
    if (!v) return;
    v->subtree_val = get_subtree_val(v->l) + v->node_val + get_subtree_val(v->r);
    v->size = get_size(v->l) + 1 + get_size(v->r); 
  }
  Node merge(Node l, Node r) {
    push_delta(l); push_delta(r);
    if (!l || !r) return l ? l : r;
    if (l->prio > r->prio) {
      l->r = merge(l->r, r);
      update(l);
      return l;
    }
    else {
      r->l = merge(l, r->l);
      update(r);
      return r;
    }
  }
  void split(Node v, int key, Node &l, Node &r) {
    push_delta(v);
    l = r = nullptr;
    if (!v) return;
    if (key <= get_size(v->l)) {
      split(v->l, key, l, v->l);
      r = v;
    }
    else {
      split(v->r, key-get_size(v->l)-1, v->r, r);
      l = v;
    }
    update(v);
  }

  Node root;
public:
  Treap() : root(nullptr) { }
  ~Treap() { delete root; }
  int get(Node v, int key) {
    push_delta(v);
    if (key < get_size(v->l)) return get(v->l, key);
    else if (key > get_size(v->l)) return get(v->r, key-get_size(v->l)-1);
    else return v->node_val;
  }
  int get(int key) { return get(root, key); }
  void insert(Node item, int key) {
    Node l, r;
    split(root, key, l, r);
    root = merge(merge(l, item), r);
  }
  void insert(int key, int val) {
    insert(new _Node(val), key);
  }
  void erase(int key) {
    Node l, m, r;
    split(root, key+1, m, r);
    split(m, key, l, m);
    delete m;
    root = merge(l, r);
  }
  int query(int a, int b) {
    Node l1, r1;
    split(root, b+1, l1, r1);
    Node l2, r2;
    split(l1, a, l2, r2);
    int res = get_subtree_val(r2);
    l1 = merge(l2, r2);
    root = merge(l1, r1);
    return res;
  }
  void update(int a, int b, int delta) {
    Node l1, r1;
    split(root, b+1, l1, r1);
    Node l2, r2;
    split(l1, a, l2, r2);
    apply_delta(r2, delta);
    l1 = merge(l2, r2);
    root = merge(l1, r1);
  }
  int size() { return get_size(root); }
};

void testcase() {
  int n, g; cin >> n >> g;
  vector<int> E(n);
  for (int &x : E) cin >> x;

  Treap treap;

  for (int i = 0; i < n; i++) {
    int sz = treap.size();

    int ans = sz;
    int lo = 0;
    int hi = sz-1;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (treap.get(mid)-mid > E[i]) {
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    treap.insert(ans, E[i]+ans);
    if (ans > 0) treap.update(0, ans-1, -1);
  }

  int closest_index = 0;
  int best_dist = 1e9;
  for (int i = 0; i < n; i++) {
    int dist = abs(treap.get(i)-g);
    if (dist <= best_dist) {
      best_dist = dist;
      closest_index = n-i;
    }
  }
  cout << closest_index << " " << best_dist << "\n";
}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cout << "Case #" << t << ": ";
    testcase();
  }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize - 16;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %%rsp, (%0)\n"
    "mov %0, %%rsp\n"
    :
    : "r"(send));
  func();
  asm volatile("mov (%0), %%rsp\n" : : "r"(send));
  free(stack);
}

int main() {
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}