#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_

const int KEY_ESCAPE = 0;

class InputClass {

  public:
    
    InputClass();
    InputClass(const InputClass &);
    ~InputClass();
  
    void Initialize();

    void KeyDown(int);
    void KeyUp(int);

    bool IsEscapePressed();

  private:

    bool m_keyboardState[256];

};

#endif
