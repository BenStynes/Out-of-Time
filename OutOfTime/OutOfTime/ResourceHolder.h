#pragma once

#include <map>
#include <memory>
#include <cassert>
#include <iostream>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

enum class TextureId {
	kTitle,
	kGameBackground
};

enum class SoundId {
	kJump,
};

enum class MusicId {
	kTitle,
};

enum class FontId {
	kRoboto,
};

template <typename ResourceID, typename Resource>
class ResourceHolder {
public:
	void load(const ResourceID id, const std::string& filename) {
		std::unique_ptr<Resource> resource = std::make_unique<Resource>();
		if (resource->loadFromFile(filename)) {
			m_resourceHolder[id] = std::move(resource);
			std::cout << filename << " Texture Loaded\n";
		}
	}

	const Resource& get(ResourceID id) const {
		const auto found = m_resourceHolder.find(id);
		assert(found != m_resourceHolder.end());
		return *found->second;
	}

private:
	std::map<ResourceID, std::unique_ptr<Resource>> m_resourceHolder;
};
