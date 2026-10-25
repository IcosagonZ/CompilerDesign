Algorithm: Intermediate Code Generation (Three-Address Code)
 * Start
 * Input: Read a simple arithmetic expression string (e.g., a+b*c).
 * Initialize: Set a counter variable temp_count = 1 for generating temporary variables (t_1, t_2, \dots).
 * Define Precedence: Define an array of operators in order of precedence: ['/', '*', '-', '+'].
 * Scan and Generate:
   * Iterate through each operator in order of precedence.
   * Scan the input expression string from left to right.
   * If the current character matches the target operator:
     * Identify the left operand (character before the operator) and right operand (character after the operator).
     * Output: Print the Three-Address Code instruction in the format:
       
     * Replace the processed sub-expression with the new temporary variable representation in the string.
     * Increment temp_count.
     * Reset the scan position to re-evaluate the modified expression.
 * Repeat Step 5 until all operators are processed.
 * Stop
