// header file with point definition 

#ifndef POINT_HPP
#define POINT_HPP

namespace point {
	class Point {
	public:
		float x;
		float y;

		Point() {}
		Point(float x_, float y_) : x(x_), y(y_) {}
	};
}

#endif
