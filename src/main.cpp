#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(BetterCreatorLayer, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

        // 1.
        if (auto creatorMenu = this->getChildByID("creator-buttons-menu")) {
            std::vector<std::string> mainButtonsToHide = {
                "top-lists-button",
                "versus-button",
                "map-button",
                "paths-button",
                "lists-button",
                "gauntlets-button",
                "map-packs-button",
                "fame-button"
            };

            for (const auto& id : mainButtonsToHide) {
                if (auto button = creatorMenu->getChildByID(id)) {
                    button->setVisible(false);
                }
            }

            // Sắp xếp lại các nút còn lại theo hàng ngang
            auto rowLayout = RowLayout::create();
            rowLayout->setGap(25.f);
            rowLayout->setAxisAlignment(AxisAlignment::Center);
            rowLayout->setCrossAxisAlignment(AxisAlignment::Center);

            creatorMenu->setLayout(rowLayout);
            creatorMenu->updateLayout();
        }

        // 2. Ẩn các menu sự kiện / nhiệm vụ ở góc phải (Daily, Event, Quests...)
        std::vector<std::string> sideMenusToHide = {
            "daily-menu",
            "weekly-menu",
            "event-menu",
            "quests-menu"
        };

        for (const auto& menuId : sideMenusToHide) {
            if (auto sideMenu = this->getChildByID(menuId)) {
                sideMenu->setVisible(false);
            }
        }

        // Kiểm tra thêm nếu các menu này nằm trong cụm top-right-menu của bản cập nhật mới
        if (auto topRightMenu = this->getChildByID("top-right-menu")) {
            for (const auto& menuId : sideMenusToHide) {
                if (auto sideMenu = topRightMenu->getChildByID(menuId)) {
                    sideMenu->setVisible(false);
                }
            }
            topRightMenu->updateLayout();
        }

        // 3
        if (auto bottomLeftMenu = this->getChildByID("bottom-left-menu")) {
            std::vector<std::string> vaultButtonsToHide = {
                "secret-vault-button",
                "treasure-room-button"
            };

            for (const auto& btnId : vaultButtonsToHide) {
                if (auto button = bottomLeftMenu->getChildByID(btnId)) {
                    button->setVisible(false);
                }
            }
            bottomLeftMenu->updateLayout();
        }

        return true;
    }
};
