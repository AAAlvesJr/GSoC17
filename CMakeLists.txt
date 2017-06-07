cmake_minimum_required(VERSION 2.8)

project(PyHydraModel)

set(PYBIND11_CPP_STANDARD -std=c++11)
set(PYBIND11_PYTHON_VERSION 2.7)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include)


add_subdirectory(pybind11)
pybind11_add_module(HydraFunctionWrapper bindings/PyFunctionWrapper.cpp)
pybind11_add_module(HydraContainerWrapper bindings/PyContainerWrapper.cpp)

