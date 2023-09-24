/*
 * API.cpp
 *
 *  Created on: Aug 26, 2023
 *      Author: ransomliu
 */


#include <iostream>  // For input and output
#include <stdexcept> // For exceptions
#include "API.h"

int orient = 0;

int orientation(int orient, char turning) {
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

std::pair<int, int> updateCoordinates(int x, int y, int orient) {
    if (orient == 0) {
        y += 1;
    } else if (orient == 1) {
        x += 1;
    } else if (orient == 2) {
        y -= 1;
    } else if (orient == 3) {
        x -= 1;
    }

    return std::make_pair(x, y);
}

class MouseCrashedError : public std::exception {
public:
    const char* what() const noexcept {
        return "Mouse Crashed Error";
    }
};

void command(const std::string& args, std::string& response) {
    std::string line = args + "\n";
    // Implement sending line to output
    // Implement receiving response from input
}

int mazeWidth() {
    std::string response;
    command("mazeWidth", response);
    return std::stoi(response);
}

int mazeHeight() {
    std::string response;
    command("mazeHeight", response);
    return std::stoi(response);
}

bool wallFront() {
    std::string response;
    command("wallFront", response);
    return response == "true";
}

bool wallRight() {
    std::string response;
    command("wallRight", response);
    return response == "true";
}

bool wallLeft() {
    std::string response;
    command("wallLeft", response);
    return response == "true";
}

void moveForward() {
    std::string response;
    command("moveForward", response);
    if (response == "crash") {
        throw MouseCrashedError();
    }
}

void turnRight() {
    std::string response;
    command("turnRight", response);
}

void turnLeft() {
    std::string response;
    command("turnLeft", response);
}

void setWall(int x, int y, const std::string& direction) {
    command("setWall " + std::to_string(x) + " " + std::to_string(y) + " " + direction, std::string());
}

void clearWall(int x, int y, const std::string& direction) {
    command("clearWall " + std::to_string(x) + " " + std::to_string(y) + " " + direction, std::string());
}

void setColor(int x, int y, const std::string& color) {
    command("setColor " + std::to_string(x) + " " + std::to_string(y) + " " + color, std::string());
}

void clearColor(int x, int y) {
    command("clearColor " + std::to_string(x) + " " + std::to_string(y), std::string());
}

void clearAllColor() {
    command("clearAllColor", std::string());
}

void setText(int x, int y, const std::string& text) {
    command("setText " + std::to_string(x) + " " + std::to_string(y) + " " + text, std::string());
}

void clearText(int x, int y) {
    command("clearText " + std::to_string(x) + " " + std::to_string(y), std::string());
}

void clearAllText() {
    command("clearAllText", std::string());
}

bool wasReset() {
    std::string response;
    command("wasReset", response);
    return response == "true";
}

void ackReset() {
    std::string response;
    command("ackReset", response);
}

void log(const std::string& string) {
    // Implement logging the string
}

int main() {
    // Your STM32CubeIDE setup and main logic here
    return 0;
}



