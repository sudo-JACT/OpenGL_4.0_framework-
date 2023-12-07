#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_


class SystemClass {
    
    public:

        SystemClass();
        SystemClass(const SystemClass &);
        ~SystemClass();

        bool Initialize();
        void Shutdown();
        void Frame();

    private:

};

#endif