#pragma once
#include "Curve3D.h"
#include "define_dll.h"

class EXTERNAL Circle : public Curve3D
{
	Circle(Point3D p, double radius);
public:
	const double Radius;

	static Circle* GetNew(Point3D p, double radius);

	virtual Vector3D countDerivative(double t) const override;
};
