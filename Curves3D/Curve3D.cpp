#include "Curve3D.h"

Curve3D::Curve3D(Point3D location, string name) :
	CurveName(name), _location(location) {}

Point3D Curve3D::getLocation() const {
	return _location;
}
