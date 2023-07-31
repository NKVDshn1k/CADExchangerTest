#include "Ellipse.h"
#include <stdexcept>

Ellipse::Ellipse(Point3D p, double a, double b)
    : Curve3D(p, "Ellipse"), RadiusA(a), RadiusB(b) {}

Ellipse* Ellipse::GetNew(Point3D p, double a, double b)
{
	if (a <= 0 || b <= 0)
		throw std::invalid_argument("Radius must be more than zero");

    if (p.z != 0)
        throw std::invalid_argument("Z axis must be zero");

    return new Ellipse(p, a, b);
}

inline Vector3D Ellipse::countDerivative(double t) const
{

    double
        a = RadiusB * (t - _location.x),
        b = sqrt(abs(1 - (pow(t - _location.x, 2) / RadiusA)));

    return Vector3D(b, a, 0);
}
