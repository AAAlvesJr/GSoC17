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
	Vector3R(){};

	Vector3R(double x, double y, double z, double w )
	{
		fCoords[0]=x;
		fCoords[1]=y;
		fCoords[2]=z;
		fCoords[3]=w;
	};

	Vector3R(std::array<double,4> const& coords) {

				for (size_t i = 0; i < N; i++)
					fCoords[i] = coords[i];
	}

	const double getCoord(size_t i) const {
		return fCoords[i];
	}

	double setCoord(size_t i, double value) {
		return fCoords[i]=value;
	}

	const double getR() const {
		double r=0;
		for(size_t i=0; i<4; i++)r +=fCoords[i];
		return sqrt(r);
	}


private:
	double fCoords[4];
};

} /* namespace model */

#endif /* INCLUDE_VECTOR3R_H_ */
