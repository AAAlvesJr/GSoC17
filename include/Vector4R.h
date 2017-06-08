/*
 * Vector3R.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: augalves
 */

#ifndef INCLUDE_VECTOR4R_H_
#define INCLUDE_VECTOR4R_H_

#include<cmath>

namespace model {

class Vector4R {
public:

	Vector4R() {};


	Vector4R(double x, double y, double z, double w) {
		fCoords[0] = x;	fCoords[1] = y;
		fCoords[2] = z;	fCoords[3] = w;
	}


	Vector4R(std::array<double, 4> const& coords) {
		for (size_t i = 0; i < 4; i++)
			fCoords[i] = coords[i];
	}

	Vector4R(Vector4R const& other){

		if(this==&other) return ;

		for(size_t i=0; i<4; i++)
			this->set(i, other.get(i));

			return;
	}

	const double get(size_t i) const {
		return fCoords[i];
	}

	void set(size_t i, double value) {
	       fCoords[i] = value;
	}

	const double R() const {
		double r = 0;
		for (size_t i = 0; i < 4; i++)
			r += fCoords[i];
		return sqrt(r);
	}

	Vector4R& operator+=( Vector4R const& other){

		for(size_t i=0; i<4; i++)
		this->set(i, other.get(i));

		return *this;
	}

private:
	double fCoords[4];
};

Vector4R operator+(Vector4R one,  Vector4R const& another){
	one += another;
	return one;
}

} /* namespace model */

#endif /* INCLUDE_VECTOR4R_H_ */
