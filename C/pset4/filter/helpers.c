#include "helpers.h"
#include <math.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            // average of red green and blue values
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // storing final average value in image
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int blue, red, green;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            // implimenting seoia algorithm
            red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            //to check the value in red
            if (red > 255)
            {
                red = 255;
            }
            //to check the value in green
            if (green > 255)
            {
                green = 255;
            }
            //to check the value in blue
            if (blue > 255)
            {
                blue = 255;
            }

            // final pixels
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    // algorithm to swap pixels
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < (width / 2); ++j)
        {
            // storing original pixel values in temporary image
            temp.rgbtRed = image[i][j].rgbtRed;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtBlue = image[i][j].rgbtBlue;


            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp.rgbtRed;
            image[i][width - j - 1].rgbtGreen = temp.rgbtGreen;
            image[i][width - j - 1].rgbtBlue = temp.rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blue, red, green, counter;

    // dynamic memory allocation for temporary new_image
    RGBTRIPLE **new_image = (RGBTRIPLE **) malloc(sizeof(RGBTRIPLE *) * height);

    for (int i = 0; i < height; i++)
    {
        new_image[i] = ((RGBTRIPLE *) malloc(sizeof(RGBTRIPLE) * width));
    }

    // calculating each surrounding pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed ;
            green = image[i][j].rgbtGreen ;
            blue = image[i][j].rgbtBlue ;
            counter = 1;

            if (i + 1 < height && j - 1 >= 0)
            {
                red +=  image[i + 1][j - 1].rgbtRed;
                green += image[i + 1][j - 1].rgbtGreen;
                blue += image[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if (j + 1 < width)
            {
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                red += image[i + 1][j + 1].rgbtRed;
                green += image[i + 1][j + 1].rgbtGreen;
                blue += image[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height)
            {
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;
                counter++;
            }
            if (j - 1 >= 0)
            {
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0)
            {
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0) && (j + 1 < width))
            {
                red += image[i - 1][j + 1].rgbtRed;
                green += image[i - 1][j + 1].rgbtGreen;
                blue += image[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0) && (j - 1 >= 0))
            {
                red += image[i - 1][j - 1].rgbtRed;
                green += image[i - 1][j - 1].rgbtGreen;
                blue += image[i - 1][j - 1].rgbtBlue;
                counter++;
            }

            // final pixels in new_image
            new_image[i][j].rgbtRed = round(red / (float)counter);
            new_image[i][j].rgbtGreen = round(green / (float)counter);
            new_image[i][j].rgbtBlue = round(blue / (float)counter);
        }
    }

    //copying new image to origilan image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
}
