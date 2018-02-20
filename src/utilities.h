#ifndef __UTILITIES_H__
#define __UTILITIES_H__
/*
 * @Author: David Heck (dheck@udel.edu)
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//2D Def.
void** malloc2D(size_t rows, size_t cols, size_t sizeOfType);
void free2D(void*** matrix);

//3D Def.
void*** malloc3D(size_t rows, size_t cols, size_t planes, size_t sizeOfType);
void free3D(void**** matrix);

//print functions
void print1D(float array[], int size);

void print2D(float* array[], int rows, int columns);

void print3D(float** array[], int rows, int colums, int depth);

#endif
