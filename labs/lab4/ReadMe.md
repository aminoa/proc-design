# NYU ProcDesign Development Template

- A registry contains information of packages which is accessed through the vcpkg-configuration.json file - contains locations for obtaining packages. 
- A package is a source code file that is used in our project
- An library is a collection of code written to provide some functionality; an interface library allows for code/files that aren't immediately compiled. An example would be [this](https://github.com/retrage/gpt-macro), which compiles itself while it still is receiving input.
- A top module is some file used that need to be exposed for simulation. 