#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path Compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 10; // number of vertices
    UnionFind uf(n);

    uf.unite(0, 1);
    uf.unite(2, 3);
    uf.unite(4, 5);
    uf.unite(6, 7);
    uf.unite(8, 9);

    cout << "Is 1 connected to 9? " << (uf.connected(1, 9) ? "Yes" : "No") << endl;
    cout << "Is 2 connected to 5? " << (uf.connected(2, 5) ? "Yes" : "No") << endl;
    cout << "Is 3 connected to 6? " << (uf.connected(3, 6) ? "Yes" : "No") << endl;

    return 0;
}
