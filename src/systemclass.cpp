#include "systemclass.hpp"

SystemClass::SystemClass() {

  m_Input = 0;
  m_Application = 0;

}

SystemClass::SystemClass(const SystemClass &other) {

  //lol

}

SystemClass::~SystemClass() {

  //lol

}

bool SystemClass::Initialize() {

  int screenWidth, screenHeight;
  bool result;

  // Create and initialize the input object.
  m_Input = new InputClass;

  m_Input->Initialize();

  // Initialize the screen size.
  screenWidth = 0;
  screenHeight = 0;

  // Initialize the X11 window.
  result = InitializeWindow(screenWidth, screenHeight);
  if (!result) {

    return false;

  }

  // Create and initialize the application object.
  m_Application = new ApplicationClass;

  result = m_Application->Initialize(m_videoDisplay, m_hwnd, screenWidth, screenHeight);
  if (!result) {

    return false;

  }

  return true;
}

void SystemClass::Shutdown() {

  // Release the application object.
  if (m_Application) {

    m_Application->Shutdown();
    delete m_Application;
    m_Application = 0;

  }

  // Release the X11 window.
  ShutdownWindow();

  // Release the input object.
  if (m_Input) {

    delete m_Input;
    m_Input = 0;

  }

  return;
}

void SystemClass::Frame() {

    bool done, result;

    // Loop until the application is finished running.
    done = false;
    while (!done) {

        // Read the X11 input.
        ReadInput();

        // Do the frame processing for the application object.
        result = m_Application->Frame(m_Input);
        if (!result) {
            
            done = true;

        }

    }

    return;
}
