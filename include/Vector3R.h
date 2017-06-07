/*
 * Vector3R.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: augalves
 */

#ifndef INCLUDE_VECTOR3R_H_
#define INCLUDE_VECTOR3R_H_

#include<cmath>

namespace model {

class Vector3R {
public:

	Vector3R() {};


	Vector3R(double x, double y, double z, double w) {
		fCoords[0] = x;	fCoords[1] = y;
		fCoords[2] = z;	fCoords[3] = w;
	}


	Vector3R(std::array<double, 4> const& coords) {
		for (size_t i = 0; i < N; i++)
			fCoords[i] = coords[i];
	}

	const double get(size_t i) const {
		return fCoords[i];
	}

	void set(size_t i, double value) {
		return fCoords[i] = value;
	}

	const double R() const {
		double r = 0;
		for (size_t i = 0; i < 4; i++)
			r += fCoords[i];
		return sqrt(r);
	}

	Vector3R& operator+=( Vector3R const& other){

		for(size_t i=0; i<4; i++)
		this->setCoord(i, other.getCoord(i));

		return *this;
	}

private:
	double fCoords[4];
};

Vector3R operator+(Vector3R one,  Vector3R const& another){
	one += another;
	return one;
}

} /* namespace model */

#endif /* INCLUDE_VECTOR3R_H_ */
