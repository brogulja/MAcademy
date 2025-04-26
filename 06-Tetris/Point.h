#pragma once
class Point
{
public:

	Point() { X = 0; Y = 0; }
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}
	int X;
	int Y;

	inline   Point& operator ==(Point& lhs)
	{
		if (this->X == lhs.X && this->Y == lhs.Y)
			return lhs;
		Point p(0, 0);

		return p;
	}

};