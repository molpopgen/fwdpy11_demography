Experimental repository
--------------------------------------------------

This is a WIP to generalize demographic modeling capability in fwdpy11.

Requirements
++++++++++++++++++++++++++++++

* fwdpy11 0.2.0, which is currently the dev_015 branch
* pybind11, with both cmake and python modules installed.  See below
* cmake

To install pybind11, use conda or, do it manually from a clone of the pybind11 repo:

.. code-block:: bash

    cmake -DPYBIND11_TEST=0 .
    sudo make install
    sudo pip install .


Building
++++++++++++++++++++++++++++++

To build in "release" mode:

.. code-block:: bash

    cmake -DCMAKE_BUILD_TYPE=Release .

If you do not have fwdpy11 installed in the "usual" places, prepend the location.  For example:

.. code-block:: bash

    PYTHONPATH=$HOME/src/fwpy11 cmake -DCMAKE_BUILD_TYPE=Release .

After the `cmake` step.

.. code-block:: bash

    make


Notes
++++++++++++++++++++++++++++++++++

We simply compile modules in-place using cmake. No pip-installing, etc., which we'll get when we merge this into
fwdpy11.  By default, cmake generates a debug build without optimizations.  To get a "release" build for benchmarking:

.. code-block:: bash

    cmake -DCMAKE_BUILD_TYPE=Release .

