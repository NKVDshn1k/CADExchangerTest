#include "Circle.h"
#include <stdexcept>

Circle::Circle(Point3D p, double radius)
    : Curve3D(p, "Circle"), Radius(radius) {}

Circle* Circle::GetNew(Point3D p, double radius)
{
    if (radius <= 0)
        throw std::invalid_argument("Radius must be more than zero");

    if (p.z != 0)
        throw std::invalid_argument("Z axis must be zero");

    return new Circle(p, radius);
}

inline Vector3D Circle::countDerivative(double t) const {

    double
        b = sqrt(abs( pow(Radius, 2) - pow(t - _location.x, 2))),
        a = _location.x - t;

    return Vector3D(b, a, 0);
}
