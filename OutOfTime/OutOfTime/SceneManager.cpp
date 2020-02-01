#include "SceneManager.h"

#include <algorithm>

#include "TitleScene.h"
#include "GameScene.h"
#include "GameoverScene.h"

SceneManager::SceneManager() { 
	registerScene<TitleScene>(SceneType::kTitle);
	registerScene<GameScene>(SceneType::kGame);
	registerScene<GameoverScene>(SceneType::kGameover);
	requestPushScene(SceneType::kTitle);
}

void SceneManager::handleEvents(const sf::Event& event) const {
	m_sceneStack.back()->handleEvents(event);
}

void SceneManager::update(const sf::Time deltaTime) const {
    m_sceneStack.back()->update(deltaTime);
}

// Allows Multi Scene rendering
void SceneManager::render(sf::RenderWindow& window) const {
	//m_sceneStack.back()->render(window);
    auto sceneItr = m_sceneStack.end();
    while (--sceneItr != m_sceneStack.begin() && (*sceneItr)->isTransparent());
    while (sceneItr != m_sceneStack.end()) {
        (*sceneItr)->render(window);
        ++sceneItr;
    }
}

void SceneManager::updateSceneChangeRequests() {
    for (const auto& sceneChange : m_sceneChanges) {
        switch (sceneChange.action) {
            case SceneAction::kPush:
                pushScene(sceneChange.type);
                break;
            case SceneAction::kPop:
                removeCurrentScene();
                break;
            case SceneAction::kClear:
                removeAllScenes();
                break;
        }
    }
    m_sceneChanges.clear();
}

void SceneManager::requestPushScene(SceneType sceneType) {
    m_sceneChanges.emplace_back(SceneChange { SceneAction::kPush, sceneType } );
}

void SceneManager::requestRemoveCurrentScene() {
    m_sceneChanges.emplace_back(SceneChange { SceneAction::kPop, SceneType::kNone } );
}

void SceneManager::requestRemoveAllScenes() {
    m_sceneChanges.emplace_back(SceneChange { SceneAction::kClear, SceneType::kNone });
}

bool SceneManager::isSceneStackEmpty() const{
    return m_sceneStack.empty();
}

SceneType SceneManager::getCurrentScene() const {
    return m_sceneStack.back()->getSceneType();
}

void SceneManager::pushScene(const SceneType sceneType) {
    // Check if scene has been registered in the scene factory
    if (const auto sfItr = m_sceneFactory.find(sceneType); sfItr != m_sceneFactory.end()) {
        // Check if scene already exists in the scene stack
        if (const auto sceneItr = std::find_if(m_sceneStack.begin(), m_sceneStack.end(), 
			[sceneType](const auto& scene) { return (scene->getSceneType() == sceneType);}); sceneItr == m_sceneStack.end()) 
		{
				m_sceneStack.emplace_back(sfItr->second());
				m_sceneStack.back()->onEnter();
        } 
		else {
			std::cout << "Scene already exists  \n";
		}
    } else {
		std::cout << "Scene not registered \n";
    }
}

void SceneManager::removeCurrentScene() {
    m_sceneStack.back()->onExit();
    m_sceneStack.pop_back();
}

void SceneManager::removeAllScenes() {
    while (!m_sceneStack.empty()) {
        m_sceneStack.back()->onExit();
        m_sceneStack.pop_back();
    }
    m_sceneStack.clear();
}