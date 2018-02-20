#include "utilities.h"
/*
 * @Author: David Heck (dheck@udel.edu)
 */
int main() {

	//Declare Variables
	int dim1 = 3; // Rows
	int dim2 = 3; // Columns
	int dim3 = 3; // Depth
	int w = 0; // used to convert 1D to 2D
	int v = 0; // used to convert 1D to 2D
	int x; // used to prevent user from entering too many numbers

	//User Input
	printf("Please enter Dimensionality of 3D Matrix (One Per Line): \n");
	fflush(stdout); //flush buffer, print was showing after input on my system.
	scanf("%d", &dim1);

	printf("Please enter Dimensionality of 3D Matrix (One Per Line): \n");
	fflush(stdout);
	scanf("%d", &dim2);

	printf("Please enter Dimensionality of 3D Matrix (One Per Line): \n");
	fflush(stdout);
	scanf("%d", &dim3);

	//Create 3D float matrix
	float*** matrix3D = malloc3D(dim1, dim2, dim3, sizeof(float));

	//Create 2D float matrix
	float** matrix2D = malloc2D(dim1, dim2 * dim3, sizeof(float));

	//Create 1D float array
	float* array1D = (float*) malloc(sizeof(float) * dim1 * dim2 * dim3);

	//Populate Array w/ User input
	printf("Please enter %d floating-point numbers separated by spaces: \n",
			(dim1 * dim2 * dim3));
	fflush(stdout);

	// Read user input, only reads the first (dim1 * dim2 * dim3) number of elements from input
	while (x < (dim1 * dim2 * dim3) && scanf("%f", &array1D[x++]) == 1);

	//1.0 1.5 1.0 1.5 2.0 2.5 2.0 2.5

	//Print 1D Array (Testing)
	//print1D(array1D, (dim1 * dim2 * dim3));

	//Copy 1D Array to 2D Matrix (In A Single For Loop);
	for (int i = 0; i < (dim1 * dim2 * dim3); i++) {
		//Change w and v values appropriately; i.e. navigate through 2D array
		if (i % (dim2 * dim3) == 0 && i != 0) {
			w += 1;
			v = 0;
		}
		//Assign 1D values to 2D location
		matrix2D[w][v] = array1D[i];
		v += 1;
	}

	//Print 2D Array
	print2D(matrix2D, dim1, (dim2 * dim3));
	printf("\n");

	//Copy 2D to 3D with memcpy
	memcpy(**matrix3D, *matrix2D, (sizeof(float) * dim1 * dim2 * dim3) );

	//Print 3D Array
	print3D(matrix3D, dim1, dim2, dim3);
	printf("\n");

	//Free Memory
	free3D(&matrix3D);
	free2D(&matrix2D);
	free(array1D);

	return 0;
}
