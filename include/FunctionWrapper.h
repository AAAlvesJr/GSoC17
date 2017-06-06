/*
 * FunctionWrapper.h
 *
 *  Created on: 2 de jun de 2017
 *      Author: augalves
 */

#ifndef FUNCTIONWRAPPER_H_
#define FUNCTIONWRAPPER_H_

#include <initializer_list>
#include <array>
#include "Types.h"
#include "FunctionWrapperBase.h"

namespace model {

/**
 * @brief      Class for function wrapper.
 *
 * @tparam     N     { number of parameters (N>0) }
 */
template<size_t N>
class FunctionWrapper: public FunctionWrapperBase<FunctionWrapper<N>, double, N> {
public:


    FunctionWrapper() = delete;

    /**
     * @brief      { function_description }
     *
     * @param      fptr  The fptr
     * @param      list  The list
     */
    FunctionWrapper(ParametricFunction_t const& fptr, std::initializer_list<double> const& list):
        FunctionWrapperBase<FunctionWrapper<N>, double, N>(list),
        fFunctor(fptr)
    {}

    FunctionWrapper(ParametricFunction_t const& fptr, std::array<double,N> const& list):
          FunctionWrapperBase<FunctionWrapper<N>, double, N>(list),
          fFunctor(fptr)
    {}

    FunctionWrapper(ParametricFunctor_t const& fctor, std::array<double,N> const& list):
            FunctionWrapperBase<FunctionWrapper<N>, double, N>(list),
            fFunctor(fctor)
      {}


    /**
     * @brief      { function_description }
     *
     * @param      other  The other
     */
    FunctionWrapper(FunctionWrapper<N> const& other):
        FunctionWrapperBase<FunctionWrapper<N>, double, N>(other),
        fFunctor(other.GetFunctor())
    {}


    /**
     * @brief      Gets the functor.
     *
     * @return     The functor.
     */
    ParametricFunctor_t GetFunctor() const {
        return fFunctor;
    }

    /**
     * @brief      Sets the functor.
     *
     * @param[in]  functor  The functor
     */
    void SetFunctor(ParametricFunctor_t functor) {
        fFunctor = functor;
    }


    double eval( const size_t n,  const double* p , const double* x ) const {
        return fFunctor(n, p, x);
    }

private:

    ParametricFunctor_t fFunctor;
};


} /* namespace model */


#endif /* FUNCTIONWRAPPER_H_ */
