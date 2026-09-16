Algorithm

 * Define three states:

   * State 0 (Start/Initial): The string has not matched a pattern ending in 10.

   * State 1: The last character read was 1.

   * State 2 (Accepting): The last two characters read were 10.

 * Read the input string character by character from left to right.

 * For each character:

   * In State 0: If character is 1, transition to State 1. If 0, stay in State 0.

   * In State 1: If character is 0, transition to State 2. If 1, stay in State 1.

   * In State 2: If character is 1, transition to State 1. If 0, transition to State 0.

 * When the end of the string (\n or EOF) is reached, check the final state:

   * If the final state is State 2, output "ACCEPTED".

   * Otherwise, output "REJECTED".
Lex Program (string.l)

How to Run
 * Compile the Lex file:
   flex string.l

 * Compile the C code:
   gcc lex.yy.c -o output

 * Execute:
   ./output

