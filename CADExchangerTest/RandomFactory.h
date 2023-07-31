#pragma once
#include "../Curves3D/Circle.h"
#include "../Curves3D/Ellipse.h"
#include "../Curves3D/Helix.h"

#include <memory>

using std::shared_ptr;
using std::make_shared;

static class RandomFactory
{
	static double drnd(double start, double fin);

public:

	static Point3D GetPoint();

	static Point3D Get2DPoint();

	static Helix* GetNewHelix();

	static Ellipse* GetNewElipse();
	 
	static Circle* GetNewCircle();

	static shared_ptr<Curve3D> GetAnyCurve();

};

