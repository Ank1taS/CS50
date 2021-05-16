#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Checks if number of arguments is not greater than 2 or 1
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Opens the required .raw file
    FILE *fp1 = fopen(argv[1], "r");

    // Checks if file is successfully opened or not
    if (fp1 == NULL)
    {
        printf("File opening error\n");
        fclose(fp1);
        return 1;
    }

    // Store buffer of JPEG
    unsigned char buffer[512];

    int  count = 0;
    FILE *fp2 = NULL;

    // Read 512 bytes of data from file fp1
    while (fread(buffer, 512, 1, fp1))
    {
        // Checks if first 4 bytes of headers are indicating JPEG or not
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(fp2);
            }

            char bufFileName[7];

            // Gives a filename serially
            sprintf(bufFileName, "%03d.jpg", count);

            // Opens the jpeg file
            fp2 = fopen(bufFileName, "w");

            // Check if file is successfully opened or not
            if (fp2 == NULL)
            {
                printf("File creation error\n");
                fclose(fp2);
                fclose(fp1);
                return 1;
            }
            count++;
        }

        // If file count is greater than 0 then write data to the JPEG file
        if (count > 0)
        {
            fwrite(buffer, 512, 1, fp2);
        }
    }

    // Closes the opened files
    fclose(fp2);
    fclose(fp1);

    return 0;
}