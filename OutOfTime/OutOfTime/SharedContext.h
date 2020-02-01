#pragma once

#include "ResourceHolder.h"

struct SharedContext {
	const ResourceHolder<TextureId,sf::Texture> &texHolder;
	const ResourceHolder<FontId,   sf::Font>    &fontHolder;
	const ResourceHolder<MusicId,  sf::Music>   &musicHolder;
	const ResourceHolder<SoundId,  sf::Sound>   &soundHolder;
};