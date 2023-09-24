# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-src"
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-build"
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix"
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix/tmp"
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp"
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src"
  "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/aneesh/proc-design/labs/lab2/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
