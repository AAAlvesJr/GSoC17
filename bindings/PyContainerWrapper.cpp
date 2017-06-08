/*
 * Container.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: augalves
 */


//model
#include <Types.h>
#include <Vector4R.h>

#include <initializer_list>
#include <array>
#include <array>

// pybind11
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

//namespaces
using namespace model;
namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<Vector4R>);

//bindings
PYBIND11_MODULE(HydraContainerWrapper, m) {

	py::class_<Vector4R>(m,"Vector4R")
		.def( py::init<>() )
		.def( py::init<double, double, double, double>() )
		.def( py::init<std::array<double, 4> const&>() )
		.def( py::init<Vector4R const&>() )
		.def("get", &Vector4R::get)
		.def("set", &Vector4R::set)
		.def("R",   &Vector4R::R)
		.def("__getitem__",[](Vector4R const& v, size_t i){ v.get(i);  } )
		.def("__setitem__",[](Vector4R& v, size_t i,double value ){ v.set(i,value);  } );

	py::bind_vector<std::vector<Vector4R>>(m, "VectorV4R");
}
