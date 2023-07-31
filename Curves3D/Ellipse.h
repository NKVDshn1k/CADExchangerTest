#pragma once
#include "Curve3D.h"
#include "define_dll.h"

class EXTERNAL Ellipse : public Curve3D
{
	Ellipse(Point3D p, double a, double b);
	
public:
	const double 
		RadiusA, 
		RadiusB;

	static Ellipse* GetNew(Point3D p, double a, double b);

	// Inherited via Curve3D
	virtual Vector3D countDerivative(double t) const override;
};

