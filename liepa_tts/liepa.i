%module liepa

%{
#define SWIG_FILE_WITH_INIT
#define SWIG_PYTHON_STRICT_BYTE_CHAR
#include <stdlib.h>
#include "liepa.h"
%}

%include "numpy.i"

%init %{
import_array();
%}

%apply (short * ARGOUT_ARRAY1, int DIM1) {(short * out, size_t outSize)};
%apply (int DIM1, short * IN_ARRAY1) {(size_t count, short * buff)};

%include "liepa.h"
