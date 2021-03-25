#include <assert.h>
#include <printf.h>
#include <libc.h>

#define MAX 10

char *search(char *text, char c)
{
    char *newBuffer;
    int i = 0;
    while (text[i] != '\0' && text[i] != c)
    {
        i++;
    }
    strncpy(newBuffer, &text[i], MAX);
    return newBuffer;
}

void flupp(unsigned char byte)
{
    unsigned char mask;

    for (mask = 0x80u; mask > 0; mask >>= 1)
    {
        printf("%d", ((byte & mask) == 0) ? 0 : 1);
    }
    printf("\n");
}

/**
 *
 * @return -1 when done with the operations
 */
int main(int argc, char *argv[])
{
    char *pi;
    pi = argv[2];

    printf(0x80u);

    return -1;
}
