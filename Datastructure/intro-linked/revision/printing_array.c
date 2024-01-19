#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    int arrray = {1,2,3,4,5};

    int size = sizeof(arrray) / sizeof(arrray[0]);


    print_array(array, size);


    return 0;
}