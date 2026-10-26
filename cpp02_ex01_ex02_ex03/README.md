# 42 CPP Module 02 — ex01, ex02, ex03

Complete C++98 implementations based on the supplied subject (version 9.1).
Each exercise is self-contained (its own `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, and `Makefile`).

## Compile and run

```sh
cd ex01 && make && ./fixed
cd ../ex02 && make && ./fixed
make test               # additional operator-overload assertions
cd ../ex03 && make && ./bsp
```

Use `make fclean` to clean binaries and object files in each directory.

## What each exercise implements

- **ex01:** two conversion constructors, `toFloat()`, `toInt()`, and output-stream `operator<<`.
- **ex02:** comparison/arithmetic/increment operators and const/non-const `min`/`max`.
- **ex03:** immutable `Point` with `const Fixed` coordinates and strict-inclusion `bsp()` for a triangle.

## Important implementation notes

- `Fixed` is represented as `raw / 256` with 8 fractional bits. Floating-point conversion rounds with `roundf()`.
- The `Fixed` `*` and `/` operators use the public `toFloat()` + floating-point constructor, as typically done in this learning exercise. The result is quantized back to 1/256.
- `Point` contains **const** coordinates, as the subject explicitly requires. They cannot be reassigned. Its publicly declared canonical copy-assignment operator is a no-op to retain the required interface; **do not use `p = q` to change the coordinates**. Use copy construction to create a new point instead. This is an inherent tension in the exercise specification.
- `bsp()` uses `double` for the 2D cross products to avoid rounding cross products to the 1/256 grid, excluding edges and vertices through strict comparisons. This is numerically reliable for ordinary exercise-scale coordinates, not an exact-arithmetic geometry implementation for extreme values.
- Like the subject, `Fixed` assumes values and operations stay in the representable 32-bit raw range. C++ signed overflow and float-to-int conversions beyond range are not handled.
