Algorithm: DFA Minimization (Partitioning Method)

### Input:
- A Deterministic Finite Automaton $M = (Q, \\Sigma, \\delta, q_0, F)$
  - $Q$: Set of states
  - $\\Sigma$: Alphabet / Input symbols
  - $\\delta$: Transition function $Q \\times \\Sigma \\rightarrow Q$
  - $q_0$: Initial state
  - $F$: Set of final/accepting states

### Output:
- Minimized DFA $M' = (Q', \\Sigma, \\delta', q_0', F')$

## Steps

### Step 1: Initial Partitioning ($P_0$)
1. Divide the set of all states $Q$ into two disjoint groups:
   - $G_1 = F$ (Final states)
   - $G_2 = Q \\setminus F$ (Non-final states)
2. Form the initial partition $P_0 = \\{ G_1, G_2 \\}$.

### Step 2: Iterative Refinement ($P_k$)
For each group $G$ in the current partition $P_{k-1}$:
1. Check if all states in $G$ transition to states within the **same group** for every input symbol $a \\in \\Sigma$.
2. If two states $s_1, s_2 \\in G$ transition to states in **different groups** for any input symbol $a$:
   - Split $G$ into subgroups such that states remaining together transition to the same target groups for all input symbols.
3. Form the new partition $P_k$.

### Step 3: Termination Condition
- Repeat **Step 2** until $P_k = P_{k-1}$ (i.e., no further splitting occurs)

### Step 4: Construct Minimized DFA
1. **States ($Q'$):** Each final group in $P_k$ becomes a single state in the minimized DFA.
2. **Start State ($q_0'$):** The group containing $q_0$ is the new start state.
3. **Final States ($F'$):** Any group containing states from $F$ becomes a final state.
4. **Transitions ($\delta'$):** For a group $G$ and symbol $a$, select a representative state $s \\in G$:
   $$\\delta'(G, a) = \\text{Group containing } \\delta(s, a)$$

