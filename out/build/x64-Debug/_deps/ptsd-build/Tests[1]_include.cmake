if(EXISTS "E:/1School/OOPL/z_trytry/oopl_PTSD_pushBox/out/build/x64-Debug/_deps/ptsd-build/Tests[1]_tests.cmake")
  include("E:/1School/OOPL/z_trytry/oopl_PTSD_pushBox/out/build/x64-Debug/_deps/ptsd-build/Tests[1]_tests.cmake")
else()
  add_test(Tests_NOT_BUILT Tests_NOT_BUILT)
endif()
