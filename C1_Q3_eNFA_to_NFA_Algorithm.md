**1. Algorithm: Conversion of \epsilon-NFA to NFA without \epsilon-transitions**

**Input**

- Number of states N and input symbols M (excluding \epsilon).
- \epsilon-transition relation matrix E.
- Transition relation array T\[symbol]\[from\\\_state]\[to\\\_state].

**Steps**

1. **Initialize \epsilon-Closure Array:**
2. - Create an N \times N matrix e\_closure initialized to 0.
   **Compute \epsilon-Closure for Every State:**
3. - For each state q\_i \ (0 \le i < N):
     - Mark e\_closure\[q\_i]\[q\_i] = 1 (a state is always in its own \epsilon-closure).
     - Traverse all reachable states via \epsilon-transitions recursively/iteratively and set e\_closure\[q\_i]\[q\_j] = 1 if q\_j is reachable from q\_i using only \epsilon-moves.
   **Compute New Transitions (\delta'):**
4. - For each state q\_i, input symbol a, and target state q\_k:
     - Define transition \delta'(q\_i, a) as: \delta'(q\_i, a) = \epsilon\text{-closure}(\delta(\epsilon\text{-closure}(q\_i), a))
     - In code logic:
       - Find all states q\_j in \epsilon\text{-closure}(q\_i).
       - For each q\_j, find all transitions to q\_m on symbol a.
       - For each q\_m, add all states in \epsilon\text{-closure}(q\_m) to the new transition set for state q\_i on symbol a.
   **Output Results:**
   - Print the new transition table representing the NFA without \epsilon-transitions.
