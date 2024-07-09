#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Include/entity.h"
#include "Include/resource_identifiers.h"
#include <SFML/Graphics/Sprite.hpp>

class Aircraft : public Entity // inherits indirectly SceneNode(class Entity : public SceneNode)
{
public:
    enum Type
	{
		Eagle,
		Raptor,
	};
	Aircraft(Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Type mType;
	sf::Sprite mSprite;
};
#endif


