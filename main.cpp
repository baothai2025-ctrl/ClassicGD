#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

        if (auto creatorMenu = this->getChildByID("creator-buttons-menu")) {
            std::vector<std::string> mainButtonsToRemove = {
                "top-lists-button",
                "versus-button",
                "map-button",
                "paths-button",
                "lists-button",
                "gauntlets-button",
                "map-packs-button",
                "fame-button"
            };

            for (const auto& id : mainButtonsToRemove) {
                if (auto button = creatorMenu->getChildByID(id)) {
                    button->removeFromParentAndCleanup(true);
                }
            }

            auto rowLayout = RowLayout::create();
            rowLayout->setGap(25.f);
            rowLayout->setAxisAlignment(AxisAlignment::Center);
            rowLayout->setCrossAxisAlignment(AxisAlignment::Center);

            creatorMenu->setLayout(rowLayout);
            creatorMenu->updateLayout();
        }

        std::vector<std::string> sideMenusToRemove = {
            "daily-menu",
            "event-menu",
            "quests-menu"
        };

        for (const auto& menuId : sideMenusToRemove) {
            if (auto sideMenu = this->getChildByID(menuId)) {
                sideMenu->removeFromParentAndCleanup(true);
            }
        }

        if (auto bottomLeftMenu = this->getChildByID("bottom-left-menu")) {
            std::vector<std::string> vaultButtonsToRemove = {
                "secret-vault-button",
                "treasure-room-button"
            };

            for (const auto& btnId : vaultButtonsToRemove) {
                if (auto button = bottomLeftMenu->getChildByID(btnId)) {
                    button->removeFromParentAndCleanup(true);
                }
            }
            bottomLeftMenu->updateLayout();
        }

        return true;
    }
};

