#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

#define ULAM_ARRAY_LENGTH 1000
#define ULAM_MAX INT_MAX / 3 + 1


int ulam_multiples(int limit, int number);

int ulam_max(int a0);

int ulam_twins(int limit);

int ulam_multiples(int limit, int number);

void ulam(int aZero);

void printArray(int arrayToPrint[]);

void printAllUlamArray();

void calculateAllUlamsFrom(int a, int b);

void clearArray();

void printAllUlamsInIntervall(int a, int b);

int doesTheSeconArrayContainsTheFirstOneCompletely(int shouldBeContained[],
                                                   int arrayToCheck[]);


int ulamArray[ULAM_ARRAY_LENGTH];
int arrayForAllUlams[ULAM_ARRAY_LENGTH][ULAM_ARRAY_LENGTH];


/**
 * Main Function for Praktikum 1
 * @return d
 */
int main()
{
    assert(16 == ulam_max(5));
    printf("%d \n", ulam_max(5));
    assert(52 == ulam_max(7));
    printf("%d \n", ulam_max(7));

    assert(5 == ulam_twins(6));
    printf("%d \n", ulam_twins(6));
    assert(-1 == ulam_twins(5));
    printf("%d \n", ulam_twins(5));

    assert(5 == ulam_multiples(10, 2));
    printf("%d \n", ulam_multiples(10, 2));
    assert(972 == ulam_multiples(1000, 3));
    printf("%d \n", ulam_multiples(1000, 3));
    assert(-1 == ulam_multiples(108, 3));
    printf("%d \n", ulam_multiples(108, 3));
    assert(386 == ulam_multiples(391, 6));
    printf("%d \n", ulam_multiples(391, 6));


    /*
    printf("max Number in Ulam Number 5 = ");
    printf("%d \n", ulam_max(5));
    clearArray();
    printf("max Number in Ulam Number 7 = ");
    printf("%d \n", ulam_max(7));
    clearArray();
    */
    //printf("%d \n", ulam_twins(6));
    /*ulam(972);
    printArray(ulamArray);*/
    //printAllUlamsInIntervall(1, 6);

    //printf("%d ", arrayForAllUlams[999][0]);


    //calculateAllUlamsFrom(1, 10);
    //printAllUlamArray();
    //printf("%d ----", arrayForAllUlams[0][0]);
    //printf("%d ", ulam_max(IN));



    return -1;
}
/**
 * Calculates ulam multiples
 * @param limit limit
 * @param number number
 * @return the last multpiule
 */
int ulam_multiples(int limit, int number)
{
    int multiple_count = 1;
    int pred = ulam_max(limit);
    int curr = 0;

    do
    {
        if (multiple_count == number)
        {
            return limit;
        }
        limit = limit - 1;
        curr = ulam_max(limit);

        if (pred == curr)
        {
            multiple_count++;
        }
        else
        {
            multiple_count = 1;
            pred = curr;
        }
    } while (limit > 1);

    return -1;
}

/**
 * calculate twinst
 * @param limit limit
 * @return twins
 */
int ulam_twins(int limit)
{
    int maxA0;
    int maxA0Plus1;
    int ulamLowerTwin = -1;

    for (int i = 1; i < limit; ++i)
    {
        maxA0 = ulam_max(i);
        clearArray();
        maxA0Plus1 = ulam_max(i + 1);
        clearArray();
        if (maxA0 == maxA0Plus1)
        {
            ulamLowerTwin = i;
        } else
        {
            ulamLowerTwin = -1;
        }
    }
    return ulamLowerTwin;
}

/**
 *  returns Max Number in ulam Array
 * @param a0 starting number
 * @return Int max Number in calculated array or -1 for a0 <= 0
 */
int ulam_max(int a0)
{
    if (a0 <= 0)
    {
        return -1;
    }
    ulam(a0);
    int maxNumber = 0;
    for (int i = 0; i <= ULAM_ARRAY_LENGTH; ++i)
    {
        if (maxNumber < ulamArray[i])
        {
            maxNumber = ulamArray[i];
        }
    }
    clearArray();
    return maxNumber;
}


/**
 * Calculates the Collatz-Problem
 * @param aZero the starting Number
 */
void ulam(int aZero)
{
    if (aZero > 0)
    {
        int indice = 1;
        ulamArray[0] = aZero;
        int lastNumber = aZero;
        while (lastNumber != 1)
        {

            if (lastNumber % 2 == 0)
            {
                //number is even
                ulamArray[indice] = lastNumber * 1 / 2;

            } else if (lastNumber % 2 != 0)
            {
                //number has to be odd
                if (lastNumber >= ULAM_MAX)
                {
                    printf("Fehler, überlauf bei INT");
                    exit(-1);
                } else
                {
                    ulamArray[indice] = lastNumber * 3 + 1;
                }
            }
            lastNumber = ulamArray[indice];
            indice++;


        }
    }
}

/**
 * Calculates all ulams from a to b
 * @param a start
 * @param b ending
 */
void calculateAllUlamsFrom(int a, int b)
{
    for (int i = 1; i <= b - a + 1; ++i)
    {
        ulam(i);
        for (int j = 0; j < ULAM_ARRAY_LENGTH; ++j)
        {
            arrayForAllUlams[i - 1][j] = ulamArray[j];
        }
        clearArray();
    }
}

/**
 * Prints everythin in allUlamArray
 */
void printAllUlamArray()
{
    for (int i = 0; i <= ULAM_ARRAY_LENGTH; ++i)
    {
        for (int j = 0; j < ULAM_ARRAY_LENGTH; ++j)
        {
            if (arrayForAllUlams[i][j] != 0)
            {
                //dont print any zero´s
                printf("%d ", arrayForAllUlams[i][j]);
            }
        }
        if (arrayForAllUlams[i][0] != 0)
        {
            //I dont want to print an empty line after each row, just then the row is empty
            printf("\n");
        }
    }
    printf("\n");
}

/**
 * prints all in intervall
 * @param a start
 * @param b ending
 */
void printAllUlamsInIntervall(int a, int b)
{
    if (a <= b)
    {
        for (int i = a; i <= b; ++i)
        {
            ulam(i);
            printArray(ulamArray);
            clearArray();
        }
    }
}

/**
 * prints array
 * @param arrayToPrint .
 */
void printArray(int arrayToPrint[])
{
    for (int i = 0; i <= ULAM_ARRAY_LENGTH; ++i)
    {
        if (arrayToPrint[i] != 0)
        {
            printf("%d ", arrayToPrint[i]);
        }
    }
    printf("\n");
}
/**
 * clear array
 */
void clearArray()
{
    for (int i = 0; i <= ULAM_ARRAY_LENGTH; ++i)
    {
        ulamArray[i] = 0;
    }
}

