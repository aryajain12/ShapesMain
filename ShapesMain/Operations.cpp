#include "Operations.h"
#include <map>
using namespace std;

// Menu Options
MenuOption::MenuOption(int num, string l) {
    number = num;
    label = l;

}


Operations::Operations() {

    MAIN_MENU_OPTIONS = {
        MenuOption(1, "Manage 2D Shapes"),
        MenuOption(2, "Manage 3D Shapes"),
        MenuOption(3, "Display All Shapes"),
        MenuOption(4, "Exit Program")
    };

    SUB_MENU_OPTIONS =
    {
       MenuOption(1, "Add Shape"),
       MenuOption(2, "Update Shape"),
       MenuOption(3, "Delete Shape"),
       MenuOption(4, "Search Shape"),
       MenuOption(5, "Go Back to Main Menu")

    };
}

//function to manange main menu of the program.
void Operations::run() {
    int choice = 0;
    while (true) {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            manage2DShapes();
            break;
        case 2:
            manage3DShapes();
            break;
        case 3:
            displayAllShapes();
            break;
        case 4:
            cout << "Exit program\n";
            return;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

//Main menu of the program.
void Operations::displayMainMenu() {

    cout << "Main Menu\n";
    for (auto& option : MAIN_MENU_OPTIONS) {
        cout << option.number << ". " << option.label << endl;
    }
}

//Function to manage 2d shapes
void Operations::manage2DShapes() {
    int choice = 0;
    while (true) {
        cout << endl;
        cout << "\n2D Shapes Menu\n";

        //displaySubMenu();
        for (auto& option : SUB_MENU_OPTIONS) {
            cout << option.number << ". " << option.label << endl;
        }
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: //Add 2d shape
            cout << endl;
            cout << "Select the type of shape:\n";
            cout << "1. Circle\n";
            cout << "2. Square\n";
            cout << "3. Rectangle\n";
            cout << "4. Triangle\n";

            int shape;
            cin >> shape;

            addShape2d(shape);
            break;
        case 2:
            //update the shape
            updateShape();
            break;
        case 3:
            //delete the shape
            deleteShape();
            break;
        case 4:
            //search the shape
            searchShape();
            break;

        case 5:
            //return back to the main menu
            return;
        default:
            //default message
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void Operations::manage3DShapes() {
    int choice = 0;
    while (true) {
        //manage 3d shapes
        cout << endl;
        cout << "\n3D Shapes Menu\n";
        //displaySubMenu();
        for (const auto option : SUB_MENU_OPTIONS) {
            cout << option.number << ". " << option.label << endl;
        }
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            //add a shape
            cout << endl;
            cout << "Select the type of shape:\n";
            cout << "1. Sphere\n";
            cout << "2. Cube\n";
            cout << "3. Cuboid\n";
            cout << "4. Cylinder\n";
            cout << "5. Hemisphere\n";
            int choice;
            cin >> choice;

            addShape3d(choice);
            break;
        case 2:
            //update the shape
            updateShape();
            break;
        case 3:
            //delete the shape
            deleteShape();
            break;
        case 4:
            //search the shape
            searchShape();
            break;

        case 5:
            //return back to the main menu
            return;
        default:
            //default message
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

//function to add a 2d shape
void Operations::addShape2d(int choice) {
    string name = "";

    cout << "Enter a unique name for the shape: ";
    cin >> name;

    switch (choice) {
    case 1: {
        //Add a circle
        double radius = 0;
        cout << "Enter the radius of the circle: ";
        cin >> radius;

        shapeMap[name] = new Circle(radius);
        break;
    }
    case 2: {
        //Add a square
        double side = 0;
        cout << "Enter the side of the square: ";
        cin >> side;
        shapeMap[name] = new Square(side);
        break;
    }
    case 3: {
        //Add a rectangle
        double length = 0, width = 0;
        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
        shapeMap[name] = new Rectangle(length, width);
        break;
    }
    case 4: {
        //Add a triangle
        double side1 = 0, side2 = 0, side3 = 0;
        cout << "Enter the value of side1, side2 and side3 of the triangle: ";
        cin >> side1 >> side2 >> side3;
        shapeMap[name] = new Triangle(side1, side2, side3);
        break;
    }
    default:
        //default message
        cout << "Invalid choice.\n";
        break;
    }
}

//Add a 3d shape
void Operations::addShape3d(int choice) {
    string name = "";

    cout << "Enter a unique name for the shape: ";
    cin >> name;

    switch (choice) {

    case 1: {
        //add a sphere
        double radius = 0;
        cout << "Enter the radius of the sphere: ";
        cin >> radius;
        shapeMap[name] = new Sphere(radius);
        break;
    }
    case 2: {
        //add a cube
        double side = 0;
        cout << "Enter the side of the cube: ";
        cin >> side;
        shapeMap[name] = new Cube(side);
        break;
    }
    case 3: {
        //add a cuboid
        double length = 0, width = 0, height = 0;
        cout << "Enter the length, width, and height of the cuboid: ";
        cin >> length >> width >> height;
        shapeMap[name] = new Cuboid(length, width, height);
        break;
    }
    case 4: {
        //add a cylinder
        double radius = 0, height = 0;
        cout << "Enter the radius and height of the cylinder: ";
        cin >> radius >> height;
        shapeMap[name] = new Cylinder(radius, height);
        break;
    }
    case 5: {
        //add a hemisphere
        double radius = 0;
        cout << "Enter the radius of the hemisphere: ";
        cin >> radius;
        shapeMap[name] = new Hemisphere(radius);
        break;
    }
    default:
        //default message
        cout << "Invalid choice.\n";
        break;
    }
}

//function to update the known information
void Operations::updateShape() {
    string name = "";
    cout << "Enter the name of the shape to update: ";
    cin >> name;

    auto it = shapeMap.find(name); //find the shape using unique name

    //if shape is a circle?
    if (Circle* circle = dynamic_cast<Circle*>(it->second)) {
        circle->accept();
    }
    //if shape is square?
    else if (Square* square = dynamic_cast<Square*>(it->second)) {
        square->accept();
    }
    //if shape is a rectangle?
    else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(it->second)) {
        rectangle->accept();
    }
    //if shape is a triangle?
    else if (Triangle* triangle = dynamic_cast<Triangle*>(it->second)) {
        triangle->accept();
    }
    //if shape is a cylinder?
    else if (Cylinder* cylinder = dynamic_cast<Cylinder*>(it->second)) {
        cylinder->accept();
    }
    //if shape is a cube?
    else if (Cube* cube = dynamic_cast<Cube*>(it->second)) {
        cube->accept();
    }
    //if shape is a cuboid?
    else if (Cuboid* cuboid = dynamic_cast<Cuboid*>(it->second)) {
        cuboid->accept();
    }
    //if shape is a sphere?
    else if (Sphere* sphere = dynamic_cast<Sphere*>(it->second)) {
        sphere->accept();
    }
    //if shape is a hemisphere?
    else if (Hemisphere* hemisphere = dynamic_cast<Hemisphere*>(it->second)) {
        hemisphere->accept();
    }
    //if shape is not found.
    else
        cout << "The given name not found.\n";
}

//function to delete the given shape
void Operations::deleteShape() {
    string name = "";
    cout << "Enter the name of the shape to delete: ";
    cin >> name;

    auto it = shapeMap.find(name);
    if (it != shapeMap.end()) {
        //delete it->second;
        shapeMap.erase(it);
        cout << "Shape " << name << " deleted successfully.\n";
    }
    else {
        cout << "Shape with name " << name << " not found.\n";
    }
}

//function to search the shape using unique name
void Operations::searchShape() {
    string name = "";
    cout << "Enter the name of the shape to search: ";
    cin >> name;

    auto it = shapeMap.find(name);
    if (it != shapeMap.end()) {
        cout << "Shape found:\n";
        cout << "Name: " << it->first << endl;


        if (Circle* circle = dynamic_cast<Circle*>(it->second)) {
            cout << "Type: Circle\n";
            cout << "Radius: " << circle->getRadius() << endl;
            cout << "Area: " << circle->getArea() << endl;
            cout << "Perimeter: " << circle->getPerimeter() << endl;
        }
        else if (Square* square = dynamic_cast<Square*>(it->second)) {
            cout << "Type: Square\n";
            cout << "Side: " << square->getSide() << endl;
            cout << "Area: " << square->getArea() << endl;
            cout << "Perimeter: " << square->getPerimeter() << endl;
        }
        else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(it->second)) {
            cout << "Type: Rectangle\n";
            cout << "Length: " << rectangle->getLength() << endl;
            cout << "Breadth: " << rectangle->getBreadth() << endl;
            cout << "Area: " << rectangle->getArea() << endl;
            cout << "Perimeter: " << rectangle->getPerimeter() << endl;
        }
        else if (Triangle* triangle = dynamic_cast<Triangle*>(it->second)) {
            cout << "Type: Triangle\n";
            cout << "Side1: " << triangle->getSide1() << endl;
            cout << "Side2: " << triangle->getSide2() << endl;
            cout << "Side3: " << triangle->getSide3() << endl;
            cout << "Area: " << triangle->getArea() << endl;
            cout << "Perimeter: " << triangle->getPerimeter() << endl;
        }
        else if (Cylinder* cylinder = dynamic_cast<Cylinder*>(it->second)) {
            cout << "Type: Cylinder\n";
            cout << "Radius: " << cylinder->getCircle()->getRadius() << endl;
            cout << "Area: " << cylinder->getSurfaceArea() << endl;
            cout << "Perimeter: " << cylinder->getVolume() << endl;
        }
        else if (Cube* cube = dynamic_cast<Cube*>(it->second)) {
            cout << "Type: Cube\n";
            cout << "Side: " << cube->getSquare()->getSide() << endl;
            cout << "Area: " << cube->getSurfaceArea() << endl;
            cout << "Perimeter: " << cube->getVolume() << endl;
        }
        else if (Cuboid* cuboid = dynamic_cast<Cuboid*>(it->second)) {
            cout << "Type: Cuboid\n";
            cout << "Length: " << cuboid->getRectangle()->getLength() << ", Breadth: " << cuboid->getRectangle()->getBreadth() << ", Height: " << cuboid->getHeight() << endl;
            cout << "Area: " << cuboid->getSurfaceArea() << endl;
            cout << "Perimeter: " << cuboid->getVolume() << endl;
        }
        else if (Sphere* sphere = dynamic_cast<Sphere*>(it->second)) {
            cout << "Type: Sphere\n";
            cout << "Radius: " << sphere->getCircle()->getRadius() << endl;
            cout << "Area: " << sphere->getSurfaceArea() << endl;
            cout << "Perimeter: " << sphere->getVolume() << endl;
        }
        else if (Hemisphere* hemisphere = dynamic_cast<Hemisphere*>(it->second)) {
            cout << "Type: Hemisphere\n";
            cout << "Radius: " << hemisphere->getCircle()->getRadius() << endl;
            cout << "Area: " << hemisphere->getSurfaceArea() << endl;
            cout << "Perimeter: " << hemisphere->getVolume() << endl;
        }
    }
    else {
        cout << "Shape with name " << name << " not found.\n";
    }

}

//function to display all shapes
void Operations::displayAllShapes() {

    map<double, pair<string, string>> shapesByArea;
    map<double, pair<string, string>> shapesByPerimeter;
    map<double, pair<string, string>> shapesBySurfaceArea;
    map<double, pair<string, string>> shapesByVolume;

    for (auto pair : shapeMap) {
        if (Circle* circle = dynamic_cast<Circle*>(pair.second)) {
            double area = circle->getArea();
            shapesByArea[area] = { pair.first, "Circle" };
            double perimeter = circle->getPerimeter();
            shapesByPerimeter[perimeter] = { pair.first,"Circle" };
        }
        else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(pair.second)) {
            double area = rectangle->getArea();
            shapesByArea[area] = { pair.first, "Rectangle" };
            double perimeter = rectangle->getPerimeter();
            shapesByPerimeter[perimeter] = { pair.first,"rectangle" };
        }
        else if (Square* square = dynamic_cast<Square*>(pair.second)) {
            double area = square->getArea();
            shapesByArea[area] = { pair.first, "Square" };
            double perimeter = square->getPerimeter();
            shapesByPerimeter[perimeter] = { pair.first,"Square" };
        }
        else if (Triangle* triangle = dynamic_cast<Triangle*>(pair.second)) {
            double area = triangle->getArea();
            shapesByArea[area] = { pair.first, "Triangle" };
            double perimeter = triangle->getPerimeter();
            shapesByPerimeter[perimeter] = { pair.first,"Triangle" };
        }
        else if (Sphere* sphere = dynamic_cast<Sphere*>(pair.second)) {
            double volume = sphere->getVolume();
            shapesByVolume[volume] = { pair.first, "Sphere" };
            double surfaceArea = sphere->getSurfaceArea();
            shapesBySurfaceArea[surfaceArea] = { pair.first, "Sphere" };
        }
        else if (Cuboid* cuboid = dynamic_cast<Cuboid*>(pair.second)) {
            double volume = cuboid->getVolume();
            shapesByVolume[volume] = { pair.first, "Cuboid" };
            double surfaceArea = cuboid->getSurfaceArea();
            shapesBySurfaceArea[surfaceArea] = { pair.first, "Cuboid" };
        }
        else if (Cube* cube = dynamic_cast<Cube*>(pair.second)) {
            double volume = cube->getVolume();
            shapesByVolume[volume] = { pair.first, "Cube" };
            double surfaceArea = cube->getSurfaceArea();
            shapesBySurfaceArea[surfaceArea] = { pair.first, "Cube" };
        }
        else if (Cylinder* cylinder = dynamic_cast<Cylinder*>(pair.second)) {
            double volume = cylinder->getVolume();
            shapesByVolume[volume] = { pair.first, "Cube" };
            double surfaceArea = cylinder->getSurfaceArea();
            shapesBySurfaceArea[surfaceArea] = { pair.first, "Cylinder" };
        }
        else if (Hemisphere* hemisphere = dynamic_cast<Hemisphere*>(pair.second)) {
            double volume = hemisphere->getVolume();
            shapesByVolume[volume] = { pair.first, "Sphere" };
            double surfaceArea = hemisphere->getSurfaceArea();
            shapesBySurfaceArea[surfaceArea] = { pair.first, "Hemisphere" };
        }
    }

    cout << endl;
    cout << "2D Shapes sorted by area: \n";
    for (auto pair : shapesByArea) {
        cout << "\nName: " << pair.second.first << endl;
        cout << "Type: " << pair.second.second << endl;
        cout << "Area: " << pair.first << endl;

    }

    cout << endl;
    cout << "2D Shapes sorted by Perimeter: \n";
    for (auto pair : shapesByPerimeter) {
        cout << "\nName: " << pair.second.first << endl;
        cout << "Type: " << pair.second.second << endl;
        cout << "Perimeter: " << pair.first << endl;

    }

    cout << endl;
    cout << "3D Shapes sorted by Surface Area: \n";
    for (auto pair : shapesBySurfaceArea) {
        cout << "\nName: " << pair.second.first << endl;
        cout << "Type: " << pair.second.second << endl;
        cout << "Surface Area: " << pair.first << endl;

    }

    cout << endl;
    cout << " 3D Shapes sorted by Volume: \n";
    for (auto pair : shapesByVolume) {
        cout << "\nName: " << pair.second.first << endl;
        cout << "Type: " << pair.second.second << endl;
        cout << "Volume: " << pair.first << endl;

    }

}
