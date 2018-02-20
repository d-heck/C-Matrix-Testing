#include "utilities.h"
/*
 * @Author: David Heck (dheck@udel.edu)
 */
//2D Code Implementation
void** malloc2D(size_t rows, size_t cols, size_t sizeOfType) {
	void* block = malloc(sizeOfType * rows * cols);
	void** matrix = malloc(sizeof(void*) * rows);
	for (int row = 0; row < rows; ++row) {
		matrix[row] = block + cols * row * sizeOfType;
	}
	return matrix;
}

//Free's 2D Array
void free2D(void*** matrix) {
	free((*matrix)[0]);
	free((*matrix));
	matrix = NULL;
}

//3D Code Implementation
void*** malloc3D(size_t rows, size_t cols, size_t planes, size_t sizeOfType) {

	//Allocate Data
	void* block = malloc(sizeOfType * rows * cols * planes); // Modify for 3D size
	void** matrix = malloc(sizeof(void*) * rows * planes); // Modify for 3D size
	void*** matrix3D = malloc(sizeof(void**) * planes); //3D

	//Build lookup array
	int current;

	for (int plane = 0; plane < planes; ++plane) {
		for (int row = 0; row < rows; ++row) {
			current = plane * rows + row;
			matrix[current] = block + current * (cols * sizeOfType);
		}
		matrix3D[plane] = matrix + (plane * rows);
	}

	return matrix3D;
}

//Frees 3D array
void free3D(void**** matrix) {
	free((*matrix)[0][0]);
	free((*matrix)[0]);
	free((*matrix));
	matrix = NULL;
}

//Print 1D - Helper function, prints 1D arrays
void print1D(float array[], int size) {
	//Print 1D Array (Testing)
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			printf("%0.2f,", array[i]);
		} else {
			printf("%0.2f", array[i]); //Don't print comma on last element
		}
	}
	return;
}

//Print 2D - Helper function, prints 2D Arrays
void print2D(float* array[], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		print1D(array[i], columns);
		if (i != rows - 1) {
			printf(";");
		}
	}
}

//Print 3D - Prints 3D Arrays
void print3D(float** array[], int rows, int columns, int depth) {
	for (int i = 0; i < rows; i++) {
		print2D(array[i], columns, depth);
		if (i != depth - 1) {
			printf("\n");
		}
	}
}
