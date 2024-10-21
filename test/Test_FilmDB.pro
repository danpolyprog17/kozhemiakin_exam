QT       += core testlib
CONFIG   += console c++17
CONFIG   -= app_bundle

# Имя целевого исполняемого файла (тесты)
TARGET = Test_FilmDB
TEMPLATE = app

# Пути к исходникам
SOURCES += \
    Test_FilmDB.cpp \
    ../FilmDB.cpp

# Пути к заголовкам
HEADERS += \
    ../FilmDB.h

# Указываем путь к заголовочным файлам
INCLUDEPATH += ../

# Определение пути к файлу с тестовыми данными
DEFINES += FILE_PATH="\"test/test_film_data.txt\""
