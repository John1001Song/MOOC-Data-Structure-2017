
# polynomials multiplication
def polyMult(poly1, poly2):

    pass

# polynomials addition
def polyAdd(poly1, poly2):

    pass

# input the raw data and output two polynomials
def dataHandle(rawInput):
    # capture two polynomials sizes
    poly1Size = rawInput[0]
    poly2Size = rawInput[poly1Size*2+1]

    # catch polynomials contents
    poly1 = rawInput[1:poly1Size*2+1]
    poly2 = rawInput[poly1Size*2+2:]

    return poly1, poly2




rawInput = input()
poly1, poly2 = rawInput.split('\n')

print(poly1, poly2)

#(poly1, poly2) = dataHandle(rawInput)
