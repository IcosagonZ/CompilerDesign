# Epsilon-Closure finder

n_states = 0
ematrix = []
closure = [[0,0,0,0],[0,0,0,0],[0,0,0,0], [0,0,0,0]]
visited = [0,0,0,0]

def dfs(start, current):
    global visited, closure

    visited[current] = 1
    closure[start][current] = 1

    for next in range(n_states):
        if(ematrix[current][next]==1 and visited[next]==0):
            dfs(start, next)

def main():
    global n_states, ematrix, visited

    # Input
    n_states = 4
    ematrix = [[0,1,0,0],[0,0,1,0],[0,0,0,0],[0,1,0,0]]

    # Find eclosure
    for i in range(n_states):
        visited = [0,0,0,0]
        dfs(i,i)

    print(closure)

if __name__ == "__main__":
    main()
