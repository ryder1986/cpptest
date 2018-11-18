TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp tool.cpp

DISTFILES += \
    readme.txt \
    readme_qt.txt

HEADERS += \
    test.h tool.h
unix{
DEFINES+=IS_UNIX
LIBS+=-lpthread
}
win32{
DEFINES+=IS_WIN

}
