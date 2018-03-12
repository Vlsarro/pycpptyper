#include <boost/python.hpp>
#include <python2.7/Python.h>
#include <iostream>
#include "util.hpp"

namespace py = boost::python;

template <typename T> T extract_val(py::object& obj) {
    T val = py::extract<T>(obj);
    return val;
}

int main() {
    Py_Initialize();
    py::object main_module = py::import("__main__");
    py::object main_namespace = main_module.attr("__dict__");

    try {
        py::object typer_module = import("typer", "typer.py", main_namespace);
        py::object typer_ins = typer_module.attr("Typer")();

        py::object val = typer_ins.attr("identify")(6);
        int cpp_int_val = extract_val<int>(val);
        std::cout << "Int value inside cpp: " << cpp_int_val << std::endl;

        py::object str_val = typer_ins.attr("identify")("saywhat");
        std::string cpp_str_val = extract_val<std::string>(str_val);
        std::cout << "String value inside cpp: " << cpp_str_val << std::endl;
    } catch (py::error_already_set const &) {
        std::string perror_str = parse_python_exception();
        std::cout << "Error occured:" << std::endl << perror_str << std::endl;
    }

    return 0;
}


