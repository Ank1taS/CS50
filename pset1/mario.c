// to create a pyramid

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    while (true)
    {
        height = get_int("Enter the height :\t");

// checking input        
        if (height >= 1 && height <= 8)
        {
            break;
        }
    }

//pyramid building
    for (int i = 0; i < height; ++i)
    {
//left pyramid's space 
        for (int spc = height - i - 1; spc > 0 ; --spc)
        {
            printf(" ");
        }
//left pyramid
        for (int j = 0; j <= i; ++j)
        {
            printf("#");            
        }
        printf("  ");
//right pyramid
        for (int j = 0; j <= i; ++j)
        {
            printf("#");  
        }
        printf("\n");    
    }
}