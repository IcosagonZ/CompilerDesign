Here is a comprehensive set of 50 viva questions and answers tailored for the KTU Compiler Design (2019 Scheme) Lab curriculum, organized by topic and experiment.
# Section 1: Lexical Analysis & Tokenization Basics
1. What is the main role of a Lexical Analyzer (Scanner)?
> The lexical analyzer reads the stream of source code characters, groups them into meaningful sequences called lexemes, and produces a sequence of tokens as output for the syntax analyzer.
> 
2. What is the difference between a Token, Lexeme, and Pattern?
>  * Token: A terminal symbol returned to the parser representing a logical unit (e.g., KEYWORD, IDENTIFIER, NUMBER).
>  * Lexeme: The actual sequence of characters in the source code matching a token's pattern (e.g., int, count, 42).
>  * Pattern: The rule/description (often a regular expression) that defines how a lexeme for a token is formed.
> 
3. Why do we strip spaces, tabs, and newlines in a lexical analyzer?
> Whitespace and comments are ignored by most programming language parsers during syntax analysis. Filtering them out early reduces the workload of downstream compiler phases.
> 
4. How does a lexical analyzer handle comments?
> When the scanner encounters comment delimiters (like // or /*), it skips all subsequent characters until it reaches the closing delimiter or newline, discarding them without producing tokens.
> 
5. What is the role of a symbol table during lexical analysis?
> The symbol table stores information about identifiers (such as variable names, function names, data types, and scope). The scanner inserts newly discovered identifiers into the symbol table.
> 
6. What is input buffering in lexical analysis, and why is it used?
> Reading character by character from disk storage is inefficient. Input buffering uses two alternating buffers (or a circular buffer) with two pointers (lexeme_begin and forward) to reduce standard I/O overhead.
> 
7. What is sentinels in input buffering?
> A sentinel is a special end-of-buffer marker (usually EOF) placed at the end of each buffer half to avoid checking if the forward pointer has reached the end of the buffer on every character read.
> 
8. What is the principle of Longest Match (Maximal Munch)?
> If multiple regular expressions match the current prefix of input, the lexical analyzer chooses the longest matching lexeme (e.g., >= is matched as a single relational operator token rather than > followed by =).
> 
9. How do you distinguish keywords from identifiers in C code?
> Keywords are pre-loaded into the symbol table. When an identifier pattern is matched, the scanner checks if the string exists in the keyword table. If present, it returns the keyword token; otherwise, it returns an identifier token.
> 
10. What is Lex/Flex?
> Lex (or Flex for GNU) is a tool for automatically generating lexical analyzers from a specification file containing regular expressions and associated C code actions.
> 
# Section 2: C Implementation of Lexical Analyzer
11. Which C standard library functions are useful for character classification in lexical analysis?
> Functions from <ctype.h> such as isalpha(), isdigit(), isalnum(), and isspace().
> 
12. How do you skip redundant whitespace characters in C?
> By using a loop or condition:
> while ((ch = fgetc(fp)) != EOF && (ch == ' ' || ch == '\t' || ch == '\n'));
> 
> 
13. What is the role of ungetc() in a C-based lexical analyzer?
> ungetc(ch, fp) pushes a character back into the input stream. It is used when the analyzer reads one character too far to determine the boundary of a token.
> 
14. How do you detect multi-character operators like ==, <=, != in C?
> Read the first symbol (e.g., =). If the next character is also =, form ==. If not, use ungetc() to push the second character back and return the single symbol =.
> 
15. How can you read input line by line to maintain line counts for error reporting?
> Track the count of \n characters encountered during character reading in a global counter line_no.
> 
16. How do you implement a simple string buffer in C to store a lexeme?
> Use a character array (e.g., char lexeme[100];), append matched characters sequentially, and null-terminate it (lexeme[i] = '\0').
> 
17. How do you handle string literals (e.g., "Hello") in C lexical analyzers?
> When double quotes " are detected, read characters into the buffer until the closing " is found, handling escape sequences like \n or \" appropriately.
> 
18. What error is raised if a string literal or block comment is not terminated?
> An "Unterminated string literal" or "Unterminated block comment" error, triggered when EOF is reached before the matching closing character.
> 
# Section 3: Finite Automata & \epsilon-Closure Basics
19. What is a Finite Automaton (FA)?
> A 5-tuple (Q, \Sigma, \delta, q_0, F) consisting of a finite set of states (Q), input alphabet (\Sigma), transition function (\delta), initial state (q_0), and set of final/accepting states (F).
> 
20. What is an \epsilon-transition (epsilon transition)?
> A transition that allows an automaton to change its state without consuming any input symbol.
> 
21. Define \epsilon-closure (Epsilon Closure) of a state s.
> The set of all states reachable from state s taking only \epsilon-transitions, including state s itself.
> 
22. Is a state always included in its own \epsilon-closure?
> Yes. Since zero \epsilon-transitions are required to reach a state from itself, s \in \epsilon\text{-closure}(s).
> 
23. What algorithm is used to compute the \epsilon-closure of a state set?
> A Graph Search algorithm (such as Depth-First Search or Breadth-First Search) starting from the given set of states and following only edges labeled \epsilon.
> 
24. What data structures are commonly used in C to compute \epsilon-closure?
> A stack or queue to store pending states for traversal, a boolean array or bitset to track visited states, and a 2D adjacency list/matrix for transition tables.
> 
25. What is the time complexity of computing \epsilon-closure for all states in an NFA with V states and E transitions?
> Running DFS/BFS from all V states yields O(V \cdot (V + E)) time complexity using adjacency lists.
> 
26. What is the difference between a NFA and a DFA?
>  * DFA: Exactly one transition for every state and input symbol; no \epsilon-transitions allowed.
>  * NFA: Zero, one, or multiple transitions for a state and input symbol; may contain \epsilon-transitions.
> 
# Section 4: \epsilon-NFA to NFA Conversion
27. What is the basic idea behind converting an \epsilon-NFA to an equivalent NFA without \epsilon-transitions?
> For every state q and input symbol a, compute the new transition function \delta'(q, a) = \epsilon\text{-closure}(\delta(\epsilon\text{-closure}(q), a)).
> 
28. How are the start and final states determined when converting an \epsilon-NFA to an NFA?
>  * The start state remains the same.
>  * A state q becomes a final state in the new NFA if its \epsilon-closure contains any final state of the original \epsilon-NFA.
> 
29. Does converting an \epsilon-NFA to an NFA change the language recognized by the automaton?
> No, both automata accept the exact same language (L(\epsilon\text{-NFA}) = L(\text{NFA})).
> 
30. Does the number of states change when converting an \epsilon-NFA to an NFA without \epsilon-transitions?
> No, the set of states Q remains identical; only the transition functions and set of accepting states are recalculated.
> 
31. How is a transition matrix represented in a C program for an NFA?
> As a 3D matrix transition[state][symbol][next_state_list] or an array of linked lists, since a state can transition to multiple states on a single symbol.
> 
32. Why do we convert \epsilon-NFAs to NFAs or DFAs in compilers?
> \epsilon-NFAs are easier to construct directly from regular expressions (e.g., using Thompson's Construction), but DFAs are required for fast execution during lexical analysis.
> 
33. What is Thompson's Construction?
> An algorithm that turns any regular expression into an equivalent \epsilon-NFA using modular building blocks for union, concatenation, and Kleene star.
> 
# Section 5: NFA to DFA Conversion (Subset Construction)
34. Name the algorithm used to convert an NFA to a DFA.
> The Subset Construction Algorithm (or Power Set Construction).
> 
35. If an NFA has N states, what is the maximum possible number of states in its equivalent DFA?
> 2^N states (the power set of NFA states).
> 
36. How do you define a state in the constructed DFA?
> Each state in the DFA corresponds to a subset of states from the NFA.
> 
37. When is a DFA state considered a final/accepting state?
> A DFA state is accepting if it contains at least one state that was an accepting state in the original NFA.
> 
38. What is the initial state of the constructed DFA?
> The \epsilon-closure of the initial state of the NFA (or simply \{q_0\} if starting from an NFA without \epsilon-transitions).
> 
39. How do you compute the transition \delta_{DFA}(A, a) for a DFA state A on input a?
> \delta_{DFA}(A, a) = \epsilon\text{-closure}\left( \bigcup_{q \in A} \delta_{NFA}(q, a) \right).
> 
40. Why do we keep track of "unmarked" or "unvisited" states during Subset Construction in C?
> To iteratively process newly discovered DFA state combinations until no new subset states are generated.
> 
41. How do you map a set of NFA states to a single DFA state index in C?
> By sorting/normalizing the state set array and using a lookup structure (like a list of structures or hash map) to map unique set signatures to integer state IDs (0, 1, 2, \dots).
> 
42. Why can't we directly run an NFA during real-time lexical analysis?
> NFAs require tracking multiple execution paths simultaneously or back-tracking, which slows down execution compared to DFAs that guarantee deterministic single-path state transitions.
> 
# Section 6: DFA Minimization Algorithms
43. Why is DFA minimization necessary?
> Minimization reduces the number of states and transitions in a DFA to the theoretical minimum, saving memory and optimizing table lookup speeds in generated lexical analyzers.
> 
44. What are the two main algorithms used for DFA minimization?
>  * Equivalence Partitioning Algorithm (Myhill-Nerode / Hopcroft's Algorithm)
>  * Table-Filling Algorithm (State Elimination / Marking Algorithm)
> 
45. What is the time complexity of Hopcroft's DFA minimization algorithm?
> O(k \cdot n \log n), where n is the number of states and k is the alphabet size.
> 
46. What is the first step in the Equivalence Partitioning algorithm?
> Divide all states Q into two initial groups:
>  * P_0 = \{ F, Q \setminus F \} (Accepting states F and Non-accepting states Q \setminus F).
> 
47. When are two states p and q considered k-equivalent?
> When for every input string w of length \le k, the transitions from p and q on w both land in accepting states or both land in non-accepting states.
> 
48. What are unreachable states in a DFA, and how are they handled in minimization?
> Unreachable states are states that cannot be reached from the start state by any input sequence. They are removed before running the partitioning algorithm.
> 
49. What is a Dead State (or Trap State)?
> A non-accepting state that transitions only to itself on all input symbols.
> 
50. How do you merge equivalent states after running the minimization algorithm?
> Replace all states belonging to the same partition group with a single representative state node and update transition table references accordingly.
> 
