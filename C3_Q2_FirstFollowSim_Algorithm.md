
# 1. Algorithm to Find FIRST(X)

1. **Terminal:** If $X$ is a terminal, then $\text{FIRST}(X) = \{X\}$.
2. **Epsilon ($\epsilon$):** If $X \rightarrow \epsilon$ is a production, add $\epsilon$ to $\text{FIRST}(X)$.
3. **Non-terminal:** If $X$ is a non-terminal and $X \rightarrow Y_1 Y_2 \dots Y_k$:
    * Add all non-$\epsilon$ symbols from $\text{FIRST}(Y_1)$ to $\text{FIRST}(X)$.
    * If $\text{FIRST}(Y_1)$ contains $\epsilon$, add $\text{FIRST}(Y_2)$, and repeat for subsequent symbols until a non-terminal does not derive $\epsilon$.
    * If all $Y_1 \dots Y_k$ contain $\epsilon$, add $\epsilon$ to $\text{FIRST}(X)$.

# 2. Algorithm to Find FOLLOW(A)

1. **Start Symbol:** Place `$` (end-of-input marker) in $\text{FOLLOW}(S)$, where $S$ is the start symbol.
2. **Production $A \rightarrow \alpha B \beta$:**
    * Add all non-$\epsilon$ symbols from $\text{FIRST}(\beta)$ to $\text{FOLLOW}(B)$.
3. **Production $A \rightarrow \alpha B$ OR $A \rightarrow \alpha B \beta$ (where $\text{FIRST}(\beta)$ contains $\epsilon$):**
    * Add all symbols from $\text{FOLLOW}(A)$ to $\text{FOLLOW}(B)$.
4. Repeat steps 2–3 until no new symbols are added to any FOLLOW set.
