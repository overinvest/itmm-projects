#include "ITMM_Form.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ITMMGUI::ITMM_Form form;
    Application::Run(% form);
}