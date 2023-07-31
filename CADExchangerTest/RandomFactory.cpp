#include "RandomFactory.h"
#include <stdlib.h>

inline double RandomFactory::drnd(double start, double fin) {
	return
		start +
		((double)rand() / RAND_MAX) *
		(fin - start);
}

inline Point3D RandomFactory::GetPoint() {
	return Point3D(drnd(-100, 100), drnd(-100, 100), drnd(-100, 100));
}

inline Point3D RandomFactory::Get2DPoint() {
	return Point3D(drnd(-100, 100), drnd(-100, 100), 0);
}

Helix* RandomFactory::GetNewHelix(){
	return Helix::GetNew(GetPoint(), drnd(1,4), drnd(1,6));
}

Ellipse* RandomFactory::GetNewElipse() {
	return Ellipse::GetNew(Get2DPoint(), drnd(1, 6), drnd(1, 6));
}

Circle* RandomFactory::GetNewCircle() {
	return Circle::GetNew(Get2DPoint(), drnd(1, 6));
}

shared_ptr<Curve3D> RandomFactory::GetAnyCurve()
{
	int switcher = rand() % 3;

	shared_ptr<Curve3D> curve;

	switch (switcher)
	{
	case 1:
		curve.reset(GetNewCircle());
		break;
	case 2:
		curve.reset(GetNewElipse());
		break;
	default:
		curve.reset(GetNewHelix());
		break;
	}

	return curve;
}
