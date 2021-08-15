#include <iostream>
#include <cmath>
//circle, square, triangle, rectangle
enum Colors{
    RAD,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE
};

class Figure{
    std::string color;
    float xCenter, yCenter, zCenter;
public:

    void  SetColor(std::string col){
        if (col=="rad") col=RAD;
        else if (col=="orange") col=ORANGE;
        else if (col=="yellow") col=YELLOW;
        else if (col=="green") col=GREEN;
        else if (col=="blue") col=BLUE;
        else if (col=="purple") col=PURPLE;

    }
    void input(float x, float y, float z, std::string col){
        xCenter=x; yCenter=y; zCenter=z; color=col;
        std::cout<<"Coordinate of center "<<xCenter<<" "<<yCenter<<
        " "<<zCenter<<"\n color "<<color<<std::endl;
    }
    float  Space(float s){
        return  s;
    }
    void Zone(float a, float  b, float  c=0){

        float xMax=xCenter+a/2;
        float yMax=yCenter+c/2;
        float zMax=zCenter-b/2;
        float xMin=xCenter-a/2;
        float yMin=yCenter-c/2;
        float zMin=zCenter+b/2;
        std::cout<<"Max coordinate point of zone "<<xMax<<" "<<yMax<<" "<<zMax<<
                 "Min coordinate point of zone "<<xMin<<" "<<yMin<<" "<<zMin<<std::endl;
    }
};
class Circle: public Figure{

public:
    float space(float r){
        return r*r*3.14;
    }
};
class Square: public Figure{
public:
    float space(float a){
        return a*a;
    }
};
class Triangle: public Figure{

public:
    float space(float a){
        return sqrt(a*a-a/2*a/2)*a/2;
    }
};
class Rectangle: public Figure{
public:
    float space(float a, float  b){
        return a*b;
    }

};

int main() {
    std::string command;
    std::cin>>command;
    float x,y,z;
    std::string col;
    if (command=="circle"){
        float r;
        Circle* circle=new Circle;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        circle->SetColor(col);
        circle->input(x,y,z, col);
        std::cin>>r;
        std::cout << "\nS=" << circle->Space(circle->space(r)) << std::endl;
        circle->Zone(r,r);
    }
    else if (command=="square"){
        float a;
        Square* square=new Square;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        square->SetColor(col);
        square->input(x,y,z,col);
        std::cin>>a;
        std::cout << "\nS=" << square->Space(square->space(a)) << std::endl;
        square->Zone(a/2,a/2);
    }
    else if (command=="triangle"){
        float a;
        Triangle* triangle=new Triangle;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        triangle->SetColor(col);
        triangle->input(x,y,z,col);
        std::cin>>a;
        std::cout << "\nS=" << triangle->Space(triangle->space(a)) << std::endl;
        triangle->Zone(a/2,(sqrt(a*a-a/2*a/2)/2));
    }
    else if (command=="rectangle"){
        float a,b;
        Rectangle* rectangle=new Rectangle;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        rectangle->SetColor(col);
        rectangle->input(x,y,z,col);
        std::cin>>a>>b;
        std::cout << "\nS=" << rectangle->Space(rectangle->space(a, b)) << std::endl;
        rectangle->Zone(a,b);
    }

}
