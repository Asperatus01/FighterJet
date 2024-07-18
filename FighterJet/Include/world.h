#ifndef WORLD_H
#define WORLD_H

#include <resource_holder.h>
#include <resource_identifiers.h>
#include <scene_node.h>
#include <sprite_node.h>
#include <aircraft.h>
#include <command_queue.h>
#include <command.h>

#include <SFML/Graphics.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
	explicit                  World(sf::RenderWindow& window);
	void                      update(sf::Time dt);
	void                      draw();

	CommandQueue&             getCommandQueue();


private:
	void                      loadTextures();
	void                      buildScene();
	void                      adaptPlayerPosition();
	void                      adaptPlayerVelocity();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	sf::RenderWindow&                   mWindow;
	sf::View                            mWorldView;
	TextureHolder                       mTextures;

	SceneNode                           mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	CommandQueue                        mCommandQueue;

	sf::FloatRect                       mWorldBounds;
	sf::Vector2f                        mSpawnPosition;
	float                               mScrollSpeed;
	Aircraft*                           mPlayerAircraft;
};

#endif // WORLD_H

