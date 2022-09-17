#include<bits/stdc++.h>
using namespace std;
#define pi 3.1416

class Shape{
public:
    Shape(){cout<<"Shape constructing\n";}
    virtual ~Shape(){cout<<"Shape destructing\n";}
    virtual double getArea()=0;
    virtual void show()=0;
};

class Point:public Shape{
public:
    Point(){cout<<"Point constructing\n";}
    ~Point(){cout<<"Point destructing\n";}
    double getArea(){return 0;}
    void show(){cout<<"I am Point!\n";}
};

class Rectangle:public Shape{
    double x,y;
public:
    Rectangle(double a,double b):x(a),y(b){cout<<"Rectangle constructing\n";}
    ~Rectangle(){cout<<"Rectangle destructing\n";}
    double getArea(){return x*y;}
    void show(){cout<<"I am Rectangle!\n";}
};

class Square:public Rectangle{
public:
    Square(double x):Rectangle(x,x){cout<<"Square constructing\n";}
    ~Square(){cout<<"Square destructing\n";}
    //沿用Rectangle的getArea函数
    void show(){cout<<"I am Square!\n";}
};

class Circle:public Point{
    double r;
public:
    Circle(double a):r(a){cout<<"Circle constructing\n";}
    ~Circle(){cout<<"Circle destructing\n";}
    double getArea(){return pi*r*r;}
    void show(){cout<<"I am Circle!\n";}
};

void show(Shape* p){
    p->show();
    cout<<p->getArea()<<endl;
}

int main(){
    Point pnt;
    Rectangle rec(3,4);
    Square sqr(3);
    Circle c(5);

    show(&pnt);
    show(&rec);
    show(&sqr);
    show(&c);

    return 0;
}