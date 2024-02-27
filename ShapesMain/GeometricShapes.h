#pragma once
#ifndef GEOMETRIC_SHAPES_H
#define GEOMETRIC_SHAPES_H

class GeometricShapes {
protected:
	const double PI = 3.1415;

public:
	GeometricShapes();
	virtual void display() = 0;
	virtual void accept() = 0;
	~GeometricShapes();
};

class Shapes2D : public GeometricShapes {
protected:
	double area;
	double perimeter;
public:
	Shapes2D();
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	~Shapes2D();
};

class Shapes3D : public GeometricShapes {
protected:
	double surfaceArea;
	double volume;
public:
	Shapes3D();
	virtual double getSurfaceArea() = 0;
	virtual double getVolume() = 0;
	~Shapes3D();
};
class Circle : public Shapes2D {
protected:
	double radius;
	//int[2] centreCoord; // is it fully constrained?
	// how to define plane?
	// [0,0,1] unit z vector ...int [3] [0,0,1]

public:
	Circle();
	Circle(double r);
	void accept();
	void setRadius(double);
	double getRadius();
	double getArea();
	double getPerimeter();
	void display();
	~Circle();
};
class Square : public Shapes2D {
protected:
	double side;
public:
	Square();
	Square(double side);
	void accept();
	void setSide(double);
	double getSide();
	double getArea();
	double getPerimeter();
	void display();
	~Square();
};
class Rectangle : public Shapes2D {
protected:
	double length, breadth;
public:
	Rectangle();
	Rectangle(double length, double breadth);
	void accept();
	void setLength(double);
	double getLength();
	void setBreadth(double);
	double getBreadth();
	double getArea();
	double getPerimeter();
	void display();
	~Rectangle();
};
class Triangle : public Shapes2D {
protected:
	double side1, side2, side3;
public:
	Triangle();
	Triangle(double side1, double side2, double side3);
	void accept();
	void setSide1(double);
	double getSide1();
	void setSide2(double);
	double getSide2();
	void setSide3(double);
	double getSide3();
	double getArea();
	double getPerimeter();
	void display();
	~Triangle();
};
class Cylinder : public Shapes3D {
	double height;
	Circle* pCircle;

public:
	Cylinder();
	Cylinder(double radius, double height);
	void setHeight(double h);
	double getHeight();
	void setCircle(Circle* circle);
	Circle* getCircle();
	void accept();
	double getSurfaceArea();
	double getVolume();
	void display();
	~Cylinder();

};
class Cube : public Shapes3D {
	Square* pSquare;
public:
	Cube();
	Cube(double side);
	void setSquare(Square* square);
	Square* getSquare();
	void accept();
	double getSurfaceArea();
	double getVolume();
	void display();
	~Cube();
};
class Cuboid : public Shapes3D {
	Rectangle* pRectangle;
	double height;
public:
	Cuboid();
	Cuboid(double length, double breadth, double height);
	void setHeight(double);
	double getHeight();
	void setRectangle(Rectangle* rectangle);
	Rectangle* getRectangle();
	void accept();
	double getSurfaceArea();
	double getVolume();
	void display();
	~Cuboid();
};
class Sphere : public Shapes3D {
	Circle* pCircle;
public:
	Sphere();
	Sphere(double radius);
	void accept();
	void setCircle(Circle* circle);
	Circle* getCircle();
	double getSurfaceArea();
	double getVolume();
	void display();
	~Sphere();
};
class Hemisphere : public Shapes3D {
	Circle* pCircle;
public:
	Hemisphere();
	Hemisphere(double radius);
	void accept();
	void setCircle(Circle* circle);
	Circle* getCircle();
	double getSurfaceArea();
	double getVolume();
	void display();
	~Hemisphere();
};
#endif
