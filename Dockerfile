# Используем более новый базовый образ Ubuntu
FROM ubuntu:22.04

# Информация об авторе
LABEL maintainer="KozhemiakinD <kozhemiakindaniel@gmail.com>"

# Установка основных утилит и зависимостей
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    qt6-base-dev \
    qt6-tools-dev-tools \
    git \
    wget
    
# Создаем рабочую директорию
WORKDIR /MyProj_KozhemiakinD_231-3213

# Копируем файлы проекта в контейнер
COPY . .

# Установка переменных среды для Qt6
ENV PATH="/usr/lib/qt6/bin:$PATH"
ENV QT_SELECT=qt6

# Компиляция проекта с использованием qmake
RUN /usr/lib/qt6/bin/qmake && make

# Указываем команду по умолчанию для запуска программы
CMD ["./exam_Program"]
