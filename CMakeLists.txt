cmake_minimum_required(VERSION 2.8.12)
project(fwdpy11_general_demography)
find_package(pybind11)
message(STATUS "Found pybind11: ${pybind11_VERSION}")
if(${pybind11_VERSION} VERSION_LESS '2.2.3')
    message(FATAL_ERROR "pybind11 version must be >= '2.2.3'")
endif()

# Get fwdpy11 includes -- a bit more tedious than it needs to be perhaps
execute_process(COMMAND bash get_fwdpy11_header_locations.sh OUTPUT_VARIABLE FWDPY11_HEADER_LOCATION)
execute_process(COMMAND bash get_fwdpp_header_locations.sh OUTPUT_VARIABLE FWDPP_HEADER_LOCATION)

find_package(GSL REQUIRED)
include_directories(BEFORE headers ${FWDPY11_HEADER_LOCATION} ${FWDPP_HEADER_LOCATION} )
message(STATUS "GSL headers in ${GSL_INCLUDE_DIRS}")
include_directories(BEFORE ${GSL_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

# These are the main modules
pybind11_add_module(evolve MODULE src/evolve.cc)
target_link_libraries(evolve PRIVATE GSL::gsl GSL::gslcblas)

