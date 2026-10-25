Here are 100 practice questions and answers based on the Compiler Design reference document provided. The answers are kept short, clear, and easy to memorize for quick review and viva preparation.
Section 1: Basics of Compilers & Language Processing
 * What is a compiler?
   * Answer: A program that reads source code in one language and translates it into an equivalent program in a target language, reporting any errors.
 * What are the two primary parts of compilation?
   * Answer: Analysis (breaks code down) and Synthesis (builds target code).
 * What does the Analysis part of compilation do?
   * Answer: It breaks the source program into constituent parts to create an intermediate representation.
 * What does the Synthesis part of compilation do?
   * Answer: It builds the target machine code using the intermediate representation.
 * What are the main phases in the Analysis part?
   * Answer: Linear analysis, Hierarchical analysis, and Semantic analysis.
 * Order the language processing steps from source code to target machine code.
   * Answer: Preprocessor \rightarrow Compiler \rightarrow Assembler \rightarrow Linker/Loader.
 * What is a preprocessor?
   * Answer: A tool that processes the source program before compilation (e.g., expanding macros or header files).
 * What does an assembler do?
   * Answer: Translates assembly code into relocatable machine code.
 * What is the function of a Linker/Loader?
   * Answer: Linker combines relocatable object files/libraries; Loader loads the final executable into memory.
 * What are the common classifications of compilers?
   * Answer: Single-pass, Multi-pass, Load-and-go, and Debugging/Optimizing compilers.
 * What is a "Load-and-go" compiler?
   * Answer: A compiler that executes the compiled code immediately in memory without saving machine code to disk.
 * Name three "cousins" of a compiler.
   * Answer: Preprocessors, Assemblers, Loaders/Link-editors.
 * What is a Compiler-Compiler?
   * Answer: A software tool or framework used to generate a compiler automatically from language specifications.
 * List three compiler construction tools.
   * Answer: Parser generators, Scanner generators, and Automatic code generators.
 * What is a Data-Flow Engine in compiler construction?
   * Answer: A tool that helps gather data dependency information for code optimization.
Section 2: Phases of a Compiler
 * Name the six main phases of a compiler.
   * Answer: 1. Lexical Analyzer 2. Syntax Analyzer 3. Semantic Analyzer 4. Intermediate Code Generator 5. Code Optimizer 6. Code Generator.
 * What is the Front End of a compiler?
   * Answer: Phases dependent on the source language, such as Lexical, Syntactic, Semantic Analysis, and Symbol Table management.
 * What is the Back End of a compiler?
   * Answer: Phases dependent on the target machine, such as Code Optimization and Code Generation.
 * What is the primary job of the Lexical Analyzer?
   * Answer: To read the source character stream left-to-right and group characters into meaningful tokens.
 * What is the primary job of the Syntax Analyzer?
   * Answer: To group tokens hierarchically into parse trees according to grammar rules.
 * What is the primary job of the Semantic Analyzer?
   * Answer: To perform checks ensuring code components fit together meaningfully (mainly type checking).
 * What is the Intermediate Code Generator phase?
   * Answer: Generates a machine-independent intermediate representation of the source program.
 * What is the Code Optimizer phase?
   * Answer: Transforms intermediate code to make it run faster and consume less memory.
 * What is the Code Generator phase?
   * Answer: Converts intermediate code into target assembly or machine language.
 * Why are Lexical and Syntax Analyzers separated?
   * Answer: For simpler design, improved compiler efficiency, and enhanced portability.
