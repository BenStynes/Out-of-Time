#pragma once

#include <SFML/Window/Event.hpp>
#include <vector>
#include <functional>
#include <unordered_map>
#include "BaseScene.h"
#include "SceneTypes.h"

class SceneManager {
public:
    explicit SceneManager();

	void handleEvents(const sf::Event& event) const;
    void update(const sf::Time deltaTime) const;
    void render(sf::RenderWindow& window) const;
    void updateSceneChangeRequests();

    void requestPushScene(const SceneType sceneType);
    void requestRemoveCurrentScene();
    void requestRemoveAllScenes();
    bool isSceneStackEmpty() const;
    
    SceneType getCurrentScene() const;

    template <typename T> 
    void registerScene(const SceneType sceneType) {
        m_sceneFactory[sceneType] = [this, sceneType]() {
            return std::make_unique<T>(*this, sceneType);
        };
    }
    
private:
    using SceneChanges = std::vector<SceneChange>;
    using SceneStack   = std::vector<std::unique_ptr<BaseScene>>;
    using SceneFactory = std::unordered_map<SceneType, std::function<std::unique_ptr<BaseScene>(void)>>;
 
    SceneStack    m_sceneStack;
    SceneChanges  m_sceneChanges;
    SceneFactory  m_sceneFactory;

    void pushScene(const SceneType sceneType);
    void removeCurrentScene();
    void removeAllScenes();
};