#include <assert.h>
#include <printf.h>
#include <libc.h>



/**
 *
 * @return -1 when done with the operations
 */
int main(int argc, char *argv[])
{
    printf("There are %d Arguments \n", argc);
    if (argc > 0) {
        for (int i = 0; i < argc; ++i)
        {
            printf("Argument at postion %d is '%s' ---\n", i, argv[i]);
        }
    }

    return -1;
}
