QT       += core
CONFIG   += console c++17
CONFIG   -= app_bundle

# Имя целевого исполняемого файла
TARGET = exam_Program
TEMPLATE = app

# Пути к исходникам
SOURCES += \
    main.cpp \
    FilmDB.cpp

# Пути к заголовкам
HEADERS += \
    FilmDB.h

# Определения, если нужно
DEFINES += FILE_PATH="\"film_data.txt\""

# Путь к файлу с данными (если нужно)
RESOURCES += \
    film_data.txt
