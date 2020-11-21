#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

/**
 * Maximum size of Matrices
 */
#define MAX_SIZE 10

/**
 * Maximum difference, between do double to be equal
 */
#define EPSILON 0.001

double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size);

void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size);

int areBothNumbersEvenOrOdd(int a, int b);

void shiftFirstMatrixToBottom(double matrix[MAX_SIZE][MAX_SIZE], int size);

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

    double matrixCounted[MAX_SIZE][MAX_SIZE]
            = {{1.0, 2.0, 3.0},
               {4.0, 5.0, 6.0},
               {7.0, 8.0, 9.0}};
    /*shiftLastMatrixTotop(matrixCounted, 3);
    print_matrix(matrixCounted, 3);
    shiftFirstMatrixToBottom(matrixCounted, 3);
    print_matrix(matrixCounted, 3);*/


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
    assert(get_determinant(matrix, 3) == 3.0);


    double matrixFourByFourRandom[MAX_SIZE][MAX_SIZE]
            = {{5.0,  0.0, 3.0, -1.0},
               {3.0,  0.0, 0.0, 4.0},
               {-1.0, 2.0, 4.0, -2.0},
               {1.0,  0.0, 0.0, 5.0}};
    assert(get_determinant(matrixFourByFourRandom, 4) == 66);

    // TEESTCASES FROM MOODLE -----------------------------------------------
    double matrixTextCaseOne[MAX_SIZE][MAX_SIZE]
            = {{1.0}};
    assert(get_determinant(matrixTextCaseOne, 1) == 1);
    double matrixTextCaseTwo[MAX_SIZE][MAX_SIZE]
            = {{1.0, 2.0},
               {3.0, 4.0}};
    assert(get_determinant(matrixTextCaseTwo, 2) == -2.0);
    double matrixTextCaseThree[MAX_SIZE][MAX_SIZE]
            = {{-1.0, -2.0},
               {-3.0, -4.0}};
    assert(get_determinant(matrixTextCaseThree, 2) == -2.0);
    double matrixTextCaseFour[MAX_SIZE][MAX_SIZE]
            = {{0.0, 1.0, 2.0},
               {3.0, 2.0, 1.0},
               {1.0, 1.0, 0.0}};
    assert(get_determinant(matrixTextCaseFour, 3) == 3.0);
    double matrixTextCaseFive[MAX_SIZE][MAX_SIZE]
            = {{-1.1, -2.2, -3.4},
               {-3.2, -2.7, -1.3},
               {-1.2, -1.6, -0.7}};
    assert(fabs(get_determinant(matrixTextCaseFive, 3) - -4.687000) < EPSILON);
    double matrixTextCaseSix[MAX_SIZE][MAX_SIZE]
            = {{1.0, 2.0,  3.0},
               {4.0, -5.0, 6.0},
               {7.0, 8.0,  9.0}};
    assert(get_determinant(matrixTextCaseSix, 3) == 120);
    double matrixTextCaseSeven[MAX_SIZE][MAX_SIZE]
            = {{1.0, -1.0, 2.0,  -3.0},
               {4.0, 0.0,  3.5,  1.0},
               {2.0, -5.0, 1.0,  0.0},
               {3.0, -1.0, -1.0, 2.0}};
    assert(get_determinant(matrixTextCaseSeven, 4) == 184.5);
    double matrixTextCaseEight[MAX_SIZE][MAX_SIZE]
            = {{0.0,  -0.8, 1.3,  -0.6, 1.5,  -0.4, 1.7,  -0.2, 1.9,  0.0},
               {-1.9, 0.0,  -1.7, 2.4,  -1.5, 2.6,  -1.3, 2.8,  -1.1, 3.0},
               {3.1,  -2.8, 0.0,  -2.6, 3.5,  -2.4, 3.7,  -2.2, 3.9,  -2.0},
               {-3.9, 4.2,  -3.7, 0.0,  -3.5, 4.6,  -3.3, 4.8,  -3.1, 5.0},
               {5.1,  -4.8, 5.3,  -4.6, 0.0,  -4.4, 5.7,  -4.2, 5.9,  -4.0},
               {-5.9, 6.2,  -5.7, 6.4,  -5.5, 0.0,  -5.3, 6.8,  -5.1, 7.0},
               {7.1,  -6.8, 7.3,  -6.6, 7.5,  -6.4, 0.0,  -6.2, 7.9,  -6.0},
               {-7.9, 8.2,  -7.7, 8.4,  -7.5, 8.6,  -7.3, 0.0,  -7.1, 9.0},
               {9.1,  -8.8, 9.3,  -8.6, 9.5,  -8.4, 9.7,  -8.2, 0.0,  -8.0},
               {-9.9, 10.2, -9.7, 10.4, -9.5, 10.6, -9.3, 10.8, -9.1, 0.0}};
    assert(fabs(get_determinant(matrixTextCaseEight, 10)
                - -4411917.340032) < EPSILON);
    //printf(" get determinat %lf", get_determinant(matrixTextCaseEight, 10));
    double matrixTwoByTwo[MAX_SIZE][MAX_SIZE]
            = {{2.0, -3.0},
               {3.5, 1.0}};
    assert(get_determinant(matrixTwoByTwo, 2) == 12.5);
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
    //printf("This matrix is given with size %d: \n", size);
    //print_matrix(matrix, size);
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
        //i == 0
        //alle nach i in die temporalMatrix
        if (i == 0)
        {
            //i ist an erster Stelle, alle nach i müssen in die matrix
            for (int y = 0; y < size - 1; y++)
            {
                for (int j = 0; j < size - 1; j++)
                {
                    //printf("y-axis %d, x-axis %d and i is:%d \n", y, j + 1, i);
                    temporalMatrix[y][j] = matrix
                    [y + 1]
                    [(j + 1)];
                }
            }
        } else if (i == size - 1)
        {
            //i ist an letzter Stelle, alle vorigen müssen in die matrix
            for (int y = 0; y < size - 1; y++)
            {
                for (int j = 0; j < size - 1; j++)
                {
                    //printf("y-axis %d, x-axis %d and i is:%d \n", y, j + 1, i);
                    temporalMatrix[y][j] = matrix
                    [y]
                    [(j + 1)];
                }
            }
        } else if (i > 0)
        {
            //i ist mitten drin, alle vor i in matrix
            for (int y = 0; y < i; y++)
            {
                for (int j = 0; j < size - 1; j++)
                {
                    //printf("y-axis %d, x-axis %d and i is:%d \n", y, j + 1, i);
                    temporalMatrix[y][j] = matrix
                    [y]
                    [(j + 1)];
                }
            }
            // jetzt noch alle nach i in matrix
            for (int y = i + 1; y < size; y++)
            {
                for (int j = 0; j < size - 1; j++)
                {
                    //printf("y-axis %d, x-axis %d and i is:%d \n", y, j + 1, i);
                    temporalMatrix[y - 1][j] = matrix
                    [y]
                    [(j + 1)];
                }
            }
        }
        if (i % 2 == 0)
        {
            //number is even, so it prefix is +(positiv)
            //printf("number is even and multiplicant is: %lf\n", matrix[i][0]);
            solution = solution + matrix[i][0]
                                  * get_determinant(temporalMatrix, size - 1);
        } else
        {
            //printf("number is odd and multiplicant is: %lf\n", (-1) * matrix[i][0]);
            solution = solution + ((-1) * matrix[i][0]
                                   * get_determinant(temporalMatrix, size - 1));
        }
        //printf("Solution is %lf \n", solution);
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

void clealArray(double matrix[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            matrix[i][j] = 0.0;
        }
    }
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
 * Shifts the first matrix to the bottom and shift the othe ones 1 position up
 * @param matrix Matrix to shift
 * @param size actual size of the matrix
 */
void shiftFirstMatrixToBottom(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    double temporalMatrix[MAX_SIZE][MAX_SIZE];

    //write the complete matrix into temporal, except the first one
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 0; j <= size; ++j)
        {
            temporalMatrix[i - 1][j] = matrix[i][j];
        }
    }
    for (int j = 0; j <= size; ++j)
    {
        temporalMatrix[size - 1][j] = matrix[0][j];
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



