#ifndef GEOMETRIC_SHAPES_CPP
#define GEOMETRIC_SHAPES_CPP

#include<iostream>
#include "GeometricShapes.h"
#include<cmath>
using namespace std;

//Constructor of base class
GeometricShapes::GeometricShapes() {}

//Destructor of base class
GeometricShapes::~GeometricShapes() {
	//cout << "The destructor of geometric shapes invoked.\n";
}

//Constructor of 2D shapes class
Shapes2D::Shapes2D() {
	area = 0;
	perimeter = 0;
}

//Destructor of 2D shapes class
Shapes2D::~Shapes2D() {
	//cout << "The destructor of 2D shapes invoked.\n";
}

//Constructor of 3D shapes class
Shapes3D::Shapes3D() {
	surfaceArea = 0;
	volume = 0;
}

//Destructor of 3D shapes class
Shapes3D::~Shapes3D() {
	//cout << "The destructor of 3D shapes invoked.\n";
}


//2D shape: Circle class function definition

Circle::Circle() { //default constructor 
	radius = 0;
}
Circle::Circle(double radius) { //parameterised constructor
	this->radius = radius;
}
void Circle::accept() { //function to accept the updated values of radius
	cout << "Enter radius: ";
	cin >> radius;
}
void Circle::setRadius(double radius) //setter function for the radius of circle
{
	this->radius = radius;
}

double Circle::getRadius() //to get the radius of the circle
{
	return radius;
}

double Circle::getArea() { //calculates the area of circle
	area = PI * radius * radius;
	return area;
}
double Circle::getPerimeter() { //calculates the perimeter of circle
	perimeter = 2 * PI * radius;
	return perimeter;
}
void Circle::display() { //displays the area and perimeter of the circle
	cout << "The area of circle is: " << area << "\n";
	cout << "The circumference of circle is: " << perimeter << "\n";

}
Circle::~Circle() {
	//cout << "Destructor of circle invoked\n";
}


//2D shape: Square class function definition

Square::Square() {//default constructor
	side = 0;
}
Square::Square(double side) {//parameterized constructor
	this->side = side;
}
void Square::accept() {//updates the side of the square
	cout << "Enter the side of the square: ";
	cin >> side;
}
void Square::setSide(double) {//setter function to set the side
	this->side = side;
}
double Square::getSide() {//getter function to get the side
	return side;
}
double Square::getArea() {//calculates and returns the area of the square
	area = side * side;
	return area;
}
double Square::getPerimeter() {//calculates and returns the perimeter of the square
	perimeter = 4 * side;
	return perimeter;
}
void Square::display() {//displays the area and perimeter of the square
	cout << "The area of square is: " << area << "\n";
	cout << "The circumference of square is: " << perimeter << "\n";
}
Square::~Square() {
	//cout << "Destructor of square invoked\n";
}


//2D shape: Rectangle class function definition

Rectangle::Rectangle() {//default constructor
	length = 0;
	breadth = 0;
}
Rectangle::Rectangle(double length, double breadth) {//parameterized constructor
	this->length = length;
	this->breadth = breadth;
}
void Rectangle::accept() {//update the length and breadth of rectangle
	cout << "Enter length and breadth of the rectangle: ";
	cin >> length >> breadth;
}
void Rectangle::setLength(double length) {//set the length
	this->length = length;
}
double Rectangle::getLength() {//get the length
	return length;
}
void Rectangle::setBreadth(double breadth) {//set the breadth
	this->breadth = breadth;
}
double Rectangle::getBreadth() {//get the breadth
	return breadth;
}
double Rectangle::getArea() {//calculate and return the area
	area = length * breadth;
	return area;
}
double Rectangle::getPerimeter() {//calculate and return the perimeter
	perimeter = 2 * (length + breadth);
	return perimeter;
}
void Rectangle::display() {//display area and perimeter
	cout << "The area of rectangle is: " << area << "\n";
	cout << "The circumference of rectangle is: " << perimeter << "\n";
}
Rectangle::~Rectangle() {
	//cout << "Destructor of rectangle invoked\n";
}


//2D shape: Triangle class function definition

