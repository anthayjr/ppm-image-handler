/*************************
 *Anthony Hay Jr.  
 *CPSC 2311 Summer 25
 *adhay@clemson.edu
 *************************/
#ifndef PPMUTIL_H
#define PPMUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Pixel
{
    unsigned char r, g, b;
}pixel_t;

typedef struct Header
{
    unsigned char type[3];
    unsigned int width;
    unsigned int height;
    unsigned int maxVal;
}header_t;

/**************************************
 * Reads the header from a PPM image file.
 * Parameters:
 *   FILE* fp - input file pointer opened in "rb" mode
 *   header_t* header - pointer to a header struct to fill in
 **************************************/
void readHeader(FILE* fp, header_t* header);

/**************************************
 * Allocates 1D memory for the image pixel data.
 * Parameters:
 *   pixel_t** data - pointer to a pixel_t pointer (your image array)
 *   unsigned int width - image width
 *   unsigned int height - image height
 **************************************/
void allocateImage1D(pixel_t** data, unsigned int width, unsigned int height);

/**************************************
 * Reads pixel data into a 1D array using fread.
 * Parameters:
 *   FILE* fp - input file pointer
 *   pixel_t* data - pointer to allocated 1D pixel array
 *   unsigned int totalPixels - total number of pixels (width * height)
 **************************************/
void readPixels1D(FILE* fp, pixel_t* data, unsigned int totalPixels);

/**************************************
 * Writes header and pixel data to output file using fwrite.
 * Parameters:
 *   FILE* fp - output file pointer
 *   header_t* header - pointer to header information
 *   pixel_t* data - pointer to 1D pixel data
 *   unsigned int totalPixels - number of pixels
 **************************************/
void writeImage1D(FILE* fp, header_t* header, pixel_t* data, unsigned int totalPixels);

/**************************************
 * Allocates 2D dynamic memory for pixels.
 * Parameters:
 *   unsigned int height - number of rows
 *   unsigned int width - number of columns
 * Returns:
 *   pixel_t** - a pointer to the 2D pixel array
 **************************************/
pixel_t** allocateImage2D(unsigned int height, unsigned int width);

/**************************************
 * Reads pixel data using nested fgetc() loops.
 * Parameters:
 *   FILE* fp - input file pointer
 *   pixel_t** image - 2D array of pixels
 *   unsigned int height - number of rows
 *   unsigned int width - number of columns
 **************************************/
void readPixels2D(FILE* fp, pixel_t** image,
                  unsigned int height, unsigned int width);

/**************************************
 * Writes header and pixel data using nested loops.
 * Parameters:
 *   FILE* fp - output file pointer
 *   header_t* header - pointer to header
 *   pixel_t** image - 2D array of pixels
 **************************************/
void writeImage2D(FILE* fp, header_t* header, pixel_t** image);

/**************************************
 * Frees the 2D image memory.
 * Parameters:
 *   pixel_t** image - pointer to 2D pixel array
 *   unsigned int height - number of rows
 **************************************/
void freeImage2D(pixel_t** image, unsigned int height);


#endif