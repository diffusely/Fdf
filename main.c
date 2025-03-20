#include "fdf.h"
#include <time.h>

 
typedef struct {
    char *data;
} String;


int main(void)
{
    String temp;
    temp.data = "sniper";
    printf("%s\n", temp.data);
    return (0);
}
