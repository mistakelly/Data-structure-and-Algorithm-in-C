#include <stdio.h>
#include <stdlib.h>


char* func_string(char *string)
{
    string[0] = 'o';
    return string;

}


int main(int argc, char *argv[])
{

    char result[10]  = "kelly";
    char* receive_result =  func_string(result);

    printf("%s\n", receive_result);

    return 0;
}