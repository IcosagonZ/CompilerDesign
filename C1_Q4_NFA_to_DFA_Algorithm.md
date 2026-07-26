Algorithm: Conversion of NFA to DFA (Subset Construction)**

**Input**

- Number of NFA states N and input symbols M.
- NFA transition table NFA\[symbol]\[from\\\_state]\[to\\\_state].

**Steps**

1. **Initialize DFA Start State:**
2. - Create the start state of the DFA D\_0 = \\{q\_0\\}, containing only the NFA start state q\_0.
   - Add D\_0 to the list of unvisited DFA states.
   - Set n\_dfa = 1.
   **Subset Construction Loop:**
3. - While there are unvisited DFA states D\_i:
     - Mark D\_i as processed/visited.
     - For each input symbol a:
       1. Compute the set of reachable NFA states U: U = \bigcup\_{q \in D\_i} \delta\_{NFA}(q, a)
       2. Check if the set U already exists as a DFA state in the list of registered DFA states:
          - **If U is a new state:** Add U as a new DFA state D\_{new}, increment n\_dfa, and set transition DFA\[D\_i]\[a] = D\_{new}.
          - **If U already exists as D\_j:** Set transition DFA\[D\_i]\[a] = D\_j.
   **Output Results:**
   - Print the generated DFA state mapping and the complete DFA transition table.
