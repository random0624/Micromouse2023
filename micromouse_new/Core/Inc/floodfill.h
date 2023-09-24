/*
 * floodfill.h
 *
 *  Created on: Aug 26, 2023
 *      Author: ransomliu
 */

#ifndef INC_FLOODFILL_H_
#define INC_FLOODFILL_H_

#include "main.h"

int orientation(int, char);

void updateCoordinatates(int, int, int);

void updateWalls(int, int, int, bool, bool, bool);

bool isAccessible(int, int, int, int);

#endif /* INC_FLOODFILL_H_ */
