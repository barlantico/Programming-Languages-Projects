#   Program #3
#   Python version of matrix multiplication utilizing 4 methods. Reads
#   in two matrices and prints result. 
#   CS320-1
#   10-14-2019
#   @author  Brian Arlantico cssc0443
 
import sys
 
#   Read in the dimensions of matrices and fill arrays A & B
#   and returns array size C.
def read_matrices(A,B):
    with open(sys.argv[1]) as f:
        m = [int(x) for x in next(f).split()][0]
        n = [int(x) for x in next(f).split()][0]
        p = [int(x) for x in next(f).split()][0]
        
        for i in range(m):
            A.append([int(x) for x in next(f).split()])
        
        for i in range(n):
            B.append([int(x) for x in next(f).split()])
        
        C = [ [ 0 for i in range(p) ] for j in range(m) ]
        
 
    return C
 
#   Prints formatted matrix from argument.
def print_matrix(matrix):
    print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in matrix]))
 
#   Multiplies matrices A & B and fills matrix C with 
#   multiplication result.
def mult_matrices(A,B,C):
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
 
 
def main():
    print('Program #3, Brian Arlantico, cssc0443')
    if len(sys.argv) != 2:
        print('Usage: python3 p3.py dataFileName')
        sys.exit()
 
    A = []
    B = []
 
    C = read_matrices(A,B)
    
    print('Matrix A contents: ')
    print_matrix(A)
    print()
 
    print('Matrix B contents: ')
    print_matrix(B)
    print()
 
    mult_matrices(A,B,C)
 
    print('Matrix A * B is: ')
    print_matrix(C)
    
    sys.exit()
 
# Begin program
if __name__ == '__main__':
    main()
    

