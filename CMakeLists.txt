cmake_minimum_required(VERSION 2.8.12)
project(fwdpy11_general_demography)
find_package(pybind11)
message(STATUS "Found pybind11: ${pybind11_VERSION}")
if(${pybind11_VERSION} VERSION_LESS '2.2.3')
    message(FATAL_ERROR "pybind11 version must be >= '2.2.3'")
endif()

find_package(GSL REQUIRED)
message(STATUS "GSL headers in ${GSL_INCLUDE_DIRS}")
include_directories(BEFORE ${GSL_INCLUDE_DIRS})

execute_process(COMMAND ${PYTHON_EXECUTABLE} -m fwdpy11 --fwdpy11_headers OUTPUT_VARIABLE FWDPY11_HEADER_LOCATION
    RESULT_VARIABLE RETCODE)
if (NOT ${RETCODE} STREQUAL "0")
    message(FATAL_ERROR "fwdpy11 headers could not be found")
else()
    message(STATUS "Found fwdpy11 headers in ${FWDPY11_HEADER_LOCATION}")
endif()
execute_process(COMMAND ${PYTHON_EXECUTABLE} -m fwdpy11 --fwdpp_headers OUTPUT_VARIABLE FWDPP_HEADER_LOCATION
    RESULT_VARIABLE RETCODE)
if (NOT ${RETCODE} STREQUAL "0")
    message(FATAL_ERROR "fwdpp headers could not be found")
else()
    message(STATUS "Found fwdpp headers in ${FWDPP_HEADER_LOCATION}")
endif()

include_directories(BEFORE headers ${FWDPY11_HEADER_LOCATION} ${FWDPP_HEADER_LOCATION} )

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

# These are the main modules
pybind11_add_module(evolve MODULE src/evolve.cc)
target_link_libraries(evolve PRIVATE GSL::gsl GSL::gslcblas)
pybind11_add_module(demography MODULE src/demography.cc)

