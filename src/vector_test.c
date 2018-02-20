#include "types.h"
/*
 * @Author: David Heck (dheck@udel.edu)
 */

int main() {

	//Declare Variables
	int N;
	int x;
	int y;
	int z;
	int result;

	//User Input
	printf("Please enter a number of elements: \n");
	fflush(stdout); //flush buffer, print was showing after input on my system.
	scanf("%d", &N);

	//Create an array of Vector3t of size N and call it points
	Vector3t* points = (int*)malloc(sizeof(int) * N);

	//Read in triples of int from the user to populate the entire array
	for (int i = 0; i < N; i++) {
		printf("Please enter integer triples to populate array (comma separated): \n");
		fflush(stdout);
		scanf("%d,%d,%d", &x, &y, &z);

		points[i].x = x;
		points[i].y = y;
		points[i].z = z;
	}

	//Calls the smallest function and stores the value in result
	result = smallest(points, N);

	//Prints closest point to origin
	printf("The closest point to origin is: ( %d, %d , %d ) \n", points[result].x,
			points[result].y, points[result].z);
	fflush(stdout);


	//Delete Array
	free(points);
	return 0;
}

//Returns the index of the point that is closes to point (0,0,0)
int smallest(const Vector3t* pts, int n) {
	//Variables used to store distance
	int tempCurr = 0;
	int tempSmall = 0;

	//Stores index;
	int closestIndex = 0;

	//Initialize tempCurr and tempSmall
	tempCurr = abs(pts[0].x) + abs(pts[0].y) + abs(pts[0].z); //Compare the absolute value sum of each vector
	tempSmall = tempCurr;

	//Check if there exists a closer index
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			tempCurr = abs(pts[i].x) + abs(pts[i].y) + abs(pts[i].z); //Compare the absolute value sum of each vector
			if (tempCurr < tempSmall) {
				tempSmall = tempCurr;
				closestIndex = i;
			}
		}
	}

	//Return the vector index with the smallest absolute value sum
	return closestIndex;
}
