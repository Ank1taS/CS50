// Programe to say hello to the user

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name ? \t");
    printf("hello ! %s.\n", name);
}