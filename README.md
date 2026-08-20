# freestd

Custom standard library for C++ to make the language more pleasant, explicit, and predictable.

## Notes

The motivation for freestd is to have a much more beautiful, and better (in my opinion) C++ standard
library.

I like C++, but the standard library does not feel great at all. I want to use C++ without hating
its standard library.

I do not claim that my library could replace even ten percent of the C++ standard library. That is
just my personal project, only made for my own interest and learning. In the future, I hope I will
continue developing this library, and one day it is going to be actually useful for some programs.

## Limitations

All limitations presented here will not be addressed directly. Some of them have or will have
solutions in form of alternatives to original features, but there will never be support for their
direct usage. Any user of the library is free to implement the core, needed for any of those
features to work.

### Hardcoded features

The C++ language features and its standard library are too tied. There are many core language
features that require standard library support. A non-exhaustive list of some of the most used
features, backed by stdlib, is present below.

#### `nullptr`

The `nullptr` keyword denotes rvalue of type `std::nullptr_t`. Idiomatically, for pointers which can
be `NULL`, `freestd::core::Option<T*>` type should be used. When a pointer is needed to become a
`NULL` pointer, the assignment of `freestd::core::None` to `freestd::core::Option<T*>` variable or
member will do what is needed. Usage of `freestd::core::Option<T*>` introduces some runtime
overhead, but for non performance-critical software the cost is cheap.

#### `sizeof`

The result of a `sizeof` expression is constant expression of type `std::size_t`. Apparently, there
is no way around that limitation. The `sizeof` operator is just irreplaceable in some cases, and so
code will still contain `std::size_t` in it - at least on compiler level.

#### exceptions

Exceptions require special functions to be defined (they are compiler-specific, which makes it even
worse). Usage of exceptions with freestd is not recommended, because the library is build around
`freestd::core::Result<T, E>`. As in case with `freestd::core::Option<T*>`, freestd approach
introduces some runtime overhead, which again is cheap for most of the software, considering the
advantages of it. When a program is demanded to have the absolute best performance, implementing the
things required for exceptions or using different approaches is advised.

#### RTTI (Run-Time Type Information)

RTTI requires special functions to be defined. Without RTTI you cannot use `typeid` and
`dynamic_cast` keywords. Realistically, the `typeid` keyword does not have any purpose other than
just getting string representation of a type. The string representation is not even reliable, as
`std::type_info` object returned by `typeid` is not required by the standard to return anything
meaningful from its `name` member function. In practice, `std::type_info::name()` returns some
string in implementation defined format. The `dynamic_cast` operator is used to cast pointers up,
down and sideways in the inheritance hierarchy with runtime checks. `dynamic_cast` is mostly needed
in projects with strong Object Oriented nature. When using freestd in an application code, idiomatic
ways would be prefering composition over inheritance, and sticking with Data Oriented Design, rather
than Object Oriented paradigm. In addition, C++20 concepts present a strategy to move away from
defining interfaces as abstract classes, and even reduce runtime overhead by preventing the use of
inheritance. Finally, diamond inheritance is problematic without RTTI.

#### brace-enclosed initializer list deduction

Automatic deduction from brace-enclosed lists is a very convenient feature, but unfortunately it
requires `std::initializer_list` to be defined. In the future, there might be some alternative to
`std::initializer_list` in freestd, but obviously, this type will have to be specified explicitly.

### Compiler flags

There are some issues with compiler flags. Some of them require stdlib support, too. The most basic
one is stack protector. Stack protector is a compiler security feature for which some special
functions are needed to be defined. The problem is that stack protector is enabled by default,
though. The simplest solution for non-professional projects world be to compile code with
`-fno-stack-protector` to disable the stack protector completely.

### Other issues

Another issue that is present in C++ is compiler generating `memcmp`, `memset`, `memcpy` and
`memmove` calls even when using `-fno-builtin` to disable optimizations for well known functions. I
consider this behavior confusing, although its stated in the compilers manuals and probably in the
standard that it is the expected behavior. A simple solution might be to link your program with
libc. More advanced solution would be to implement the needed functions. I have a little observation
regarding this problem. All examples I have made for freestd can be built fine with gcc - it never
generated calls to any of those four functions. On the other hand, clang seems not to be able to
build even the smallest programs without generating the unwanted calls.
