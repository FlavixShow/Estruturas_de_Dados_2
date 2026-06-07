#ifndef MACRO_H
#define MACRO_H

#define new(TYPE, ...) new_##TYPE(__VA_ARGS__)

#endif
