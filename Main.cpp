#include "FactoryofShapes.h"

int main()
{
	Container<Shape *> shapes;

	shapes.AddEnd(FactoryofShapes::CreateShape(FactoryofShapes::point));
	shapes.AddEnd(FactoryofShapes::CreateShape(FactoryofShapes::circle));
	shapes.AddEnd(FactoryofShapes::CreateShape(FactoryofShapes::rect));
	shapes.AddEnd(FactoryofShapes::CreateShape(FactoryofShapes::polyline));
	shapes.AddEnd(FactoryofShapes::CreateShape(FactoryofShapes::square));
	shapes.AddEnd(FactoryofShapes::CreateShape(FactoryofShapes::polygon));

	std::cout << Shape::getCount() << std::endl;

	for( Container<Shape *>::Iterator it = shapes.begin(); it != shapes.end(); ++it )
	{
		it->print();
		delete *it;
	}

	std::cout << Shape::getCount() << std::endl;
	getchar();
}
