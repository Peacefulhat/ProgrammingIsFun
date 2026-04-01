#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef unsigned int uint32;

typedef struct
{
    uint32 R;
    uint32 G;
    uint32 B;
} ppm_colors;

// currenlty Colors are generated randomly and the data is thrown.
typedef struct
{
    const char* MagicNumber;
    uint32 Width;
    uint32 Height;
    uint32 ColorRange;
    ppm_colors Colors;
}ppm;


void WriteRandomRGB(const char* FilePath, uint32 Width, uint32 Height, uint32 ColorRange)
{
    FILE* Fp = fopen(FilePath, "w");
    if (!Fp) {
        printf("Error opening file.\n");
        return;
    }

    ppm Img;
    Img.MagicNumber = "P3";
    Img.Width = Width;
    Img.Height = Height;
    Img.ColorRange = ColorRange;

    fprintf(Fp, "%s\n", Img.MagicNumber);
    fprintf(Fp, "%u %u\n", Img.Width, Img.Height);
    fprintf(Fp, "%u\n",Img.ColorRange);


    for (uint32 i = 0; i < Img.Height; i++)
    {
        for (uint32 j = 0; j < Img.Width; j++)
        {
            // Black and white Squares
            /* Img.Colors.R = (j & i)%256; //
               Img.Colors.G =     (Img.Colors.R &( (j & i)))%256;
               Img.Colors.B =     (Img.Colors.R & Img.Colors.G &(( (j & i))))%256;
            */
            // Squers and tirangles
                /*
                Img.Colors.R = (j & i)%256;
                Img.Colors.G =     (Img.Colors.R + ( (j + i)))%256;
                Img.Colors.B =     (Img.Colors.R + Img.Colors.G - (( (j + i))))%256;
                */
                Img.Colors.R = (j & i)%256;
                Img.Colors.G =     (Img.Colors.R + ( (j + i)))%256;
                Img.Colors.B =     (Img.Colors.R + Img.Colors.G - (( (j + i))))%256;

                fprintf(Fp, "%u %u %u ", Img.Colors.R, Img.Colors.G, Img.Colors.B);
        }
        fprintf(Fp, "\n");
    }

    fclose(Fp);
}

int main()
{
    srand(time(NULL));
    WriteRandomRGB("test.ppm", 1920, 1080, 255);
    return 0;
}
