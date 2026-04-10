#pragma once

class CPoint
{
public:
	CPoint() = default;
	CPoint(double x, double y)
		: x(x)
		, y(y) {}
	~CPoint() = default;
	double x;
	double y;
};