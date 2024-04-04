#include <iostream>
#include <algorithm>

class Rectangle {
private:
    int x, y, width, height;

public:
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void resize(int newWidth, int newHeight) {
        width = newWidth;
        height = newHeight;
    }

    Rectangle getSmallestContainingRectangle(const Rectangle& otherRect) const {
        int minX = std::min(x, otherRect.x);
        int minY = std::min(y, otherRect.y);
        int maxX = std::max(x + width, otherRect.x + otherRect.width);
        int maxY = std::max(y + height, otherRect.y + otherRect.height);
        int newWidth = maxX - minX;
        int newHeight = maxY - minY;
        return Rectangle(minX, minY, newWidth, newHeight);
    }

    Rectangle getIntersectionRectangle(const Rectangle& otherRect) const {
        int minX = std::max(x, otherRect.x);
        int minY = std::max(y, otherRect.y);
        int maxX = std::min(x + width, otherRect.x + otherRect.width);
        int maxY = std::min(y + height, otherRect.y + otherRect.height);
        int newWidth = maxX - minX;
        int newHeight = maxY - minY;
        if (newWidth <= 0 || newHeight <= 0)
            return Rectangle(0, 0, 0, 0);  // No intersection
        return Rectangle(minX, minY, newWidth, newHeight);
    }

    void print() const {
        std::cout << "Rectangle: (" << x << ", " << y << "), width: " << width << ", height: " << height << std::endl;
    }
};

int main() {
    Rectangle rect1(1, 1, 4, 3);
    Rectangle rect2(3, 2, 3, 2);

    std::cout << "Initial Rectangle 1: ";
    rect1.print();
    std::cout << "Initial Rectangle 2: ";
    rect2.print();

    rect1.move(2, 2);
    rect2.resize(5, 4);

    std::cout << "Rectangle 1 after moving: ";
    rect1.print();
    std::cout << "Rectangle 2 after resizing: ";
    rect2.print();

    Rectangle smallestContainingRect = rect1.getSmallestContainingRectangle(rect2);
    Rectangle intersectionRect = rect1.getIntersectionRectangle(rect2);

    std::cout << "Smallest containing rectangle: ";
    smallestContainingRect.print();
    std::cout << "Intersection rectangle: ";
    intersectionRect.print();

    return 0;
}
