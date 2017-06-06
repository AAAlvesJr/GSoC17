//hydra model

#pragma once

//model
#include <FunctionWrapperBase.h>
#include <FunctionWrapper.h>
#include <Types.h>

//std
#include <initializer_list>
#include <array>

// pybind11
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>

//macro to instantiate and typedef the parameters
#define WRAPPER_INSTANCES(N)\
	template class model::FunctionWrapper<N>;\
	template class model::FunctionWrapperBase<model::FunctionWrapper<N>, double, N>;\
	typedef  model::FunctionWrapperBase<model::FunctionWrapper<N>, double, N> functor_base_##N##_t;\
    typedef  model::FunctionWrapper<N> functor_##N##_t;\

WRAPPER_INSTANCES(0) //0 parameter
WRAPPER_INSTANCES(1) //1 parameter
WRAPPER_INSTANCES(2) //2 parameters
WRAPPER_INSTANCES(3) //3 parameters

//namespaces
using namespace model;
namespace py = pybind11;

//bindings
PYBIND11_MODULE(PyHydraModel, m) {

	py::class_<functor_base_1_t>(m,"FunctorBase1")
			.def( py::init<std::array<double,1> const&>() )
			.def("getPar", &functor_base_1_t::GetPar)
			.def("setPar", &functor_base_1_t::SetPar)
			.def("__call__", [](functor_base_1_t const& wrapper, py::array_t<double, py::array::c_style> const& input)
							{ return wrapper(input.data()); } );

    py::class_<functor_1_t,functor_base_1_t>(m,"Functor1")
		.def( py::init<ParametricFunctor_t const&, std::array<double,1> const&>() )
		.def("getPar", &functor_1_t::GetPar)
		.def("setPar", &functor_1_t::SetPar)
		.def("__call__", [](functor_1_t const& wrapper, py::array_t<double, py::array::c_style> const& input)
						{ return wrapper(input.data()); } );

}
