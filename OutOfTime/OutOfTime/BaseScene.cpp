#include "BaseScene.h"
#include "SceneManager.h"

BaseScene::BaseScene(SceneManager& sceneManager, const SceneType sceneType, const bool isTransparent)
    : m_sceneManager  { sceneManager  }
    , m_sceneType     { sceneType }
    , m_isTransparent { isTransparent } {
}

BaseScene::~BaseScene() {
}

bool BaseScene::isTransparent() {
    return m_isTransparent;
}

SceneType BaseScene::getSceneType() const{
    return m_sceneType;
}

void BaseScene::requestPushScene(const SceneType sceneType) const {
    m_sceneManager.requestPushScene(sceneType);
}

void BaseScene::requestRemoveCurrentScene() const {
    m_sceneManager.requestRemoveCurrentScene();
}

void BaseScene::requestRemoveAllScenes() const {
    m_sceneManager.requestRemoveAllScenes();
}