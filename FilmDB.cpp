#include "FilmDB.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

FilmDB::FilmDB(const QString& filePath) {
    load_data(filePath);
}

void FilmDB::load_data(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open file:" << filePath;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(' ');
        if (details.size() == 4) {
            QString title = details[0];
            QString genre = details[1];
            int duration = details[2].toInt();
            int rating = details[3].toInt();
            add_film(title, genre, duration, rating);
        } else {
            qWarning() << "Invalid line format:" << line;
        }
    }
}

void FilmDB::add_film(const QString& title, const QString& genre, int duration, int rating) {
    films.push_back({title, genre, duration, rating});
}

QVector<QString> FilmDB::get_good_films_of_genre(int rating, const QString& genre) {
    QVector<QString> result;
    for (const auto& film : films) {
        // Сравниваем жанры без учёта регистра букв
        if (QString::compare(film.genre, genre, Qt::CaseInsensitive) == 0 && film.rating >= rating) {
            result.push_back(film.title);
        }
    }
    return result;
}

QVector<QString> FilmDB::get_films_of_genre_less_than(int time, const QString& genre) {
    QVector<QString> result;
    for (const auto& film : films) {
        // Сравниваем жанры без учёта регистра букв
        if (QString::compare(film.genre, genre, Qt::CaseInsensitive) == 0 && film.duration <= time) {
            result.push_back(film.title);
        }
    }
    return result;
}

QVector<QString> FilmDB::get_films_less_than(int time) {
    QVector<QString> result;
    for (const auto& film : films) {
        if (film.duration <= time) {
            result.push_back(film.title);
        }
    }
    return result;
}

int FilmDB::count_genre(const QString& genre) {
    int count = 0;
    for (const auto& film : films) {
        // Сравниваем жанры без учёта регистра букв
        if (QString::compare(film.genre, genre, Qt::CaseInsensitive) == 0) {
            count++;
        }
    }
    return count;
}
