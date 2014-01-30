using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Demo {
  /// <summary>
  /// Windows API method defitions
  /// </summary>
  static class NativeMethods {
    [DllImport("user32.dll", SetLastError = true)]
    public static extern IntPtr FindWindowEx(IntPtr parentHandle, IntPtr childAfter, string className, string windowTitle);
  }
}
