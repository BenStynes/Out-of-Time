#pragma once

#include "ResourceHolder.h"

struct SharedContext {
	const ResourceHolder<TextureId,sf::Texture> &texHolder;
	const ResourceHolder<FontId,   sf::Font>    &fontHolder;
	const ResourceHolder<SoundId,  sf::Sound>   &soundHolder;
};