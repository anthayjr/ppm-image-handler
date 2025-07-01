/*************************
 *Anthony Hay Jr.  
 *CPSC 2311 Summer 25
 *adhay@clemson.edu
 *************************/
#include "ppmUtil.h"

/**************************************
 * Reads header from the input PPM file.
 * Use fscanf to extract the magic number, width, height, and maxVal.
 * Consumes the whitespace after maxVal.
 **************************************/

void readHeader(FILE* fp, header_t* header)
{
    // Read the magic number (e.g., "P6")
    fscanf(fp, "%s", header->type);

    // Read width and height
    fscanf(fp, "%u %u", &header->width, &header->height);

    // Read maxVal (typically 255)
    fscanf(fp, "%u", &header->maxVal);

    // Consume the whitespace (usually a newline) after maxVal
    fgetc(fp);
}

/**************************************
 * Allocates a 1D array of pixels based on width * height.
 * Stores the memory address in the provided pointer.
 **************************************/

void allocateImage1D(pixel_t** data, unsigned int width, unsigned int height)
{
    // Allocate memory for the full image as a 1D array
    *data = malloc(sizeof(pixel_t) * width * height);
}

/**************************************
 * Reads pixel data using fread into the 1D array.
 **************************************/

void readPixels1D(FILE* fp, pixel_t* data, unsigned int totalPixels)
{
    // Use fread to load all pixels in one call
    fread(data, sizeof(pixel_t), totalPixels, fp);
}

/**************************************
 * Writes the header and pixel data using fwrite.
 **************************************/

void writeImage1D(FILE* fp, header_t* header, pixel_t* data, unsigned int totalPixels)
{
    // Write the header in proper PPM format
    fprintf(fp, "%s\n%u %u\n%u\n",
            header->type, header->width, header->height, header->maxVal);

    // Write the pixel data in binary using fwrite
    fwrite(data, sizeof(pixel_t), totalPixels, fp);
}
pixel_t** allocateImage2D(unsigned int height, unsigned int width)
{
    // Allocate an array of row pointers
    pixel_t** image = malloc(height * sizeof(pixel_t*));

    // Allocate each row
    for (unsigned int i = 0; i < height; ++i)
    {
        image[i] = malloc(width * sizeof(pixel_t));
    }

    return image;
}

void readPixels2D(FILE* fp, pixel_t** image,
                  unsigned int height, unsigned int width)
{
    for (unsigned int i = 0; i < height; ++i)
    {
        for (unsigned int j = 0; j < width; ++j)
        {
            // Read red, green, blue using fgetc()
            image[i][j].r = fgetc(fp);
            image[i][j].g = fgetc(fp);
            image[i][j].b = fgetc(fp);
        }
    }
}

void writeImage2D(FILE* fp, header_t* header, pixel_t** image)
{
    // Write the header
    fprintf(fp, "%s\n%u %u\n%u\n",
            header->type, header->width, header->height, header->maxVal);

    for (unsigned int i = 0; i < header->height; ++i)
    {
        for (unsigned int j = 0; j < header->width; ++j)
        {
            fputc(image[i][j].r, fp);
            fputc(image[i][j].g, fp);
            fputc(image[i][j].b, fp);
        }
    }
}

void freeImage2D(pixel_t** image, unsigned int height)
{
    for (unsigned int i = 0; i < height; ++i)
    {
        free(image[i]);
    }

    free(image);
}
