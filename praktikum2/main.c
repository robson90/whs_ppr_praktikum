#include <stdio.h>
#include <assert.h>

/**
 * Maximum size of Matrices
 */
#define MAX_SIZE 10

double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size);

void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size);

int areBothNumbersEvenOrOdd(int a, int b);

void shiftLastMatrixTotop(double matrix[MAX_SIZE][MAX_SIZE], int size);

/**
 * Main Function that calls all necessary methods
 * @return -1 when done with the operations
 */
int main()
{
    //Tests for areBothNumbersEvenOrOdd(a, b)
    assert(areBothNumbersEvenOrOdd(0, 0) == 1);
    assert(areBothNumbersEvenOrOdd(1, 1) == 1);
    assert(areBothNumbersEvenOrOdd(2, 2) == 1);
    assert(areBothNumbersEvenOrOdd(3, 2) == 0);
    assert(areBothNumbersEvenOrOdd(2, 3) == 0);


    double matrixOne[MAX_SIZE][MAX_SIZE]
            = {1.0};
    assert(get_determinant(matrixOne, 1) == 1.0);
    double matrixTwo[MAX_SIZE][MAX_SIZE]
            = {{1.0, 1.0},
               {1.0, 1.0}};
    assert(get_determinant(matrixTwo, 2) == 0.0);

    double matrixThree[MAX_SIZE][MAX_SIZE]
            = {{1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0}};
    assert(get_determinant(matrixThree, 3) == 0.0);

    double matrixFour[MAX_SIZE][MAX_SIZE]
            = {{1.0, 1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0, 1.0}};
    assert(get_determinant(matrixFour, 4) == 0.0);

    double matrix[MAX_SIZE][MAX_SIZE]
            = {{0.0, 1.0, 2.0},
               {3.0, 2.0, 1.0},
               {1.0, 1.0, 0.0}};
    printf(" get determinat %lf", get_determinant(matrix, 3));
    assert(get_determinant(matrix, 3) == 3.0);

    double matrixCounted[MAX_SIZE][MAX_SIZE]
            = {{1.0, 2.0, 3.0},
               {4.0, 5.0, 6.0},
               {7.0, 8.0, 9.0}};
    assert(get_determinant(matrixCounted, 3) == 0);

    double matrixFourByFourRandom[MAX_SIZE][MAX_SIZE]
            = {{5.0, 0.0, 3.0, -1.0},
               {3.0, 0.0, 0.0, 4.0},
               {-1.0, 2.0, 4.0, -2.0},
               {1.0, 0.0, 0.0, 5.0}};
    assert(get_determinant(matrixFourByFourRandom, 4) == 66);

    return -1;
}

/**
 * Return the determinant from the given matrix, with the actual size
 * @param matrix given matrix, to calculate the determinant
 * @param size actual size of matrix
 * @return the determinant of the given matrix
 */
double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    /*
     * Optimizations to be made:
     * I could check, if there are any 0.0, if yes I would choose the row or
     * column, with the most 0. Then I wouldn't even need to calculate the
     * "underDeterminant" of that number, because it is always 0.0. That
     * could massively increase performance in bigger matrices. I would have to
     * implement, the my implementation would select a specific row or column
     * on desired requirements
     */
    printf("This matrix is given with size %d: \n", size);
    print_matrix(matrix, size);
    double solution = 0;
    double temporalMatrix[MAX_SIZE][MAX_SIZE];
    //actual size is bigger than maximum bounds of array
    if (size > MAX_SIZE)
    {
        return 0.0;
    } else if (size == 1)
    {
        return matrix[0][0];
    }
    // I could test if the size is 3, then I would calculate the det(A) with
    // the sentence of Saurrus. BUT I dont want to.
    for (int i = 0; i < size; i++)
    {
        //clearMatrix(temporalMatrix);
        for (int y = 0; y < size - 1; y++)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                printf("x-axis %d, y-axis %d \n", j + 1, (i + y + 1) % (size));
                temporalMatrix[y][j] = matrix
                [(i + y + 1) % (size)]
                [(j + 1)];
            }
            //I have to shift, only when the the row of the laplace algo isnt
            // the first or the last one
            if (i != 0 && i != size -1) {
                shiftLastMatrixTotop(temporalMatrix, size - 1);
            }
        }
        if (i % 2 == 0)
        {
            //number is even, so it prefix is +(positiv)
            printf("number is even and multiplicant is: %lf\n", matrix[i][0]);
            solution = solution + matrix[i][0]
                                  * get_determinant(temporalMatrix, size - 1);
        } else
        {
            printf("number is odd and multiplicant is: %lf\n", (-1) * matrix[i][0]);
            solution = solution + ((-1) * matrix[i][0]
                                   * get_determinant(temporalMatrix, size - 1));
        }
        printf("Solution is %lf \n", solution);
    }
    return solution;
}

/**
 * Prints the given Matrix with its actual size.
 * @param matrix matix to print
 * @param size actual size of matrix
 */
void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; ++j)
        {
            printf("%.1lf  ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Retuns 1 if both numbers are Odd or both are even.
 * UNUSED right now. * @param a first number
 * @param b second number
 * @return 0 when not true, 1 when true
 */
int areBothNumbersEvenOrOdd(int a, int b)
{
    if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0))
    {
        return 1;
    } else
    {
        return 0;
    }
}

/**
 * Shifts the last matrix to the top and shift the othe ones 1 position down
 * @param matrix Matrix to shift
 * @param size actual size of the matrix
 */
void shiftLastMatrixTotop(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    double temporalMatrix[MAX_SIZE][MAX_SIZE];
    //write the last martrix at the starting position
    for (int j = 0; j <= size; ++j)
    {
        temporalMatrix[0][j] = matrix[size - 1][j];
    }
    //start front to back copy alle matrix, except last one, y-axis remebered
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 0; j <= size; ++j)
        {
            temporalMatrix[i][j] = matrix[i - 1][j];
        }
    }
    //copy temporal on top of the given Matrix
    for (int i = 0; i <= size; ++i)
    {
        for (int j = 0; j <= size; ++j)
        {
            matrix[i][j] = temporalMatrix[i][j];
        }
    }

}