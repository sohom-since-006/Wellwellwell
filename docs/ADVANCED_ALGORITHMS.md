# 🚀 Advanced Data Structures & Algorithmic Paradigms

This dossier covers advanced modules implemented across graph connectivity, string theory, range queries, and number theory.

---

## 1. Graph Algorithms
- **Prim's Algorithm**: Greedy Minimum Spanning Tree with priority queue $\mathcal{O}((V + E) \log V)$.
- **Kosaraju's Algorithm**: Two-pass DFS for Strongly Connected Components (SCC) in directed graphs.
- **Bipartite Verification**: 2-coloring BFS/DFS graph bipartition validation.
- **Cycle Detection**: Directed (recursion stack) and Undirected (parent backtracking).

---

## 2. Advanced Range Queries & Self-Balancing Trees
- **Fenwick Tree (BIT)**: Prefix sums and updates via two's complement lowest set bit ($i \ \& \ (-i)$).
- **Segment Tree**: Arbitrary range queries with lazy propagation support.
- **AVL / Red-Black Trees**: Height balancing with strict rotation guarantees.

---

## 3. String Theory & Pattern Matching
- **Manacher's Algorithm**: Linear $\mathcal{O}(N)$ longest palindromic substring discovery.
- **Z-Algorithm**: Prefix comparison array for exact linear pattern locating.
- **Trie Autocomplete**: Prefix tree combined with depth-first traversal for live keyword synthesis.

---

## 4. Number Theory & Dynamic Programming
- **Chinese Remainder Theorem**: System of modular congruences via extended Euclidean inverse.
- **Miller-Rabin Test**: Probabilistic polynomial-time primality test.
- **Matrix Exponentiation**: $\mathcal{O}(\log N)$ recurrence relation calculation.
