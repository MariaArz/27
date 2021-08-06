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

    void  colo(std::string col){
        if (col=="rad") col=RAD;
        if (col=="orange") col=ORANGE;
        if (col=="yellow") col=YELLOW;
        if (col=="green") col=GREEN;
        if (col=="blue") col=BLUE;
        if (col=="purple") col=PURPLE;

    }
    void input(float x, float y, float z, std::string col){
        xCenter=x; yCenter=y; zCenter=z; color=col;
        std::cout<<"Coordinate of center "<<xCenter<<" "<<yCenter<<
        " "<<zCenter<<"\n color "<<color<<std::endl;
    }
    float  Space(float s){
        return  s;
    }
    void Zone(float a, float  b, float  c){

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
    float s(float r){
        return r*r*3.14;
    }
};
class Square: public Figure{
public:
    float S(float a){
        return a*a;
    }
};
class Triangle: public Figure{

public:
    float ST(float a){
        return sqrt(a*a-a/2*a/2)*a/2;
    }
};
class Rectangle: public Figure{
public:
    float SpaceOfCover(float a, float  b){
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
        circle->colo(col);
        circle->input(x,y,z, col);
        std::cin>>r;
        std::cout<<"\nS="<<circle->Space(circle->s(r))<<std::endl;
        circle->Zone(r,r,0);
    }
    else if (command=="square"){
        float a;
        Square* square=new Square;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        square->colo(col);
        square->input(x,y,z,col);
        std::cin>>a;
        std::cout<<"\nS="<<square->Space(square->S(a))<<std::endl;
        square->Zone(a/2,a/2,0);
    }
    else if (command=="triangle"){
        float a;
        Triangle* triangle=new Triangle;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        triangle->colo(col);
        triangle->input(x,y,z,col);
        std::cin>>a;
        std::cout<<"\nS="<<triangle->Space(triangle->ST(a))<<std::endl;
        triangle->Zone(a/2,(sqrt(a*a-a/2*a/2)/2),0);
    }
    else if (command=="rectangle"){
        float a,b,c;
        Rectangle* rectangle=new Rectangle;
        std::cout<<"Coordinate of center and color"<<std::endl;
        std::cin>>x>>y>>z>>col;
        rectangle->colo(col);
        rectangle->input(x,y,z,col);
        std::cin>>a>>b>>c;
        std::cout<<"\nS="<<rectangle->Space(rectangle->SpaceOfCover(a,b,c))<<std::endl;
        rectangle->Zone(a,b,c);
    }

}
