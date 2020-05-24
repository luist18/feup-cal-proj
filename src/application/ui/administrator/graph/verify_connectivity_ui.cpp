#include "verify_connectivity_ui.h"
#include "../../../../util/algorithm/algorithm.h"

VerifyConnectivityUI::VerifyConnectivityUI(UIManager &uiManager) : uiManager(uiManager) {}

void VerifyConnectivityUI::run() {
    std::cout << uiManager.getHeader() << std::endl;

    std::cout << "Calculating connectivity..." << std::endl;
    bool connected = algorithm::isDenselyConnected(uiManager.getCompany().getGraph(), true);
    std::cout << "The world graph is ";
    if (!connected)
        std::cout << "not ";
    std::cout << "densely connected!" << std::endl;

    ui_util::displayPlaceholder();
}
