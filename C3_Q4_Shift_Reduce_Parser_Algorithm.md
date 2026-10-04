 * Start


 * Initialize stack as empty, top = -1, and input string index i = 0.


 * Read input string into input array.


 * Repeat while i < length(input):


   * Shift: Push input[i] onto stack, increment top, and print "SHIFT".


   * Check Reduction:


     * If top of stack is 'i', reduce to 'E' (stack[top] = 'E') and print "REDUCE E -> id".


     * If stack top contains 'E+E' or 'E*E', pop 2 elements (top = top - 2), replace with 'E', and print "REDUCE E -> E+E" or "REDUCE E -> E*E".


   * Increment i.


 * Perform final reduction check on remaining stack content.


 * If top == 0 and stack[0] == 'E':


   * Print "String Accepted".


   * Else: Print "String Rejected".


 * Stop
