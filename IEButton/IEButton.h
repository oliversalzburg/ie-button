// IEButton.h

#pragma once

using namespace System;

namespace IEButton {
  public ref class ButtonInstaller {
  private:
    ButtonInstaller(IntPtr ieWindow) : ieWindow( ieWindow ) {}

    IntPtr ieWindow;

  public:
    // TODO: Add your methods for this class here.
    static ButtonInstaller^ For(IntPtr ieWindow);

    void Install();
  };
}
