#include <imgui.h>
#include <module.h>
#include <gui/gui.h>

SDRPP_MOD_INFO{
    /* Name:            */ "radioastro_hl",
    /* Description:     */ "Custom radio astronomy module for hydrogen line observation",
    /* Author:          */ "Ahmad-Bamba",
    /* Version:         */ 0, 1, 0,
    /* Max instances    */ -1
};

class RadioAstroHL : public ModuleManager::Instance {
public:
    RadioAstroHL(std::string name) {
        this->name = name;
        gui::menu.registerEntry(name, menuHandler, this, NULL);
    }

    ~RadioAstroHL() {
        gui::menu.removeEntry(name);
    }

    void postInit() {}

    void enable() {
        enabled = true;
    }

    void disable() {
        enabled = false;
    }

    bool isEnabled() {
        return enabled;
    }

private:
    static void menuHandler(void* ctx) {
        RadioAstroHL* _this = static_cast<RadioAstroHL*>(ctx);
        ImGui::Text("Hello SDR++, my name is %s", _this->name.c_str());
    }

    std::string name;
    bool enabled = true;
};

MOD_EXPORT void _INIT_() {
    // Nothing here
}

MOD_EXPORT ModuleManager::Instance* _CREATE_INSTANCE_(std::string name) {
    return new RadioAstroHL(name);
}

MOD_EXPORT void _DELETE_INSTANCE_(void* instance) {
    delete instance;
}

MOD_EXPORT void _END_() {
    // Nothing here
}
