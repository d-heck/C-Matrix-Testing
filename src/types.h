#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
 * @Author: David Heck (dheck@udel.edu)
 */

//Struct Def
struct vec3 {
	int x;
	int y;
	int z;

};

//Typedef
typedef struct vec3 Vector3t;

int smallest(const Vector3t* pts, int n); //Finds closest point to 0,0,0

#endif
