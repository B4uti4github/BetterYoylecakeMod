#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
using namespace geode::prelude;

struct $modify(MyGJBaseGameLayer, GJBaseGameLayer) {
	void resetPlayer(){
		GJBaseGameLayer::resetPlayer();
		yoyle();
	}

	void yoyle() {
		auto yoylecakeSpr = CCSprite::create("yoylecake.png"_spr);
		
		auto winSize = CCDirector::get()->getWinSize();
		
		this->addChild(yoylecakeSpr);
		
		yoylecakeSpr->setOpacity(255);		

		float scaleRatio = (winSize.height / yoylecakeSpr->getContentSize().height);

		yoylecakeSpr->setScale(scaleRatio);

		yoylecakeSpr->setPosition({ winSize.width / 2, winSize.height / 2 });
		yoylecakeSpr->runAction(CCSequence::createWithTwoActions(
  			CCFadeOut::create(0.5),
			CCRemoveSelf::create()
		));
		FMODAudioEngine::sharedEngine()->playEffect("y-sfx.ogg"_spr);
	}

    bool init() {
		if (!GJBaseGameLayer::init()) return false;

		return true;
    }
};
