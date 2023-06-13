#include <iostream>
using namespace std;

class Shape {
protected:
    double length;
    double width;

public:
    Shape(double l, double w) : length(l), width(w) {}

    double getLength()  {
        return length;
    }

    double getWidth() {
        return width;
    }

    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }

    double area() {
        return length * width;
    }
};

class TwoD_Shape : public Shape {
public:
    TwoD_Shape(double l, double w) : Shape(l, w) {}

    double area() {
        return Shape::area();
    }
};

class ThreeD_Shape : public Shape {
    double height;
public:
    ThreeD_Shape(double l, double w, double h) : Shape(l, w), height(h){}

    double volume() {
        return Shape::area() * width;
    }

    double area(){
        return 2 * (length * width + width * height + length * height);
    }
};

class Circle : public TwoD_Shape {
private:
    double radius;
    string color;
    float pi;

public:

    Circle(double l, double w, double r, string c) : TwoD_Shape(l, w), radius(r), color(c)
    {
        pi = 3.1415;
    }

    double getRadius(){
        return radius;
    }

    string getColor() {
        return color;
    }

    void setRadius(double r) {
        radius = r;
        setLength(2 * r);
        setWidth(2 * r);
    }

    void setColor(string c) {
        color = c;
    }

    double area() {
        return  pi * radius * radius;
    }
};

class Square : public TwoD_Shape {
private:
    double side;
    string color;

public:
    Square(double s, string c) : side(s), color(c), TwoD_Shape(s, s) {}

    double getSide() {
        return side;
    }

    string getColor() {
        return color;
    }

    void setSide(double s) {
        side = s;
        setLength(s);
        setWidth(s);
    }

    void setColor(string c) {
        color = c;
    }

    double area(){
        return side * side;
    }
};

class Cube : public ThreeD_Shape {
private:
    double height;

public:
    Cube(double l, double w) : height(l), ThreeD_Shape(l,l, w) {}

    double getHeight() {
        return height;
    }

    void setHeight(double h) {
        height = h;
        setWidth(h);
    }

    double volume() {
        return Shape::area() * height;
    }
};

class Pyramid : public ThreeD_Shape {
private:
    double base;
    double height;

public:
    Pyramid(double b, double h, double w) : base(b), height(h), ThreeD_Shape(b, h, w) {}

    double getBase(){
        return base;
    }

    double getHeight() {
        return height;
    }

    void setBase(double b) {
        base = b;
        setLength(b);
    }

    void setHeight(double h) {
        height = h;
        setWidth(h);
    }

    double volume() {
        return (1.0 / 3.0) * Shape::area() * height;
    }
};

int main() {
    Circle circle(5.0, 7.0, 3.0, "red");
    Square square(4.0, "Blue");
    Cube cube(3.0, 2.0);
    Pyramid pyramid(6.0, 8.0, 3.0);

    // Print circle's area
    cout << "Circle Area: " << circle.area() << endl;

    // Print square's area
    cout << "Square Area: " << square.area() << endl;

    // Print cube's area and volume
    cout << "Cube Area: " << cube.area() << endl;
    cout << "Cube Volume: " << cube.volume() << endl;

    // Print pyramid's area and volume
    cout << "Pyramid Area: " << pyramid.area() << endl;
    cout << "Pyramid Volume: " << pyramid.volume() << endl;
}
