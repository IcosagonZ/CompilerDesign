1. **Open File:** Open `input.txt` for reading. If the file fails to open, display an error and terminate.
2. **Read Character by Character:** Read a character `ch` from the file until reaching End-of-File (`EOF`).
3. **Ignore Redundant Whitespace:** If `ch` is a space (`' '`), tab (`'\t'`), newline (`'\n'`), or carriage return (`'\r'`), skip it and continue to the next character.
4. **Identify Operators:** If `ch` matches any character in the operator list (`+`, `-`, `*`, `/`, `=`, `%`, `<`, `>`), print it as an **Operator**.
5. **Identify Keywords, Numbers, and Identifiers:**
    * If `ch` is alphanumeric, start accumulating characters into a buffer.
    * Keep reading subsequent characters while they remain alphanumeric.
    * Return the first non-alphanumeric character back to the input stream using `ungetc()`.
    * Null-terminate the buffer.
    * Check token type:
    * If the buffer matches a word in the C keywords list, print it as a **Keyword**.
    * Else if the buffer starts with a digit, print it as a **Number**.
    * Otherwise, print it as an **Identifier**.
6. **Clean Up:** Close the file and end the program.
