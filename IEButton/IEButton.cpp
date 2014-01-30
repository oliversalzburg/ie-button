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
    HWND controlBar = FindWindowEx(reBar, nullptr, L"ControlBandClass", nullptr);
    HWND hWndToolbar = FindWindowEx(controlBar, nullptr, L"ToolbarWindow32", L"Favorites and Tools Bar");

    TBADDBITMAP tbAddBitmap;
    tbAddBitmap.hInst = HINST_COMMCTRL;
    tbAddBitmap.nID = IDB_VIEW_SMALL_COLOR;

    int stdidx = SendMessage(hWndToolbar, TB_ADDBITMAP, 0, (LPARAM)&tbAddBitmap);

    TBBUTTON buttonToAdd = {
      stdidx + VIEW_LARGEICONS, 
      1337, 
      TBSTATE_ENABLED, 
      BTNS_BUTTON
    };

    SendMessage(hWndToolbar, TB_INSERTBUTTON, 1, (LPARAM)&buttonToAdd);
  }
}
