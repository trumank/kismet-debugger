#include <string>
#include <stdio.h>

#include <GUI/GUITab.hpp>
#include <Mod/CppUserModBase.hpp>
#include <UE4SSProgram.hpp>
#include <KismetDebugger.hpp>

class MyTestTab : public GUI::GUITab
{
private:
    RC::GUI::KismetDebugger::Debugger m_debugger{};

public:
    MyTestTab() : RC::GUI::GUITab()
    {
        TabName = L"Kismet Debugger";
    }

    auto render() -> void override
    {
        m_debugger.render();
    }
};

class KismetDebuggerMod : public RC::CppUserModBase
{
private:
    std::shared_ptr<MyTestTab> m_debugger_tab{};

public:
    KismetDebuggerMod() : CppUserModBase()
    {
        ModName = STR("KismetDebugger");
        ModVersion = STR("1.0");
        ModDescription = STR("Debugging interface for kismet bytecode");
        ModAuthors = STR("truman");

        UE4SS_ENABLE_IMGUI()

        m_debugger_tab = std::make_shared<MyTestTab>();
        UE4SSProgram::get_program().add_gui_tab(m_debugger_tab);
    }

    ~KismetDebuggerMod()
    {
        if (m_debugger_tab)
            UE4SSProgram::get_program().remove_gui_tab(m_debugger_tab);
    }
    auto on_program_start() -> void override
    {
    }
    auto on_update() -> void override
    {
    }
};

#define MY_AWESOME_MOD_API __declspec(dllexport)
extern "C"
{
    MY_AWESOME_MOD_API RC::CppUserModBase* start_mod()
    {
        return new KismetDebuggerMod();
    }

    MY_AWESOME_MOD_API void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}

