/*
 * Container.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: augalves
 */


//model
#include <Types.h>

//std
#include <initializer_list>
#include <array>

// pybind11
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>


//namespaces
using namespace model;
namespace py = pybind11;


//bindings
PYBIND11_MODULE(HydraContainerWrapper, m) {

	py::class_<Vector4R>(m,"Vector4R")
		.def( py::init<>() )
		.def( py::init<double, double, double, double>() )
		.def( py::init<std::array<double, 4> const&>() )
		.def("get", &Vector4R::get)
		.def("set", &Vector4R::set)
		.def("R", &Vector4R::set)
		.def("__getitem__",[](Vector4R const& v){  } )
		.def("__setitem__",);
}
