#pragma once
#include <iostream>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SharedContext.h"
#include "SceneTypes.h"

class SceneManager;

class BaseScene {
public:
    BaseScene(SceneManager& sceneManager, const SceneType m_sceneType, const bool isTransparent = false);
    virtual ~BaseScene();

	virtual void handleEvents(const sf::Event& event) = 0;
    virtual void update(const sf::Time deltaTime)  = 0;
    virtual void render(sf::RenderWindow& window)  = 0;
    virtual void onEnter() = 0;
    virtual void onExit()  = 0;

    bool isTransparent();
    SceneType getSceneType() const;

protected:
	const SharedContext& getSharedContext() const;
    void requestPushScene(const SceneType sceneType) const;
    void requestRemoveCurrentScene() const;
    void requestRemoveAllScenes() const;

private:
    SceneManager& m_sceneManager;
    SceneType m_sceneType;
    bool m_isTransparent;
};