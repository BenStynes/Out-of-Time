#include "BaseScene.h"

class GameScene final : public BaseScene {
public:
	GameScene(SceneManager& sceneManager, const SceneType sceneType);

	void handleEvents(const sf::Event& event);
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void onEnter() override;
	void onExit() override;

private:
};