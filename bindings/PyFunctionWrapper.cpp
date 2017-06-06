//hydra model
#include <FunctionWrapper.h>
#include <Types.h>

//boost.python
#include <boost/python.hpp>
using namespace boost::python;
using namespace model;




BOOST_PYTHON_MODULE(PyHydraModule)
{
	
	typedef FunctionWrapper<0> FunctionWrapperN0;
	typedef FunctionWrapperBase<FunctionWrapper<0>, double, 0> FunctionWrapperBaseN0;
    typedef FunctionWrapper<1> FunctionWrapperN1;
	typedef FunctionWrapperBase<FunctionWrapper<1>, double, 1> FunctionWrapperBaseN1;

   	class_<FunctionWrapperN1, bases<FunctionWrapperBaseN1> >("Functor1", init< ParametricFunction_t, std::initializer_list<double> >)
	.def(init<FunctionWrapperN1>)
	.def("getFunctor", &FunctionWrapperN1::GetFunctor)
	.def("setFunctor", &FunctionWrapperN1::SetFunctor)
	;

}
