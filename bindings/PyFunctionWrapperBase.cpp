//hydra model

#pragma once

#include <FunctionWrapperBase.h>
#include <FunctionWrapper.h>
#include <Types.h>
#include <initializer_list>


#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>

using namespace model;

template class FunctionWrapper<0>;
template class FunctionWrapper<1>;

template class FunctionWrapperBase<FunctionWrapper<0>, double, 0>;
template class FunctionWrapperBase<FunctionWrapper<1>, double, 1>;

typedef FunctionWrapperBase<FunctionWrapper<0>, double, 0> FunctorN0_t;
typedef FunctionWrapperBase<FunctionWrapper<1>, double, 1> FunctorN1_t;

typedef FunctionWrapperBase< FunctionWrapper<0>, double, 0> FunctionWrapperBaseN0;
typedef FunctionWrapperBase< FunctionWrapper<1>, double, 1> FunctionWrapperBaseN1;

namespace py = pybind11;

PYBIND11_MODULE(PyHydraModel, m) {


    py::class_<FunctorN1_t>(m,"FunctorN1")
		.def( py::init<std::array<double,1> const&>() )
		.def("getPar", &FunctorN1_t::GetPar)
		.def("setPar", &FunctorN1_t::SetPar)
		.def("__call__", [](FunctorN1_t const& wrapper, py::array_t<double> const& input)
						{ return wrapper(input.data()); } );

   // return m.ptr();
}
