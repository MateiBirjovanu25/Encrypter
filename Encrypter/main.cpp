#include <QtWidgets/QApplication>
#include "GUI.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
    testVigenere();
    testCaesar();
    testEncryptFile();
    testXor();
    testEnoch();
    testMat();
    QApplication a(argc, argv);
    GUI mainGui;
    mainGui.show();
    return a.exec();
}
