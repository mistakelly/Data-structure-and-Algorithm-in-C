#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**printing the arrays*/

void print_array(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        print("{}")
    }
}



int main(int argc, char *argv[])
{
    int array[] = {1,2,3,4,5};

    int size = sizeof(array) / sizeof(array[0]);


    print_array(array, size);


    return 0;
}