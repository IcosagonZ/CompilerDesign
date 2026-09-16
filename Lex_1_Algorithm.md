Algorithm to Count Vowels and Spaces using Lex

 * Initialize Counters: Set vowels = 0 and spaces = 0.

 * Read Input: Read the input text character by character through standard input (yylex()).

 * Pattern Matching:

   * If the character matches any vowel (a, e, i, o, u in lowercase or uppercase), increment vowels by 1.

   * If the character matches a space (' '), increment spaces by 1.

   * For any other character (consonants, numbers, newline, special characters), ignore it and move to the next.

 * End of Input: Detect the end of input stream (yywrap()).

 * Display Results: Print the total counts of vowels and spaces.

 * Terminate: End the program execution.
