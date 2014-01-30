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
    HWND toolsBar = FindWindowEx(controlBar, nullptr, L"ToolbarWindow32", L"Favorites and Tools Bar");
  }
}
