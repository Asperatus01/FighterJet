#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H

#include <sstream>
#include <string>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

#include "string_helpers.inl"
#endif 

