#pragma once

struct Point {
    int x;
    int y;
};

struct Rectangle {
    int width;
    int height;
};

bool isInRectangle(Point &point, Rectangle &rectangle) {
    if (point.x >= 0 && point.y >= 0 && point.x <= rectangle.width && point.y <= rectangle.height) {
        return true;
    }
    return false;
}