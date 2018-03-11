#include <boost/python.hpp>
#include <python2.7/Python.h>
#include <iostream>
#include "util.hpp"

namespace py = boost::python;

int main() {
    Py_Initialize();
    py::object main_module = py::import("__main__");
    py::object main_namespace = main_module.attr("__dict__");

    try {
        py::object result = py::exec("print('inside cpp code')", main_namespace);
    } catch (py::error_already_set const &) {
        std::string perror_str = parse_python_exception();
        std::cout << "Error occured:" << std::endl << perror_str << std::endl;
    }

    return 0;
}