Triangle::Triangle() {//default constructor
	side1 = 0;
	side2 = 0;
	side3 = 0;
}
Triangle::Triangle(double side1, double side2, double side3) {//parameterized constructor
	this->side1 = side1;
	this->side2 = side2;
	this->side3 = side3;
}
void Triangle::accept() {//updates the sides of triangle
	cout << "Enter the value of side1: ";
	cin >> side1;
	cout << "Enter the value of side2: ";
	cin >> side2;
	cout << "Enter the value of side3: ";
	cin >> side3;
}
void Triangle::setSide1(double side1) {//set the first side
	this->side1 = side1;
}
double Triangle::getSide1() {//get the first side
	return side1;
}
void Triangle::setSide2(double side2) {//set the second side
	this->side2 = side2;
}
double Triangle::getSide2() {//get the second side
	return side2;
}
void Triangle::setSide3(double side3) {//set the third side
	this->side3 = side3;
}
double Triangle::getSide3() {//get the third side
	return side3;
}
double Triangle::getArea() { //calculate and return the area
	double s = (side1 + side2 + side3) / 2;
	area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
	return area;
}
double Triangle::getPerimeter() {//calculate and return the perimeter
	perimeter = side1 + side2 + side3;
	return perimeter;
}
void Triangle::display() {//displays area and perimeter of triangle
	cout << "The area of triangle is: " << area << "\n";
	cout << "The circumference of triangle is: " << perimeter << "\n";
}
Triangle::~Triangle() {
	//cout << "Destructor of triangle invoked\n";
}


//3D shape: Cylinder class function definition

Cylinder::Cylinder() { //default constructor
	height = 0;
	pCircle = new Circle();

}
Cylinder::Cylinder(double radius, double height) {//parameterized constructor
	pCircle = new Circle(radius);
	this->height = height;
}
void Cylinder::setHeight(double height) {//set height of the cylinder
	this->height = height;
}
double Cylinder::getHeight() { //get height of the cylinder
	return height;
}
void Cylinder::setCircle(Circle* circle) {//set the radius of the cylinder using circle pointer
	pCircle = circle;
}
Circle* Cylinder::getCircle() {//get the radius of the cylinder
	return pCircle;
}
void Cylinder::accept() {//update the radius and height of the cylinder
	cout << "Enter radius of the cylinder: ";
	double r;
	cin >> r;
	pCircle->setRadius(r);
	cout << "Enter height of the cylinder: ";
	cin >> height;
}
double Cylinder::getSurfaceArea() {//calculate and return the surface area of cylinder
	surfaceArea = 2 * PI * ((*pCircle).getRadius()) * ((*pCircle).getRadius() + height);
	return surfaceArea;
}
double Cylinder::getVolume() {//calculate and return volume of the cylinder
	volume = PI * pow((*pCircle).getRadius(), 2) * height;
	return volume;
}
void Cylinder::display() {//displays surface area and volume
	cout << "The area of cylinder is: " << surfaceArea << "\n";
	cout << "The volume of cylinder is: " << volume << "\n";
}
Cylinder::~Cylinder() {
	//cout << "Destructor of cylinder invoked\n";
}


//3D shape: Cube class function definition

Cube::Cube() {//default constructor
	pSquare = new Square();
}
Cube::Cube(double side) {//parameterized constructor
	pSquare = new Square(side);
}
void Cube::setSquare(Square* square) {//set the side of square
	pSquare = square;
}
Square* Cube::getSquare() {//get the side of square
	return pSquare;
}
void Cube::accept() {//updates the sides of cube
	cout << "Enter the side of the cube: ";
	double s; cin >> s;
	pSquare->setSide(s);
}
double Cube::getSurfaceArea() {//calculate and return the surface area
	surfaceArea = 6 * pow(pSquare->getSide(), 2);
	return surfaceArea;
}
double Cube::getVolume() {//calculate and return volume
	volume = pow(pSquare->getSide(), 3);
	return volume;
}
void Cube::display() {//displays surface area and volume
	cout << "The area of cube is: " << surfaceArea << "\n";
	cout << "The volume of cube is: " << volume << "\n";
}
Cube::~Cube() {
	//cout << "Destructor of CUBE invoked\n";
}


//3D shape: Cuboid class function definition

