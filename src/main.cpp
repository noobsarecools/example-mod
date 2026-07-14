#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(MyLayoutMod, CreatorLayer) {
    bool init() {
        // 1. Load the normal Creator Layer first
        if (!CreatorLayer::init()) return false;

        // 2. Find the menu grid where game buttons live
        auto menu = this->getChildByID("creator-buttons-menu");
        
        // 3. Create your custom layout button (Uses the Blue Spark sprite frame)
        auto btnSprite = CCSprite::createWithSpriteFrameName("GJ_downloadsBtn_001.png");
        auto myButton = CCMenuItemSpriteExtra::create(
            btnSprite, 
            this, 
            menu_selector(MyLayoutMod::onOpenLayouts)
        );
        
        // 4. Attach the button to the menu and space everything nicely
        menu->addChild(myButton);
        menu->updateLayout();
        return true;
    }

    // 5. When clicked, load your custom list of layout IDs right into GD!
    void onOpenLayouts(CCObject* sender) {
        // --- PUT YOUR RATED LEVEL IDS IN THE QUOTES BELOW SEPARATED BY COMMAS ---
        std::string myRatedLevels = "10234567,9876543,55443322"; 

        auto searchObject = GameLevelManager::sharedState()->getSearchObject(SearchType::Custom, myRatedLevels);
        auto searchLayer = LevelSearchLayer::create(searchObject);
        CCDirector::sharedDirector()->getRunningScene()->addChild(searchLayer);
    }
};
