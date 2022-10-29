#include <stdio.h>
#include <stdlib.h>

struct BITMAP_header
{
    char name[2];
    unsigned int size;
    unsigned int image_offset;
};

struct DIB_header
{
    unsigned int header_size;
    unsigned short int width;
    unsigned int height;
    unsigned short int colorplanes;
    unsigned short int bitsperpixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int temp[4];
};

struct RGB
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

struct Image
{
    int height;
    int width;
    struct RGB **rgb;
};

struct Image readImage(FILE *fp, int height, int width)
{
    int i, bytestoread, numofrgb;
    struct Image pic;
    pic.rgb = (struct RGB **)malloc(height * sizeof(void *));
    pic.height = height;
    pic.width = width;
    bytestoread = ((24 * pic.width + 31) / 32) * 4;
    numofrgb = bytestoread / sizeof(struct RGB);
    for (i = height - 1; i >= 0; i--)
    {
        pic.rgb[i] = (struct RGB *)malloc(width * sizeof(struct RGB));
        fread(pic.rgb[i], 1, bytestoread, fp);
    }

    return pic;
}

void freeImage(struct Image pic)
{
    int i;
    for (i = pic.height - 1; i >= 0; i--)
    {
        free(pic.rgb[i]);
    }
    free(pic.rgb);
}

unsigned char greyscale(struct RGB rgb)
{
    return ((0.3 * rgb.red) + (0.6 * rgb.green) + (0.1 * rgb.blue)) / 3;
}

/* TEXT */
void imageToText(struct Image img)
{
    int i, j;
    unsigned char gs;
    char textpixel[] = {'@', '#', '%', '0', 'a', '-', ',', ' '};
    for (i = 0; i < img.height; i++)
    {
        for (j = 0; j < img.width; j++)
        {
            gs = greyscale(img.rgb[i][j]);
            printf("%c", textpixel[7 - gs / 32]);
        }
        printf("\n");
    }
}

void RGBImageToGreyscale(struct Image pic)
{
    int i, j;
    for (i = 0; i < pic.height; i++)
    {
        for (j = 0; j < pic.width; j++)
        {
            pic.rgb[i][j].red = pic.rgb[i][j].green = pic.rgb[i][j].blue = greyscale(pic.rgb[i][j]);
        }
    }
}

int createBWImage(struct BITMAP_header header, struct DIB_header dibheader, struct Image pic)
{
    int i;
    FILE *fpw = fopen("new.bmp", "w");
    if (fpw == NULL)
    {
        return 1;
    }

    RGBImageToGreyscale(pic);

    fwrite(header.name, 2, 1, fpw);
    fwrite(&header.size, 3 * sizeof(int), 1, fpw);
    fwrite(&dibheader, sizeof(struct DIB_header), 1, fpw);

    for (i = pic.height - 1; i >= 0; i--)
    {
        fwrite(pic.rgb[i], ((24 * pic.width + 31) / 32) * 4, 1, fpw);
    }
    fclose(fpw);
    return 0;
}

int openbmpfile(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    struct BITMAP_header header;
    struct DIB_header dibheader;

    fread(header.name, 2, 1, fp);
    fread(&header.size, 3 * sizeof(int), 1, fp);
    printf("First two characters:%c%c\n", header.name[0], header.name[1]);

    if ((header.name[0] != 'B') || (header.name[1] != 'M'))
    {
        fclose(fp);
        return 1;
    }

    printf("Size:%d\n", header.size);
    printf("Offset:%d\n", header.image_offset);

    fread(&dibheader, sizeof(struct DIB_header), 1, fp);
    printf("Header size:%d\n", dibheader.header_size);
    printf("Width:%d\n", dibheader.width);
    printf("Height:%d\n", dibheader.height);
    printf("Color planes:%d\n", dibheader.colorplanes);
    printf("Bits per pixel:%d\n", dibheader.bitsperpixel);
    printf("Compression:%d\n", dibheader.compression);
    printf("Image size:%d", dibheader.image_size);

    if ((dibheader.header_size != 40) || (dibheader.compression != 0) || (dibheader.bitsperpixel != 24))
    {
        fclose(fp);
        return 1;
    }

    fseek(fp, header.image_offset, SEEK_SET);
    struct Image image = readImage(fp, dibheader.height, dibheader.width);
    imageToText(image);
    createBWImage(header, dibheader, image);

    fclose(fp);
    freeImage(image);
    return 0;
}

int main()
{
    openbmpfile();
    return 0;
}
