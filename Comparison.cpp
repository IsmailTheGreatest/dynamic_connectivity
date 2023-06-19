
#include <iostream>
#include <vector>
#include <chrono>

class WeightedQuickUnion {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    WeightedQuickUnion(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) {
            return;
        }

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
    }
};

int main() {
    int n = 5000;  // Number of elements

    WeightedQuickUnion uf(n);

    // Generate random unions
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        int p = rand() % n;
        int q = rand() % n;
        uf.unite(p, q);
    }

    // Check connectivity for random pairs
    int pairCount = 1000;
    int connectedCount = 0;

    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < pairCount; ++i) {
        int p = rand() % n;
        int q = rand() % n;
        if (uf.isConnected(p, q)) {
            ++connectedCount;
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Total pairs: " << pairCount << std::endl;
    std::cout << "Connected pairs: " << connectedCount << std::endl;
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
