# PPM Image Handler

## 📌 Overview
A C-based program that reads, modifies, and writes PPM (Portable PixMap) image files using dynamic memory allocation and file I/O.

## 🛠️ Features
- Read and write binary P6 PPM files
- Support for both 1D and 2D dynamic memory allocation
- Manual manipulation of pixel data
- Efficient memory management with `fread` and `fwrite`

## 📂 Files
- `ppmDriver.c`: Handles user interaction and drives program logic
- `ppmUtil.c`: Core functions for reading/writing/manipulating PPM data
- `ppmUtil.h`: Function prototypes and struct definitions

## 📸 Sample Output
> Add a screenshot if possible — even a CLI output or a hex view of pixel data

## 🚀 How to Run
```bash
make
./ppmDriver input.ppm output.ppm
