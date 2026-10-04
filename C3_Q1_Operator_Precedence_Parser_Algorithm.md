# Algorithm: Operator Precedence Parser

1. **Initialize Data Structures:**
    * Define the **operator precedence table** specifying relations (`<` Shift, `>` Reduce, `a` Accept, `e` Error) for combinations of operators/terminals (`+`, `*`, `id`, `$`).
    * Initialize a `stack` with the start symbol `$` and set `top = 0`.
    * Read the input string `input` ending with `$`, and set input index `i = 0`.

2. **Parsing Loop:**
    * Set `a = stack[top]` (top element of stack) and `b = input[i]` (current input character).
    * Look up the operator precedence relation `rel = table[a][b]`.

3. **Check Precedence Relation:**
    * **If `rel` is `'<'` or `'='` (Shift):**
    * Increment `top`.
    * Push `b` onto `stack` (`stack[top] = b`).
    * Advance input pointer (`i = i + 1`).

    * **If `rel` is `'>'` (Reduce):**
    * Pop top element from `stack` (`top = top - 1`).

    * **If `rel` is `'a'` (Accept):**
    * Input string is valid. Print **"ACCEPTED"** and terminate.

    * **If `rel` is `'e'` or invalid (Error):**
    * Input string is invalid. Print **"REJECTED"** and terminate.

4. **Repeat** Step 2 until the input is accepted or an error occurs.

# OUTPUT
```
Enter input expression (end with $): a+b*c$

Stack           Relation        Input           Action
------------------------------------------------------
$               <               a+b*c$          Shift a
$a              >               +b*c$           Reduce a
$               <               +b*c$           Shift +
$+              <               b*c$            Shift b
$+b             >               *c$             Reduce b
$+              <               *c$             Shift *
$+*             <               c$              Shift c
$+*c            >               $               Reduce c
$+*             >               $               Reduce *
$+              >               $               Reduce +
$               a               $               ACCEPTED!
```
