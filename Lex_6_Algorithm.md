Algorithm

1. Initialize a variable comment_count = 0.
2. Define Rules:
    1. Match single-line comments starting with // up to the end of the line (\n). Increment comment_count.
    2. Match multi-line comments starting with /* and ending with */. Increment comment_count.
    3. Match all other characters (including newlines) and do nothing (skip them).

3. Scan Input: Feed the input stream through the lexical analyzer.
4. Output: Print comment_count after reaching the end of the file (EOF).
