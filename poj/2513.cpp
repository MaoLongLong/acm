// 字典树 并查集 欧拉路
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500005;

int tot = 0, n = 0, m = 0, fa[maxn], degree[maxn] = {0};
char a[15], b[15];

struct Node {
    int id;
    Node *next[26];
    Node(int _id = 0) : id(_id) {
        memset(next, 0, sizeof(next));
    }
} * root;

int insert(char *s) {
    int len = strlen(s);
    Node *p = root;
    for (int i = 0; i < len; ++i) {
        int id = s[i] - 'a';
        if (p->next[id] == NULL) {
            p->next[id] = new Node;
        }
        p = p->next[id];
    }
    if (p->id == 0) p->id = ++tot;
    return p->id;
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void join(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) {
        fa[f1] = f2;
    }
}

int main() {
    root = new Node;
    for (int i = 0; i < maxn; ++i) fa[i] = i;
    while (~scanf("%s%s", a, b)) {
        int i = insert(a), j = insert(b);
        ++degree[i], ++degree[j];
        join(i, j);
    }
    for (int i = 1; i <= tot; ++i) {
        if (fa[i] == i) ++n;
        if (degree[i] % 2 == 1) ++m;
    }
    if (n > 1)
        printf("Impossible\n"); // 等于0（没有任何输入）得输出Possible, 坑
    else if (m == 0 || m == 2)
        printf("Possible\n");
    else
        printf("Impossible\n");
    // system("pause");
    return 0;
}
