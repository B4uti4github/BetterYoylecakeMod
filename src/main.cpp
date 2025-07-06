#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include <Geode/binding/GJGameLevel.hpp>

using namespace geode::prelude;

struct $modify(MyGJBaseGameLayer, GJBaseGameLayer) {
	void resetPlayer(){
		auto activworst = Mod::get()->getSettingValue<bool>("activate-worst-deaths");

		if (activworst == true){
			if (auto* theNode = CCDirector::sharedDirector()->getRunningScene()->getChildByID("PlayLayer")) {
				auto playLayer = typeinfo_cast<PlayLayer*>(theNode);
				float per = playLayer->getCurrentPercent();

				if (per >= (float)Mod::get()->getSettingValue<double>("Percent-of-the-f")) {
					yoyle2();
				};

				if (per < (float)Mod::get()->getSettingValue<double>("Percent-of-the-f")) {
					yoyle();
				};
			};
		} else {
			yoyle();
		}
		GJBaseGameLayer::resetPlayer();
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
	void yoyle2() {
		auto yoylecakeSpr = CCSprite::create("yoylecake2.png"_spr);
		
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
		FMODAudioEngine::sharedEngine()->playEffect("y-sfx2.mp3"_spr);
	}

    bool init() {
		if (!GJBaseGameLayer::init()) return false;

		return true;
    }
};
