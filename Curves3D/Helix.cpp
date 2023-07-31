#include "Helix.h"
#define _USE_MATH_DEFINES 
#include <math.h>
#include <stdexcept>

Helix::Helix(Point3D p, double step, double r)
	: Curve3D(p, "Helix"), Radius(r), Step(step) {}

Helix* Helix::GetNew(Point3D p, double step, double r) {
	if (r <= 0)
		throw std::invalid_argument("Radius must be more than zero");
	if (step <= 0)
		throw std::invalid_argument("Step must be more than zero");

	return new Helix(p, step, r);
}

inline Vector3D Helix::countDerivative(double t) const
{
    double
        y = -Radius * sin(t),
        x = Radius * cos(t),
        z = Step / (2 * M_PI);

    return Vector3D(x,y,z);
}
