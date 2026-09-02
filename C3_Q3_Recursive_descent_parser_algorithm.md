Step 1: Start.
Step 2: Read the input expression string into a buffer and set a pointer (ip) to the first character.
Step 3: Call function E() to parse the expression.
Step 4: Inside E(), call T(), then repeatedly consume '+' or '-' operators followed by T().
Step 5: Inside T(), call F(), then repeatedly consume '*' or '/' operators followed by F().
Step 6: Inside F(), if current character is alphanumeric, advance ip; if '(', consume '(', call E(), and match ')'; otherwise, reject.
Step 7: After E() returns, if ip reaches the end of the string ('\0'), print "Accepted"; otherwise, print "Rejected".
Step 8: Stop.
