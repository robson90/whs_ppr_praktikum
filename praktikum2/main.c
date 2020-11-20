#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 10

double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size);

void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size);

int areBothNumbersEvenOrOdd(int a, int b);

void clearMatrix(double matrix[MAX_SIZE][MAX_SIZE]);

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
    //assert(get_determinant(matrixOne, 1) == 1.0);
    double matrixTwo[MAX_SIZE][MAX_SIZE]
            = {{1.0, 1.0},
               {1.0, 1.0}};
    //assert(get_determinant(matrixTwo, 2) == 0.0);

    double matrixThree[MAX_SIZE][MAX_SIZE]
            = {{1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0}};
    //assert(get_determinant(matrixThree, 3) == 0.0);

    double matrixFour[MAX_SIZE][MAX_SIZE]
            = {{1.0, 1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0, 1.0},
               {1.0, 1.0, 1.0, 1.0}};
    //assert(get_determinant(matrixFour, 4) == 0.0);
/**
    double matrix[MAX_SIZE][MAX_SIZE]
            = {{0.0, 1.0, 2.0},
               {3.0, 2.0, 1.0},
               {1.0, 1.0, 0.0}};**/

    double matrix[MAX_SIZE][MAX_SIZE]
            = {{1.0, 2.0, 3.0},
               {4.0, 5.0, 6.0},
               {7.0, 8.0, 9.0}};
    printf(" get determinat %lf", get_determinant(matrix, 3));
    //assert(get_determinant(matrix, 3) == 3.0);

    /*
    print_matrix(matrixTwo, 2);
    print_matrix(matrixThree, 3);
    print_matrix(matrixFour, 4);
    print_matrix(matrix, 3);
    */

    return -1;
}


double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
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
                //TODO has to start at top
                printf("x-axis %d, y-axis %d \n", j + 1, (i + y + 1) % (size));
                temporalMatrix[y][j] = matrix
                [(i + y + 1) % (size)]
                [(j + 1)];
            }
        }
        if (i % 2 == 0)
        {
            //number is even, so it prefix is +(positiv)
            solution = solution + matrix[0][i]
                                  * get_determinant(temporalMatrix, size - 1);
        } else
        {
            solution = solution + ((-1) * matrix[0][i]
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

/**
 * Retuns 1 if both numbers are Odd or both are even
 * @param a first number
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
 * clears matrix
 */
void clearMatrix(double temporalMatrix[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i <= MAX_SIZE; ++i)
    {
        for (int j = 0; j <= MAX_SIZE; ++j)
        {
            temporalMatrix[i][j] = 0.0;
        }
    }
}