Section 3: Lexical Analysis & Regular Expressions
 * Define a Token.
   * Answer: A sequence of characters representing a logical unit (e.g., id, if, num).
 * Define a Lexeme.
   * Answer: The actual sequence of characters in the source code matching a token pattern (e.g., count, 3.14).
 * Define a Pattern.
   * Answer: A set of rules describing how strings are formed for a token.
 * What is Union in language operations (L \cup M)?
   * Answer: The set of strings that belong to either language L or language M.
 * What is Concatenation (LM)?
   * Answer: The set of strings formed by appending a string from M to a string from L.
 * What is Kleene Closure (L^*)?
   * Answer: Zero or more concatenations of language L.
 * What is Positive Closure (L^+)?
   * Answer: One or more concatenations of language L.
 * Write the regular expression for an identifier.
   * Answer: letter (letter | digit)*.
 * What does the regular expression shorthand ? mean?
   * Answer: Zero or one instance (optional).
 * What does the regular expression shorthand + mean?
   * Answer: One or more instances.
 * What does character class [abc] represent?
   * Answer: Matches any single character: a or b or c.
 * What is Panic Mode error recovery in lexical analysis?
   * Answer: Discarding characters one by one until a well-formed token is found.
 * List three lexical error recovery actions besides Panic Mode.
   * Answer: Deleting extra characters, inserting missing characters, or replacing incorrect characters.
 * What is transposing adjacent characters in error recovery?
   * Answer: Swapping two nearby characters to fix misspelled keywords (e.g., tehn \rightarrow then).
 * What scanner generator utility is popular in UNIX systems?
   * Answer: LEX (or Flex).
Section 4: Syntax Analysis & Context-Free Grammars
 * Define Context-Free Grammar (CFG).
   * Answer: A 4-tuple G = (V, T, S, P) representing Non-terminals, Terminals, Start symbol, and Production rules.
 * What is a Terminal in CFG?
   * Answer: Basic symbols or tokens that cannot be expanded further.
 * What is a Non-terminal in CFG?
   * Answer: Syntactic variables that expand into sequences of terminals and non-terminals.
 * What is a Derivation?
   * Answer: A sequence of production rule replacements starting from the start symbol S to form a string.
 * What is Leftmost Derivation?
   * Answer: A derivation where the leftmost non-terminal is always replaced first.
 * What is Rightmost Derivation?
   * Answer: A derivation where the rightmost non-terminal is always replaced first.
 * What is an Ambiguous Grammar?
   * Answer: A grammar that produces more than one parse tree for a single string.
 * What are the two main issues in parsing?
   * Answer: Specification of syntax and representation of input after parsing.
 * List three common problems in Top-Down parsing.
   * Answer: Backtracking, Left recursion, and Ambiguity.
 * What is Left Recursion?
   * Answer: A condition where a production rule has the form A \rightarrow A\alpha, causing infinite loops in top-down parsers.
 * What is Left Factoring?
   * Answer: Rewriting productions to defer decision-making when rules share a common prefix.
 * What is the Dangling-Else problem?
   * Answer: An ambiguity where an else can attach to multiple preceding if statements.
 * What is FIRST(X) in parsing?
   * Answer: The set of terminal symbols that begin strings derived from X.
 * What is FOLLOW(A) in parsing?
   * Answer: The set of terminal symbols that can appear immediately to the right of A in some sentential form.
 * What symbol is always in FOLLOW(S) for start symbol S?
   * Answer: The end-marker symbol $.
Section 5: Parsers & Parsing Techniques
 * What is an Operator Precedence Parser?
   * Answer: A shift-reduce parser applied to operator grammars with no \epsilon-productions and no adjacent non-terminals on right-hand sides.
 * State an advantage of Operator Precedence Parsing.
   * Answer: It is straightforward and easy to implement.
 * State a disadvantage of Operator Precedence Parsing.
   * Answer: Hard to handle operators with dual precedence (like unary vs binary minus).
 * What is Shift-Reduce Parsing?
   * Answer: A bottom-up parsing method that shifts tokens onto a stack and reduces matching patterns to non-terminals.
 * What is a Handle?
   * Answer: A substring matching a production's right side whose reduction represents a step in reverse rightmost derivation.
 * What is Handle Pruning?
   * Answer: The process of repeatedly finding and replacing handles to construct a rightmost derivation in reverse.
 * What are Viable Prefixes?
   * Answer: Prefixes of right sentential forms that can legally appear on a shift-reduce parser stack.
 * What is an LR(0) item?
   * Answer: A production rule with a dot . added to mark the current parsing position.
 * What is a Kernel Item in LR parsing?
   * Answer: Initial item S' \rightarrow .S or any item whose dot is NOT at the far-left position.
 * What is a Non-Kernel Item in LR parsing?
   * Answer: An item whose dot is at the far-left position of the right side.
 * List the three major types of LR parsers.
   * Answer: SLR (Simple LR), LALR (Look Ahead LR), and Canonical LR.
 * Which LR parser is the most powerful?
   * Answer: Canonical LR parser.
 * What does YACC stand for?
   * Answer: Yet Another Compiler-Compiler.
 * What type of parser does YACC generate?
   * Answer: LALR parser.
 * What is Phrase-Level Error Recovery in parsing?
   * Answer: Filling blank parse-table entries with routines that insert, delete, or alter input symbols.
