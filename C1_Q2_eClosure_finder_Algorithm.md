# Algorithm

1. **Input:** Number of states $N$ and the $N \times N$ $\varepsilon$-transition matrix.
2. **For each state $i$ from $0$ to $N-1$:**
    * Reset the `visited` array to all `0`s.
    * Run **DFS($i$, $i$)**:
    * Mark state `current` as visited.
    * Add `current` to $\varepsilon\text{-closure}(i)$.
    * For every state `next` from $0$ to $N-1$:
    * If there is an $\varepsilon$-transition from `current` to `next` and `next` is unvisited, call **DFS($i$, `next`)**.
3. **Output:** Print $\varepsilon\text{-closure}(i)$ for each state $i$.

# Output
```
Enter total no of states: 3
Enter epsilon transition adjacency matrix (1 if exists else 0):
0 1 0
0 0 1
0 0 0  

Epsilon Closures
e-closure(q0) = { q0 q1 q2 }
e-closure(q1) = { q1 q2 }
e-closure(q2) = { q2 }
```
