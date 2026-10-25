Algorithm: Code Generation (Back End of Compiler)
 * Start the program.
 * Read the number of Three-Address Code (TAC) statements, N.
 * Read N TAC statements from the user.
 * For each statement from 1 to N:
   * Parse the statement into res, arg1, op, and arg2.
   * If the statement is an assignment (res = arg1):
     * Emit: MOV AX, arg1
     * Emit: MOV res, AX
   * Else if the statement is a binary operation (res = arg1 \ op \ arg2):
     * Emit: MOV AX, arg1
     * If op is +, emit: ADD AX, arg2
     * If op is -, emit: SUB AX, arg2
     * If op is *, emit: IMUL arg2
     * If op is /, emit: MOV DX, 0 followed by IDIV arg2
     * Emit: MOV res, AX
 * Stop the program.