Cuboid::Cuboid() {//default constructor
	height = 0;
	pRectangle = new Rectangle();
}
Cuboid::Cuboid(double length, double breadth, double height) {//parameterized constructor
	this->height = height;
	pRectangle = new Rectangle(length, breadth);
}
void Cuboid::setHeight(double height) {//set the height of cuboid
	this->height = height;
}
double Cuboid::getHeight() { //get the height of cuboid
	return height;
}
void Cuboid::setRectangle(Rectangle* rectangle) { //set the length and breadth of cuboid
	pRectangle = rectangle;
}
Rectangle* Cuboid::getRectangle() {//get the length and breadth of cuboid 
	return pRectangle;
}
void Cuboid::accept() {
	int l, b, h;
	cout << "Enter length of the cuboid: \n";
	cin >> l;
	pRectangle->setLength(l);
	cout << "Enter breadth of the cuboid: \n";
	cin >> b;
	pRectangle->setBreadth(b);
	cout << "Enter height of the cuboid: \n";
	cin >> h;
}
double Cuboid::getSurfaceArea() {//calculate and return the surface area
	surfaceArea = 2 * ((pRectangle->getLength() * pRectangle->getBreadth()) + (pRectangle->getBreadth() * height) + (pRectangle->getLength() * height));
	return surfaceArea;
}
double Cuboid::getVolume() {//calculate and return volume
	volume = pRectangle->getLength() * pRectangle->getBreadth() * height;
	return volume;
}
void Cuboid::display() {//displays surface area and volume
	cout << "The area of cuboid is: " << surfaceArea << "\n";
	cout << "The volume of cuboid is: " << volume << "\n";
}
Cuboid::~Cuboid() {
	//cout << "Destructor of cuboid invoked\n";
}



//3D shape: Sphere class function definition

Sphere::Sphere() {//default constructor
	pCircle = new Circle();
}
Sphere::Sphere(double radius) {//parameterized constructor
	pCircle = new Circle(radius);
}
void Sphere::setCircle(Circle* circle) {//set the radius of sphere using pointer
	pCircle = circle;
}
Circle* Sphere::getCircle() {//get the radius using pointer of circle
	return pCircle;
}
void Sphere::accept() {//update the radius of the sphere
	cout << "Enter radius of the sphere: ";
	double r;
	cin >> r;
	pCircle->setRadius(r);
}
double Sphere::getSurfaceArea() {//calculate and return the surface area
	surfaceArea = 4 * PI * pow(pCircle->getRadius(), 2);
	return surfaceArea;
}
double Sphere::getVolume() {//calculate and return volume
	volume = (double)4 / 3 * PI * pow(pCircle->getRadius(), 3);
	return volume;
}
void Sphere::display() {//displays surface area and volume
	cout << "The area of sphere is: " << surfaceArea << "\n";
	cout << "The volume of sphere is: " << volume << "\n";
}
Sphere::~Sphere() {
	//cout << "Destructor of sphere invoked\n";
}



//3D shape: Hemisphere class function definition

Hemisphere::Hemisphere() {//default constructor
	pCircle = new Circle();
}
Hemisphere::Hemisphere(double radius) {//parameterized constructor
	pCircle = new Circle(radius);
}
void Hemisphere::setCircle(Circle* circle) {//set the radius of hemisphere using pointer
	pCircle = circle;
}
Circle* Hemisphere::getCircle() {//get the radius using pointer of circle
	return pCircle;
}
void Hemisphere::accept() {//update the radius of hemisphere
	cout << "Enter radius of the sphere: ";
	double r;
	cin >> r;
	pCircle->setRadius(r);
}
double Hemisphere::getSurfaceArea() {//calculate and return the surface area
	surfaceArea = 3 * PI * pow(pCircle->getRadius(), 2);
	return surfaceArea;
}
double Hemisphere::getVolume() {//calculate and return volume
	volume = (double)2 / 3 * PI * pow(pCircle->getRadius(), 3);
	return volume;
}
void Hemisphere::display() {//displays surface area and volume
	cout << "The area of hemisphere is: " << surfaceArea << "\n";
	cout << "The volume of hemisphere is: " << volume << "\n";
}
Hemisphere::~Hemisphere() {
	//cout << "Destructor of hemisphere invoked\n";
}
#endif

