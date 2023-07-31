#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include <string>
#include "define_dll.h"

using std::string;

class EXTERNAL Curve3D
{
protected:
	Point3D _location;

	Curve3D(Point3D location, string name);
public: 
	const string CurveName;

	Point3D getLocation() const;

	virtual Vector3D countDerivative(double t) const = 0;
};