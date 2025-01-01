#include "BossView.h"
#include "Boss.h" // Include for Boss

BossView::BossView() {}

BossView::~BossView() {}

void BossView::draw(sf::RenderWindow& window, const Enemy& enemy) {
    const Boss& boss = dynamic_cast<const Boss&>(enemy);
    window.draw(boss.getSprite());
}