Section 6: Intermediate Code Generation
 * Name three common intermediate code representations.
   * Answer: Syntax Trees, Postfix notation, and Three-Address Code (TAC).
 * What is Three-Address Code (TAC)?
   * Answer: Code consisting of instructions where each statement has at most three operands.
 * What is a Quadruple?
   * Answer: A TAC implementation structure containing four fields: op, arg1, arg2, and result.
 * What is a Triple?
   * Answer: A TAC representation avoiding explicit temporary names by using positional pointer references.
 * What is an Indirect Triple?
   * Answer: A listing technique using pointers to a list of triples rather than moving physical code around.
 * What is Back-patching?
   * Answer: Filling in unspecified label addresses in jump statements during code generation using semantic actions.
 * What does mklist(i) do in back-patching?
   * Answer: Creates a new list containing an index i to an instruction.
 * What does merge_list(p1, p2) do in back-patching?
   * Answer: Concatenates two target label instruction lists p1 and p2.
 * What does backpatch(p, i) do?
   * Answer: Inserts target label i as the location for all statements on list p.
 * Give TAC for a or b and not c.
   * Answer:
     t1 := not c
     t2 := b and t1
     t3 := a or t2
 * Why use intermediate code instead of direct machine code?
   * Answer: Improves portability by allowing easy reuse of front-ends or back-ends across multiple targets.
Section 7: Optimization & Data Structures
 * What is a Basic Block?
   * Answer: A straight-line sequence of code entered at the start and left at the end without internal jumps.
 * What is a Flow Graph?
   * Answer: A directed graph whose nodes are basic blocks and edges show control flow paths.
 * What is a DAG (Directed Acyclic Graph)?
   * Answer: A node-and-edge graph without cycles used to analyze transformations inside a basic block.
 * Mention two applications of DAG in optimization.
   * Answer: Eliminating common sub-expressions and detecting variables used/computed across blocks.
 * What is Peephole Optimization?
   * Answer: Locally optimizing target code by analyzing a tiny window ("peephole") of consecutive instructions.
 * List three characteristics/techniques of Peephole Optimization.
   * Answer: Redundant instruction elimination, algebraic simplification, and use of machine idioms.
 * What is Code Motion?
   * Answer: Moving loop-invariant expressions outside a loop to reduce repetitive evaluation.
 * What are the primary goals of Code Movement?
   * Answer: Reducing overall program size (space) and execution frequency (time).
 * What is Dead Code Elimination?
   * Answer: Removing statements that compute values that are never used anywhere in the program.
 * What is Strength Reduction?
   * Answer: Replacing expensive operations with cheaper ones (e.g., replacing x \times 2 with x + x).
 * How is target instruction cost typically calculated?
   * Answer: Cost = 1 + \text{cost of source addressing mode} + \text{cost of destination addressing mode}.
Section 8: Symbol Tables & Run-time Storage
 * What is a Symbol Table?
   * Answer: A fast-lookup data structure storing variable identifiers, data types, scope, and memory attributes.
 * When are entries added to a Symbol Table?
   * Answer: As soon as identifiers are recognized during the Lexical Analysis phase.
 * List three storage allocation strategies.
   * Answer: Static allocation, Stack allocation, and Heap allocation.
 * What is Static Allocation?
   * Answer: Allocating memory for all data objects permanently at compile time.
 * What is Stack Allocation?
   * Answer: Managing procedure activations and local variables dynamically using a LIFO stack.
 * What is an Activation Record?
   * Answer: A block of stack memory allocated for managing data needed for a single execution of a procedure.
 * List four items contained in an Activation Record.
   * Answer: Local variables, saved registers, control links, and return values.
 * What is Dynamic Scoping?
   * Answer: Scope resolution where non-local names resolve to the most recently called, active procedure at runtime.
