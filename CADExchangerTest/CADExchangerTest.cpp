#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <omp.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "../Curves3D/Curve3D.h"
#include "RandomFactory.h"

using namespace std;

inline void PrintAllPointsAndDerivatives(vector<shared_ptr<Curve3D>> curves);
inline vector<shared_ptr<Circle>> GeyCircles(vector<shared_ptr<Curve3D>> curves);
inline void Sort(vector<shared_ptr<Circle>>&);
inline double GetRadiusSum(vector<shared_ptr<Circle>>);

int main()
{
    int elems_num = 20;

    vector<shared_ptr<Curve3D>> curves;
    curves.reserve(elems_num);

    for (int i = 0; i < elems_num; i++)
        curves.push_back(RandomFactory::GetAnyCurve());
    
    PrintAllPointsAndDerivatives(curves);
    cout << endl;

    vector<shared_ptr<Circle>> circles = GeyCircles(curves);

    Sort(circles);

    for (int i = 0; i < circles.size(); i++)
        cout << circles[i]->Radius << endl;

    cout << endl;

    cout << "Sum of R = " << GetRadiusSum(circles) << endl;

}

void PrintAllPointsAndDerivatives(vector<shared_ptr<Curve3D>> curves)
{
    for (int i = 0; i < curves.size(); i++)
    {
        auto p = curves[i]->getLocation();
        auto v = curves[i]->countDerivative(M_PI / 4);
        cout.setf(ios::left);


        printf_s("%-10s point = (%.2lf, %.2lf, %.2lf)  \tf'(t) = (%.2lf, %.2lf, %.2lf)\n",
            curves[i]->CurveName.c_str(), p.x, p.y, p.z, v.x, v.y, v.z);
    }
}

vector<shared_ptr<Circle>> GeyCircles(vector<shared_ptr<Curve3D>> curves)
{
    vector<shared_ptr<Circle>> circles;

    for (int i = 0; i < curves.size(); i++)
    {
        if (typeid(*curves[i].get()) != typeid(Circle))
            continue;

        shared_ptr<Circle> circle = dynamic_pointer_cast<Circle>(curves[i]);
        circles.push_back(circle);      
    }

    return circles;
}

void Sort(vector<shared_ptr<Circle>>& circles)
{
    auto byRadiusComparer = [](shared_ptr<Circle> c1, shared_ptr<Circle> c2) {
        return c1->Radius < c2->Radius;
    };

    sort(circles.begin(), circles.end(), byRadiusComparer);
}

double GetRadiusSum(vector<shared_ptr<Circle>> circles)
{
    double sum = 0;
    #pragma omp parallel num_threads(2) for \
            reduction(+:s)
    for (int i = 0; i < circles.size(); i++)
        sum += circles[i]->Radius;

    return sum;
}