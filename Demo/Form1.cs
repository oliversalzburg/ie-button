using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using IEButton;

namespace Demo {
  public partial class Form1 : Form {
    public Form1() {
      InitializeComponent();
    }

    private void Form1_Load( object sender, EventArgs e ) {
      IntPtr ieFrame = NativeMethods.FindWindowEx( IntPtr.Zero, IntPtr.Zero, "IEFrame", null );
      if( ieFrame.Equals( IntPtr.Zero ) ) {
        MessageBox.Show( "No IE window found" );
        Application.Exit();
      }

      ButtonInstaller installer = ButtonInstaller.For(ieFrame);
      installer.Install();
    }
  }
}