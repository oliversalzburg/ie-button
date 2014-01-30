// This is the main DLL file.

#include "stdafx.h"

#include "IEButton.h"

namespace IEButton {
  ButtonInstaller^ ButtonInstaller::For(IntPtr ieWindow) {
    return gcnew ButtonInstaller(ieWindow);
  }

  void ButtonInstaller::Install() {
    if( ieWindow.Equals(IntPtr::Zero) ) return;

    HWND hWnd = static_cast<HWND>(ieWindow.ToPointer());
    HWND navigationBar = FindWindowEx(hWnd, nullptr, L"WorkerW", L"Navigation Bar");
    HWND reBar = FindWindowEx(navigationBar, nullptr, L"ReBarWindow32", nullptr);
    HWND hWndControlBar = FindWindowEx(reBar, nullptr, L"ControlBandClass", nullptr);
    HWND hWndToolbar = FindWindowEx(hWndControlBar, nullptr, L"ToolbarWindow32", L"Favorites and Tools Bar");

    LRESULT imageList = SendMessage(hWndToolbar, TB_GETIMAGELIST, 0, 0);
    LRESULT imageListHot = SendMessage(hWndToolbar, TB_GETHOTIMAGELIST, 0, 0);
    LRESULT imageListPressed = SendMessage(hWndToolbar, TB_GETPRESSEDIMAGELIST, 0, 0);

    TBBUTTON buttonToAdd;
    ZeroMemory( &buttonToAdd, sizeof( TBBUTTON ) );
    buttonToAdd.iBitmap = 1;
    buttonToAdd.idCommand = 1;
    buttonToAdd.fsState = TBSTATE_ENABLED;
    buttonToAdd.fsStyle = BTNS_BUTTON|BTNS_AUTOSIZE;

    LRESULT insertButtonResult = SendMessage( hWndToolbar, TB_INSERTBUTTON, 0, (LPARAM)&buttonToAdd );
    
    SendMessage(hWndToolbar, TB_AUTOSIZE, 0, 0);
    SendMessage(hWndToolbar, WM_SIZE, 0, 0);
    SendMessage(hWndControlBar, WM_SIZE, 0, 0);
  }
}
