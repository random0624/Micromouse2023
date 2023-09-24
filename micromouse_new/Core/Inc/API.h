/*
 * API.h
 *
 *  Created on: Aug 26, 2023
 *      Author: ransomliu
 */

#ifndef INC_API_H_
#define INC_API_H_
#include "main.h"
#include <string>


int orientation (int, char);

void command(const string&, std::string&);

int mazeWidth(void);

int mazeHeight(void);

bool wallFront(void);

bool wallRight(void);

bool wallLeft(void);

void moveForward(void);

void turnRight(void);

void turnLeft(void);

void setWall(int, int, std::string);

void clearWall(int, int, std::string);

void setColor(int, int, std::string);

void clearColor(int, int);

void clearAllColor(void);

void setText(int, int, std::string);

void clearText(int, int);

void clearAllText(void);

bool wasReset(void);

void ackReset(void);

void log(std::string);

int main(void);

#endif /* INC_API_H_ */
