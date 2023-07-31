#pragma once
#include "Curve3D.h"
#include "define_dll.h"
class EXTERNAL Helix : public Curve3D
{
	Helix(Point3D p, double step, double r);
public:

	const double
		Radius,
		Step;

	static Helix* GetNew(Point3D p, double step, double r);

	virtual Vector3D countDerivative(double t) const override;
};

