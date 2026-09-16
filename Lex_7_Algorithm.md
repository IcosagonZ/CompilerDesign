Algorithm

1. Initialize a global integer variable count = 0.
2. Define Lex Pattern: Create a regular expression to match strings where the 5th character is 'k' or 'K'.
    1. Pattern: ^[a-zA-Z0-9]{4}[kK][a-zA-Z0-9]*$ (Matches any 4 alphanumeric characters, followed by 'k' or 'K', followed by any remaining sequence of characters).
3. Scan Input: Read the input stream word by word or line by line using the Lex pattern matching rules.
4. Increment: Each time the regular expression pattern matches a word, increment count by 1.
5. Ignore: Match and ignore all other non-matching words or whitespace tokens.
6. Output: Print the final value of count in the main() function after yylex() finishes reading the input (EOF).
