#pragma once

#include "Shapes.h"
#include <string>
#include <time.h>

static int const start = 1;
static int const end = 10;

class FactoryofShapes
{
	static int intRandom()
	{
		srand(time(0));
		return 1+rand() % 10;
	}

	static double doubleRand()
	{
		double f = (double)intRandom() / RAND_MAX;
		return start + f * (end - start);
	}

	static Point randPoint()
	{
		return Point(doubleRand(), doubleRand());
	}

public:
	static const std::string point;
	static const std::string circle;
	static const std::string square;
	static const std::string rect;
	static const std::string polyline;
	static const std::string polygon;

	static Shape * CreateShape(std::string const & name)
	{
		if (name == point)
		{
			return new Point(randPoint());
		}
		if (name == circle)
		{ 
			double r = doubleRand();
			Point p = randPoint();
			return new Circle(r, p);
		}
		if (name == square)
		{
			double l = doubleRand();
			Point p = randPoint();
			return new Square(p, l);
		}
		if (name == rect)
		{
			Point p1 = randPoint();
			Point p2 = randPoint();
			return new Rect(p1, p2);
		}
		if (name == polyline)
		{ 
			Polyline * polyline = new Polyline;
			int n = intRandom();
			for (int i = 0; i < n; i++)
			{
				Point temp_point = randPoint();
				polyline->AddPoint(temp_point);
			}
			return polyline;
		}
		if (name == polygon)
		{
			Polygon * polygon = new Polygon;
			int n = intRandom();
			for (int i = 0; i < n; i++)
			{
				Point temp_point = randPoint();
				polygon->AddPoint(temp_point);
			}
			return polygon;
		}
	}
};

const std::string FactoryofShapes::point = "Point";
const std::string FactoryofShapes::circle = "Circle";
const std::string FactoryofShapes::square = "Square";
const std::string FactoryofShapes::rect = "Rect";
const std::string FactoryofShapes::polyline = "Polyline";
const std::string FactoryofShapes::polygon = "Polygon";
