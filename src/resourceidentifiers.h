#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H

// Forward declaration of SFML classes
namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Tower,
		TowerCount,
		Map,
		TowerBar,
		Bloon,
		Bullet,
		TextureCount,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif // RESOURCEIDENTIFIERS_H
