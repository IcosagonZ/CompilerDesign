# NFA to DFA - by mee

def main():
    n_symbols = 2
    n_states = 3

    nfa = {
        0: [
            [1,1,0],
            [0,0,0],
            [0,0,0]
        ],
        1: [
            [1,0,0],
            [0,0,1],
            [0,0,0]
        ]
    }

    dfa_all_states = []

    for symbol in range(n_symbols):
        dfa_states = []
        for states in range(n_states):
            states_temp = []
            for state in range(n_states):
                if(nfa[symbol][states][state]==1):
                    states_temp.append(state)
            if(states_temp not in dfa_states):
                dfa_states.append(states_temp)
        print("Symbol {} -> States = {}".format(symbol, dfa_states))
        dfa_all_states.append(dfa_states)

    # Find DFA
    for symbol in range(n_symbols):


if __name__ == "__main__":
    main()
