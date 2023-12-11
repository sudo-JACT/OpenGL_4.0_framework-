#include "inputclass.hpp"

InputClass::InputClass() {

  //lol

}

InputClass::InputClass(const InputClass &other) {

  //lol

}

InputClass::~InputClass() {

  //lol

}

void InputClass::Initialize() {

  int i;


  // Initialize the keyboard state.
  for (i=0; i < 256; i++) {

    m_keyboardState[i] = false;
    
  }
  
  return;
}


void InputClass::KeyDown(int keySymbol) {

  if (keySymbol == 65307) { 

    m_keyboardState[KEY_ESCAPE] = true; 

  }
  
  return;
}


void InputClass::KeyUp(int keySymbol) {

  if (keySymbol == 65307) { 

    m_keyboardState[KEY_ESCAPE] = false; 

  }
  
  return;
}


bool InputClass::IsEscapePressed() {

  return m_keyboardState[KEY_ESCAPE];

}
