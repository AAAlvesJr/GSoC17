/*
 * Algorithm.h
 *
 *  Created on: 9 de jun de 2017
 *      Author: augalves
 */

#ifndef INCLUDE_ALGORITHM_H_
#define INCLUDE_ALGORITHM_H_

#include <algorithm>

namespace model {

template<typename ITERATOR, typename FUNCTOR>
void algorithm(ITERATOR begin, ITERATOR end, FUNCTOR const& functor )
{
	 std::for_each(begin, end, functor);
};

}  // namespace model



#endif /* INCLUDE_ALGORITHM_H_ */
