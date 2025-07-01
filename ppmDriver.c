/*************************
 *Anthony Hay Jr.  
 *CPSC 2311 Summer 25
 *adhay@clemson.edu
 *************************/
#include "ppmUtil.h"
int main(void)
{
    FILE* inFile = fopen("input.ppm", "rb");
    FILE* outFile1 = fopen("output1.ppm", "wb");
    if (!inFile || !outFile1) {
        printf("Error opening file(s).\n");
        return 1;
    }
    // Read header
    header_t header;
    readHeader(inFile, &header);
    // Allocate 1D memory
    pixel_t* imageData = NULL;
    allocateImage1D(&imageData, header.width, header.height);
    // Read pixel data
    unsigned int totalPixels = header.width * header.height;
    readPixels1D(inFile, imageData, totalPixels);
    // Write pixel data to output1
    writeImage1D(outFile1, &header, imageData, totalPixels);

    // Clean up 
    fclose(outFile1);
    free(imageData);
    rewind(inFile);

    FILE* outFile2 = fopen("output2.ppm", "wb");
    if (!outFile2) {
        printf("Error opening output2.ppm\n");
        fclose(inFile);
        return 1;
    }
    // Re-read header
    readHeader(inFile, &header);
    // Allocate and process 2D image
    pixel_t** image2D = allocateImage2D(header.height, header.width);
    readPixels2D(inFile, image2D, header.height, header.width);
    writeImage2D(outFile2, &header, image2D);

    // Clean up
    freeImage2D(image2D, header.height);
    fclose(outFile2);
    fclose(inFile);
    return 0;
}