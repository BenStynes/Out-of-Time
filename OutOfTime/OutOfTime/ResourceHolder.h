#pragma once

#include <map>
#include <memory>
#include <cassert>
#include <iostream>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

enum TextureId {
	kTitle,
	kGameBackground,

	kBSOne,
	kBSTwo,
	kBSThree,
	kBSFour,

	kCWOne,
	kCWTwo,
	kCWThree,
	kCWFour,

	kFWOne,
	kFWTwo,
	kFWThree,
	kFWFour,

	kMSOne,
	kMSTwo,
	kMSThree,
	kMSFour,

	kTWOne,
	kTWTwo,
	kTWThree,
	kTWFour
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
			std::cout << filename << " Resource Loaded\n";
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
