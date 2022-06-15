# printf (school 21 project)

Just library with simple replica of the printf C function.

### How it works

it works just as usual printf (https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm).
It handles : **``%c %s %p %d %u %x %X``** specifiers and **``DOES NOT HANDLE: FLAGS WIDTH PRECISION AND LENGTH``**


### How to use

First things first you need to make the libftprintf.a.

All of makefile rules:

| Rule | Function |
| - | - |
| ``make`` | Generete game without enemies |
| ``make all`` | Same as just make |
| ``make clean`` | Deletes all object files |
| ``make fclean`` | Deletes the object files and the _libftprintf.a_ file |
| ``make re`` | makes ``fclean`` and ``make`` again |
