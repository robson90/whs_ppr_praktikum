#include <assert.h>
#include <printf.h>
#include <libc.h>
#include <stdbool.h>

char *c[] = {
        "ENTER",
        "NEW",
        "POINT",
        "FIRST"
};

char **cp[] = {c + 3, c + 2, c + 1, c};
char ***cpp = cp;

struct POINT
{
    int x;
    int y;
};
struct POINT point;
struct POINT *p_point;

bool str_prefix(char *string, char *prefix)
{
    int i = 0;
    bool isPrefix = true;
    while (*(string + i) != NULL && *(prefix + i) != NULL) {
        if(*(string + i) != *(prefix + i)) {
            isPrefix = false;
        }
        i+=1;
    }
    return isPrefix;
}

/**
 * Main Function that calls all necessary methods for praktikum 3
 * @return -1 when done with the operations
 */
int main()
{
    printf("%s", **++cpp);
    printf("%s ", *--*++cpp + 3);
    printf("%s", *cpp[-2] + 3);
    printf("%s\n", cpp[-1][-1] + 1);

    //printf("true %d \n", str_prefix("2345", "23"));
    //printf("true %d \n", str_prefix("2345", "2345"));
    //printf("false %d \n", str_prefix("2345", "34"));

    //str_prefix("2345", "23");
    //str_prefix("2345", "2345");
    //str_prefix("2345", "34");

    int i = 0;
    printf("%d", i);
    printf("%d", '-');

    return (EXIT_SUCCESS);
}