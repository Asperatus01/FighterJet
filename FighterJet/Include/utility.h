#ifndef UTILITY_H
#define UTILITY_H

#include <sstream>
#include <string>


namespace sf
{
	class Sprite;
	class Text;
}

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include "utility.inl"
#endif // UTILITY_H

