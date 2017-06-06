/*
 * types.h
 *
 *  Created on: 2 de jun de 2017
 *      Author: augalves
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <functional>

namespace model {


typedef double(*Function_t)( const double*);
typedef std::function<double( const double*)> Functor_t;

typedef double(*ParametricFunction_t)( const size_t, const double*, const double*);
typedef std::function<double( const size_t, const double*, const double*)> ParametricFunctor_t;

}  // namespace model

#endif /* TYPES_H_ */
