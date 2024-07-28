#ifndef TEXT_NODE_H
#define TEXT_NODE_H

#include <resource_holder.h>
#include <resource_identifiers.h>
#include <scene_node.h>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class TextNode : public SceneNode
{
public:
	explicit			TextNode(const FontHolder& fonts, const std::string& text);

	void				setString(const std::string& text);

private:
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text			mText;
};

#endif // TEXT_NODE_H

