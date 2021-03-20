#include <assert.h>
#include <printf.h>
#include <libc.h>

#define ABORT { printf("Programmabbruch\n"); exit(-1); }


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

/**
 * Main Function that calls all necessary methods for praktikum 3
 * @return -1 when done with the operations
 */
int main()
{
    {
        assert(1 == 5 < 8 < 10);
        printf("1 == 5 < 8 < 10\n");

        assert(1 == 5 < 3 < 10);
        printf("1 == 5 < 3 < 10\n");
    }
    {
        printf("~0101 → 1010\n");
        printf("%s ->", byte_to_binary(5));
        printf("%s \n", byte_to_binary(~5));

        printf("0101 & 0011 → 0001\n");
        printf("%s \n", byte_to_binary(0x05 & 0x03));

        printf("0101 | 0011 → 0111\n");
        printf("%s \n", byte_to_binary(5 | 3));

        printf("0101 ^ 0011 → 0110\n");
        printf("%s \n", byte_to_binary(5 ^ 3));

        printf("das dritte bit von rechts löschen 111 zu 011\n");
        printf("%s \n", byte_to_binary(0x07 & 0xFB));
    }
    {
        printf("0111 << 2 = 1100\n");
        printf("%s \n", byte_to_binary(0x07 << 2));

        printf("0111 >> 2 = 0001\n");
        printf("%s \n", byte_to_binary(0x07 >> 2));
    }
    {
        printf("1 + 2 * 3 %% 4\n");
        printf("%d \n", 1 + 2 * 3 % 4);
    }
    {
        if (0)
            printf("if\n");
        else
            printf("else\n");
        switch (1 - 1)
        {
            case 1: printf("1\n"); break;
            case 2: printf("2\n"); break;
            case 3: printf("3\n"); break;
            default: printf("default\n"); break;
        }
    }
    {
        int count = 5;
        while (count >= 0)
        {
            printf("%d ", count--);
        }
        printf("\n");
        do
        {
            printf("%d ", count--);
        }while (count >= 0);
        printf("\n");
        for (int i = 0; i < 5; ++i)
        {
            printf("%d ", i);
        }
        printf("\n");

    }

    ABORT
    return -1;
}
