/*
 * FunctionWrapperBase.h
 *
 *  Created on: 2 de jun de 2017
 *      Author: augalves
 */

#ifndef FUNCTIONWRAPPERBASE_H_
#define FUNCTIONWRAPPERBASE_H_

#include<initializer_list>
#include<Types.h>
#include <array>
namespace model {



/**
 * @brief      Class for function wrapper base.
 *
 * @tparam     FunctorType  { type of the functor }
 * @tparam     ReturnType   { return type }
 * @tparam     N            { number of parameters }
 */
template<typename FunctorType, typename ReturnType, size_t N>
class FunctionWrapperBase {

public:

	/**
	 * @brief      default constructor
	 */
	FunctionWrapperBase()=delete;
    /*{

		for (size_t i = 0; i < N; i++)
			fPars[i] = 0 ;

	}*/

	/**
	 * @brief      {par...} constructor
	 *
	 * @param      list  The list
	 */
	FunctionWrapperBase(std::initializer_list<double> const& list) {

		for (size_t i = 0; i < N; i++)
			fPars[i] = *(list.begin() + i) ;
	}

	/**
		 * @brief      {par...} constructor
		 *
		 * @param      list  The list
		 */
	FunctionWrapperBase(std::array<double,N> const& list) {

			for (size_t i = 0; i < N; i++)
				fPars[i] = *(list.begin() + i) ;
		}


	/**
	 * @brief      { function_description }
	 *
	 * @param      other  The other
	 */
	FunctionWrapperBase(FunctionWrapperBase<FunctorType, ReturnType, N> const& other ) {

		for (size_t i = 0; i < N; i++)
			this->fPars[i] = other.GetPar(i);
	}



	//virtual ~FunctionWrapperBase(){};

	/**
	 * @brief      Gets the pars.
	 *
	 * @return     The pars.
	 */
	const double GetPar(size_t i) const {
		return this->fPars[i];
	}

	/**
	 * @brief      Sets the par.
	 *
	 * @param[in]  i      { parameter_description }
	 * @param[in]  value  The value
	 */
	void SetPar(size_t i, double value) {
		this->fPars[i] = value;
	}

	/**
	 * function call operator
	 */
	template<typename T> inline ReturnType operator()(const T* data) const  {

		return static_cast<const FunctorType*>(this)->eval(N, fPars, data);
	}
private:


	double fPars[N]; //! parameters
	                  

};


} /* namespace model */

#endif /* FUNCTIONWRAPPERBASE_H_ */
