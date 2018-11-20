#include <demography.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(demography, m)
{
    m.doc() = "Classes and functions related to demographic models.";

    py::class_<fwdpy11::reproduction>(m, "Reproduction",
                                      "ABC for reproduction classes");
}
