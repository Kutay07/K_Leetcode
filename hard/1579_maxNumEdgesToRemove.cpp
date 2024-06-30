#include <vector>
using namespace std;

// Union-Find veri yapısı sınıfı
class UnionFind
{
public:
    vector<int> parent, rank;
    int components;

    UnionFind(int n) : parent(n), rank(n, 0), components(n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            components--;
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        UnionFind ufAlice(n), ufBob(n);
        int edgesAdded = 0;

        // Önce Tip 3 kenarları işleyin
        for (const auto &edge : edges)
        {
            if (edge[0] == 3)
            {
                if (ufAlice.unite(edge[1] - 1, edge[2] - 1))
                {
                    ufBob.unite(edge[1] - 1, edge[2] - 1);
                    edgesAdded++;
                }
            }
        }

        // Sonra Tip 1 kenarlarını (sadece Alice için) işleyin
        for (const auto &edge : edges)
        {
            if (edge[0] == 1)
            {
                if (ufAlice.unite(edge[1] - 1, edge[2] - 1))
                {
                    edgesAdded++;
                }
            }
        }

        // Son olarak Tip 2 kenarlarını (sadece Bob için) işleyin
        for (const auto &edge : edges)
        {
            if (edge[0] == 2)
            {
                if (ufBob.unite(edge[1] - 1, edge[2] - 1))
                {
                    edgesAdded++;
                }
            }
        }

        // Eğer Alice veya Bob'un grafı tamamen geçilebilir değilse, -1 döndürün
        if (ufAlice.components != 1 || ufBob.components != 1)
        {
            return -1;
        }

        // Kullanılmayan kenar sayısını döndürün
        return edges.size() - edgesAdded;
    }
};

/*
1579. Remove Max Number of Edges to Keep Graph Fully Traversable
Hard

Alice and Bob have an undirected graph of n nodes and three types of edges:

    Type 1: Can be traversed by Alice only.
    Type 2: Can be traversed by Bob only.
    Type 3: Can be traversed by both Alice and Bob.

Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

Example 1:
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

Example 2:
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

Example 3:
Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.

Constraints:
    1 <= n <= 105
    1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
    edges[i].length == 3
    1 <= typei <= 3
    1 <= ui < vi <= n
    All tuples (typei, ui, vi) are distinct.
*/