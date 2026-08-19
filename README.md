# freestd

Custom standard library for C++ to make the language more pleasant, explicit and predictable.

## Notes

The motivation for freestd is to have much more beautiful and better (in my opinion) C++ standard
library.

I like C++, but the standard library does not feel great at all. I want to use C++ without hating
its standard library.

I do not claim that my library could replace even ten percent of C++ standard library. That is just
my personal opinionated project only made for own interest and learning. In future I hope I will
continue developing this library and one day it is going to be actually useful for some programs.

## Caveats

### Hardcoded features

C++ language features and standard library are too tied.
There are many core language features that require standard library support.
Non-complete list of some most popular 'hardcoded' features with some information is below.

#### `nullptr`

`nullptr` keyword denotes rvalue of type `std::nullptr_t`. Semantically you can use this in your
program. Idiomatically you should use `freestd::core::Option<T*>` and raw pointers should always
point to valid objects.

#### `sizeof`

The result of a `sizeof` expression is constant expression of type std::size_t. Unfortunately, I
don't think there is a way around that. `sizeof` operator is just irreplaceable in some cases, but
in freestd there will be no declaration/definition of any `std` member. So technically you can use
it but there is no support for `std::size_t` in freestd.

#### exceptions

Exceptions require special functions to be defined (they are compiler-specific, which makes it even
worse). I just dont recommend using exceptions with freestd, because all stdlib is build around
`freestd::core::Result<T, E>`. Obviously, freestd approach poses some runtime overhead. If you need
the absolute maximum efficiency of your program you can implement things required for exceptions
yourself.

#### rtti (run-time type information)

As in case with exceptions, this requires some special functions. Without this you cannot use
`typeid` keyword and `dynamic_cast`. Realistically, `typeid` keyword does not have any value other
than just getting string representation of a type. The string representation is not even reliable as
`typeid` is not required by the standard to return anything meaningful. In practice, `typeid`
returns some string in format chosen by compiler. `dynamic_cast` is needed to cast pointers up, down
and sideways in the inheritance hierarchy. This may only be needed in projects with strong Object
Oriented nature. Idiomatically, when using freestd you should prefer Data Oriented Design and using
C++20 concepts to virtual member functions in case you use OOP in C++ purely for interfaces. Also,
there are going to be problems with some uses of inheritance, which I did not study in depths.

#### brace-enclosed initializer list deduction

This may be very convenient, but unfortunately, it requires `std::initializer_list` to be defined.
In freestd there will be no support for constructing collections from `std::initializer_list`, but
may be there will be some alternative type to that, unfortunately without automatic deduction.

### Compiler flags

Also, there are some issues with compiler flags. Some flags also require library support. The most
basic one is stack protector. Its a compiler security feature for which some special functions are
required. I do not think freestd should have support for that. Its up to user to implement needed
functions, although stack protector is enabled by default. My solution for now is to compile with
`-fno-stack-protector` to disable this feature completely.

Another issue that is present is compiler generating `memcmp`, `memset`, `memcpy` and `memmove`
calls even when using `-fno-builtin`. I consider this behavior confusing, although its stated in the
compilers manuals and probably in the standard that it is the expected behavior. Simple solution may
be to link your program with libc, but you can always implement your own functions to compile your
programs without this issue. My little observation is that for simple programs I have never faced
gcc to generate calls to those four functions, but clang does it even for the simplest programs.
