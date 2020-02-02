#include "BaseScene.h"
#include "Clock.h"
#include "Gear.h"
class GameScene final : public BaseScene {
public:
	GameScene(SceneManager& sceneManager, const SceneType sceneType);

	void handleEvents(const sf::Event& event);
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void onEnter() override;
	void onExit() override;
	void initialiseGears();


private:
	Clock m_clock;
	sf::Vector2f m_mousePos;
	bool inRightPos = false;

	int m_retries{ 3 };
	Gear allGears[9];
	sf::Music m_music;
	sf::Sprite m_sprite;
	sf::Text winText;
};