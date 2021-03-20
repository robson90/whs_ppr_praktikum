#include <assert.h>
#include <printf.h>
#include <libc.h>

enum year
{
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul,
    Aug, Sep, Oct, Nov, Dec
};

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

void p_swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

char *msg_1 = "Fehlermeldung 1";
char *msg_2 = "Fehlermeldung 2";

char *get_msg(int no)
{
    char *msg;
    switch (no)
    {
        case 1 :
            msg = msg_1;
            break;
        case 2 :
            msg = msg_2;
    }
    return msg;
}

void xxx(char *s1, char *s2)
{
    while (*s1 != '\0')
    {
        printf("%c *s1 != '\\0'\n", s1);
        s1++;
    }
    while (*s2 != '\0')
    {
        printf("%c *s2 != '\\0'\n", s2);
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

#define FLIP(n, k) (n ^ (0XFF << k))

int flipBits2(int n, int k)
{
    int mask = (0XFF << k);
    return n ^ mask;
}

char *string_replace(char *s1, char *s2, char *s3);

int isPatternComplete(char *s1, char *s2, int i);




enum bool
{
    false = 0, true = 1
};

typedef enum bool (*COND)(int);

int *delete(int *vector, int *size, COND cond);

enum bool odd(int value);

enum bool even(int value);

/**
 * Main Function that calls all necessary methods for praktikum 3
 * @return -1 when done with the operations
 */
int main()
{
    {
        char a = 'a';
        printf("%x Adress \n", &a);
        printf("%c Content\n", a);

        //Dem Pointer die Adresse des Werts geben
        char *p1 = &a;
        printf("%x Adress \n", &p1);
        printf("%c Content\n", *p1);
    }
    {
        int a = 5;
        int b = 10;
        printf("%d - %d\n", a, b);
        p_swap(&a, &b);
        printf("%d - %d\n", a, b);
    }
    {
        printf("%x Adress \n", get_msg(1));
        int i = 0;
        char *returnedChar = get_msg(2);
        while (returnedChar[i] != '\0')
        {
            printf("%c", returnedChar[i]);
            i++;
        }
        printf("\n");
    }
    {
        for (int i = Jan; i <= Dec; i++)
            printf("%d ", i);
        printf("\n");
    }
    {
        int v1[5] = {0};
        int v2[5] = {1};
        for (int i = 0; i < 5; i++)
            printf("v1 %d - v2 %d\n", v1[i], v2[i]);
    }
    {
        char wert[0];
        if (wert[0] == '\0')
        {
            printf("inside if %s \n", wert[0]);
        }
    }
    {
        /*char s1 = "12345";
        char s2 = "54321";
        xxx(s1, s2);*/
    }
    {
        printf("%s \n", byte_to_binary(0xFF));
        printf("%s \n", byte_to_binary(FLIP(0XFF, 2)));
        printf("%s \n", byte_to_binary(FLIP(0X00, 6)));
    }
    {
        printf("%d sfd\n", strlen("Test"));
    }
    {
        assert("CD"[2] == '\0');
        assert(isPatternComplete("ABCDEF", "CD", 2) == 1);
        assert(isPatternComplete("ABCDEF", "CD", 1) == 0);
        assert(isPatternComplete("ABCDEF", "CDF", 2) == 0);
        assert(isPatternComplete("ABCDEF", "MD", 2) == 0);
    }
    {
        printf("%s = ABXYZEF ? \n", string_replace("ABCDEF", "CD", "XYZ"));
        assert(strcmp(string_replace("ABCDEF", "CD", "XYZ"), "ABXYZEF") == 0);
        printf("%s = ABXEF ? \n", string_replace("ABCDEF", "CD", "X"));
        assert(strcmp(string_replace("ABCDEF", "CD", "X"), "ABXEF") == 0);
        printf("%s = ABCDEF ? \n", string_replace("ABCDEF", "MD", "XYZ"));
        assert(strcmp(string_replace("ABCDEF", "MD", "XYZ"), "ABCDEF") == 0);
    }
    {
        /*assert(odd(3) == true);
        assert(odd(-1) == true);
        assert(odd(0) == false);
        assert(odd(2) == false);

        assert(even(3) == false);
        assert(even(-1) == false);
        assert(even(0) == true);
        assert(even(2) == true);*/
    }
    {
        /*
        int givenVector[] = {1, 2, 3, 4};
        delete(givenVector, 4, even);
        int resultVector1[] = {1, 0, 3, 0};
        int i = 0;
        while (i < 4) {
            assert(givenVector[i] == resultVector1[i]);
            i++;
        }
        delete(givenVector, 4, odd);
        int resultVector2[] = {0, 0, 0, 0};
        i = 0;
        while (i < 4) {
            assert(givenVector[i] == resultVector2[i]);
            i++;
        }*/
    }
    {
        int i = 1;
        //true and false
        if (i) {
            printf("it is true(everything else than 0)");
        } else {
            printf("i is not true");
        }
    }





    return -1;
}

int *delete(int *vector, int *size, COND cond)
{
    int i = 0;
    while (i < size) {
        if (cond(vector[i]) == true) {
            vector[i] = 0;
        }
        i++;
    }
    return 1;
}


enum bool odd(int value)
{
    printf("odd is called ! \n");
    if (value < 0)
    {
        value = abs(value);
    }
    return value % 2 == 1 ? true : false;
}

enum bool even(int value)
{
    printf("even is called ! \n");
    if (value < 0)
    {
        value = abs(value);
    }
    return value % 2 == 0 ? true : false;
}


/**
 *
 * @param s1 where the Characters are replaces
 * @param s2 pattern to search for
 * @param s3 replacement for pattern
 * @return
 */
char *string_replace(char *s1, char *s2, char *s3)
{
    /*printf("%d s1\n", strlen(s1));
    printf("%d s2\n", strlen(s2));
    printf("%d s3\n", strlen(s3));
    printf("%d max length\n", strlen(s1) - strlen(s2) + strlen(s3));*/
    int maxLength = strlen(s1) - strlen(s2) + strlen(s3);
    char resultString[maxLength];

    int sourceIndex = 0;
    int patternIndex = 0;
    int resultIndex = 0;
    while (s1[sourceIndex] != '\0')
    {
        if (s1[sourceIndex] != s2[patternIndex])
        {
            resultString[resultIndex] = s1[sourceIndex];
            sourceIndex++;
            resultIndex++;
        } else if (s1[sourceIndex] == s2[patternIndex])
        {
            if (isPatternComplete(s1, s2, sourceIndex))
            {
                while (s3[patternIndex] != '\0')
                {
                    resultString[resultIndex] = s3[patternIndex];
                    resultIndex++;
                    patternIndex++;
                }
                sourceIndex += (int) strlen(s2);
            } else
            {
                sourceIndex++;
            }
        }
    }
    return resultString;
}

int isPatternComplete(char *s1, char *s2, int i)
{
    int bool = 1;
    int patternIndex = 0;
    while (s2[patternIndex] != '\0' && bool == 1)
    {
        if (s1[i] != s2[patternIndex])
        {
            bool = 0;
        }
        i++;
        patternIndex++;
    }
    return bool;
}