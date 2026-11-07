# e-NFA to NFA

n_states = 0
n_symbols = 0
ematrix = []
transitions = {}
closure = []
visited = []

def dfs(start, current):
    visited[current] = 1
    closure[start][current] = 1
    for next in range(n_states):
        if(ematrix[current][next]==1 and visited[next]==0):
            dfs(start,next)

def main():
    global n_states, ematrix, visited

    # Input
    n_states = 3
    n_symbols = 2
    ematrix = [
        [1, 1, 0],
        [0, 1, 1],
        [0, 0, 1]
    ]
    transitions = {
        0: [
            [1, 0, 0],
            [0, 0, 0],
            [0, 0, 0]
        ],
        1: [
            [0, 0, 0],
            [0, 1, 0],
            [0, 0, 0]
        ]
    }

    # Find eclosure
    for i in range(n_states):
        closure.append([0]*n_states)
    for i in range(n_states):
        visited = [0]*n_states
        dfs(i,i)

    print("Closure matrix is: ", end="")
    print(closure)

    print("\n")

    # NFA calculation
    print("NFA:")
    for state in range(n_states):
        for symbol in range(n_symbols):
            nfa_targets = set()
            for state1 in range(n_states):
                if(closure[state][state1]==1):
                    for state2 in range(n_states):
                        if(transitions[symbol][state1][state2]==1):
                            for state3 in range(n_states):
                                if(closure[state2][state3]==1):
                                    nfa_targets.add(state3)
            print("State q{} on symbol {}: states are: {}".format(state, symbol, nfa_targets))

if __name__ == "__main__":
    main()
