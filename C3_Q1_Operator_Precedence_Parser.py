# Operator precedence parser
# id > + > * >$

precedence = [
    # id  +   *   $
    ['=','>','>','>'], # id
    ['<','>','<','>'], # +
    ['<','>','>','>'], # *
    ['<','<','<','a']  # $
]

def get_index(c):
    if(c=='+'):
        return 1
    elif(c=='*'):
        return 2
    elif(c=='$'):
        return 3
    elif(c.isalnum()):
        return 0
    else:
        return -1

def main():
    stack = ['$']
    string = input("Input expression: ")

    i = 0

    print("STK\tREL\tINP\tACT")

    while(True):
        a = stack[-1]
        b = string[i]

        row = get_index(a)
        col = get_index(b)

        if(row==-1 or col==-1):
            print("Illegal character >:(")
            return 0

        rel = precedence[row][col]
        print("{}\t{}\t{}\t".format(stack[-1],rel,string[i]), end="")

        if(rel=='<' or rel=='='):
            # shift
            i+=1
            stack.append(b)
            print("Shift")
        elif(rel=='>'):
            # reduce
            stack.pop()
            print("Reduce")
        elif(rel=='a'):
            # accept
            print("Accept")
            break
        else:
            print("Error")
            break

if __name__ == "__main__":
    main()
