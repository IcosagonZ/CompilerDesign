
1. Initialize two counters: line_count = 0 and tab_count = 0.

2. Read the input character by character using the Lex engine.

3. If the character is a newline (\n), increment line_count.

4. If the character is a tab (\t), increment tab_count.

5. Ignore all other characters.

6. When the end of input (EOF) is reached, print line_count and tab_count.