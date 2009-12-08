
#ifndef H_PLUGINWINDOWWIN
#define H_PLUGINWINDOWWIN

#include "Win/win_common.h"
#include "PluginWindow.h"

#include <map>

namespace FB {

    class PluginWindowWin : public PluginWindow
    {
    public:
        PluginWindowWin(HWND hWnd);
        virtual ~PluginWindowWin();
        static LRESULT CALLBACK _WinProc(HWND hWnd, UINT uMsg, WPARAM wParam,
                                                          LPARAM lParam);
        HWND getHWND() { return m_hWnd; }

        typedef std::map<void*,PluginWindowWin*> PluginWindowMap;
    protected:
        static PluginWindowMap m_windowMap;

        bool WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParamm, LRESULT lRes);
    	WNDPROC lpOldWinProc;
        HWND m_hWnd;
    };

};

#endif // H_PLUGINWINDOWWIN