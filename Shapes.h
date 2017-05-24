#pragma once

#include "Base.h"
#include "Container.h"
#include <math.h>
#include <string>

class Shape : virtual public Printable
{
public:
	Shape() 
	{
		++count; 
	}
	Shape( Shape const & other) 
	{ 
		++count; 
	}
	virtual ~Shape() 
	{
		--count; 
	}
	static int getCount() 
	{
		return count; 
	}

private:
	static int count;
};

int Shape::count = 0;

class Point : public Named, public Shape
{
	double coordinate_x;
	double coordinate_y;

public:
	Point(): Named("Point")
	{
		coordinate_x = 0;
		coordinate_y = 0;
	}
	Point(double x, double y) : coordinate_x(x), coordinate_y(y), Named("Point") {}
	
	double GetX(void) const
	{
		return coordinate_x;
	}
	double GetY(void) const
	{
		return coordinate_y;
	}
	void print(void) const
	{
		std::cout << GetName() << ": " << "(" << coordinate_x << "," << coordinate_y << ")\n";
	}
};

class Circle : public Named, public Shape
{
	double radius;
	Point point;
public:
	Circle(double r, Point const & con_point) : radius(r), point(con_point), Named("Circle") {}
	double area() const
	{
		return 3.14159 * radius * radius;
	}
	void print(void) const
	{
		std::cout << GetName() << ": \n";
		std::cout << "radius: " << radius << ", area: " << area();
	}
};

class Rect : virtual public Named, public Shape
{
	Point point1;
	Point point2;
	Point point3;
	Point point4;
public:
	Rect( Point const & con_point1, Point const & con_point2 )
		: Named("Rect")
		, point1(con_point1)
		, point2(con_point2)
		, point3(point1.GetX(), point2.GetY())
		, point4(point2.GetX(), point1.GetY())
	{}

	void print(void) const
	{
		std::cout << GetName() << ": \n";
		point1.print();
		std::cout << ", ";
		point2.print();
		std::cout << ", ";
		point3.print();
		std::cout << ", ";
		point4.print();
	}
};

class Square : virtual public Named, public Rect
{
	double length;
public:
	Square(Point point1, double l)
		: Named("Square")
		, Rect (point1, Point(point1.GetX() + length, point1.GetY() + length))
		, length(l)
	{}
	double area() const
	{
		return length * length;
	}
	void print(void) const
	{
		std::cout << GetName() << ": \n";
		std::cout << "length of the side: " << length << ", area: " << area();
	}
};

class Polyline : virtual public Named, public Shape
{
public:
	Polyline() : Named("Polyline") {}
	void AddPoint(Point const & point)
	{
		points.AddEnd(point);
	}
	double GetLength(void) const
	{
		double length = 0;
		Point firstpoint = points.getHead();
		Point temp_point = firstpoint;
		Container<Point>::Iterator j = points.begin();

		for (Container<Point>::Iterator i = points.begin(); i != points.end(); ++i)
		{
			length += GetDistance(*i, temp_point);
			temp_point = (*i);
		}
		return length;
	}
	void print(void) const
	{
		std::cout << GetName() << ": \n";
		std::cout << "Length: " << GetLength() << "\n";
		for (Container<Point>::Iterator i = points.begin(); i != points.end(); ++i)
		{
			(*i).print();
		}
	}

protected:
	Container<Point> points;
	double GetDistance(Point point1, Point point2) const
	{
		return sqrt(pow(point1.GetX() - point2.GetX(), 2) + pow(point1.GetY() - point2.GetY(), 2));
	}
};

class Polygon : virtual public Named, public Polyline
{
public:
	Polygon() : Named("Polygon") {}
	double GetLength(void) const
	{
		double length = Polyline::GetLength();
		length += GetDistance(points.getHead(), points.getEnd());
		return length;
	}
	void print(void) const
	{
		Polyline::print();
	}
};
