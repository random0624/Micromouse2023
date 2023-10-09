/*
 * floodfill.c
 *
 *  Created on: Aug 26, 2023
 *      Author: ransomliu
 */
//jesus wants this change to show up to universal
//i want ransom in my bed under the sheets making your brother
//me and your mother making your brother under the sheets
#include "API.h"
#include "floodfill.h"
#include "main.h"

int x = 0;
int y = 0;
int orient = 0;
int state = 0;

bool shortPath = false;

int orientation(int &orient, char turning) {
    if (turning == 'L') {
        orient -= 1;
        if (orient == -1) {
            orient = 3;
        }
    } else if (turning == 'R') {
        orient += 1;
        if (orient == 4) {
            orient = 0;
        }
    } else if (turning == 'B') {
        if (orient == 0) {
            orient = 2;
        } else if (orient == 1) {
            orient = 3;
        } else if (orient == 2) {
            orient = 0;
        } else if (orient == 3) {
            orient = 1;
        }
    }
    return orient;
}

void updateCoordinates(int &x, int &y, int orient) {
    if (orient == 0) {
        y += 1;
    } else if (orient == 1) {
        x += 1;
    } else if (orient == 2) {
        y -= 1;
    } else if (orient == 3) {
        x -= 1;
    }
}

void updateWalls(int x, int y, int orient, bool L, bool R, bool F) {
    // Implement the updateWalls logic for C++
    // This function updates the cell values based on wall information
}

bool isAccessible(int x, int y, int x1, int y1) {
    // Implement the isAccessible logic for C++
    // This function checks if a cell is accessible based on the current orientation and cell values
    return false;
}

// Define other necessary functions similarly

int main() {
    // Initialize your STM32CubeIDE setup here
    // Initialize sensors and other hardware

    while (true) {
        // Replace the API calls with your STM32CubeIDE equivalents
        // Update walls using sensors
        //boolean L = /* Read left sensor */;
        //boolean R = /* Read right sensor */;
        //boolean F = /* Read front sensor */;

        updateWalls(x, y, orient, L, R, F);

        if (flood[y][x] != 0) {
            if (state == 0) {
                // Implement your logic here for state 0
            } else if (state == 1) {
                // Implement your logic here for state 1
            }
            // Implement other state cases similarly

            if (shortPath) {
                char direction = toMove2(flood2, x, y, xprev, yprev, orient);
                if (direction == 'L') {
                    // Turn left
                } else if (direction == 'R') {
                    // Turn right
                } else if (direction == 'B') {
                    // Turn back
                }
                // Move forward
                updateCoordinates(x, y, orient);
            } else {
                char direction = toMove(flood, x, y, xprev, yprev, orient);
                if (direction == 'L') {
                    // Turn left
                } else if (direction == 'R') {
                    // Turn right
                } else if (direction == 'B') {
                    // Turn back
                }
                // Move forward
                updateCoordinates(x, y, orient);
            }
        } else {
            // Implement your logic for flood value of 0
        }

        // Delay or control loop frequency as needed
    }

    return 0;
}





