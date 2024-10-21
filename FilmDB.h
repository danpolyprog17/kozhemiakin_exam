#ifndef FILMDB_H
#define FILMDB_H

#include <QString>
#include <QVector>

class FilmDB {
public:
    FilmDB(const QString& filePath);
    QVector<QString> get_good_films_of_genre(int rating, const QString& genre);
    QVector<QString> get_films_of_genre_less_than(int time, const QString& genre);
    QVector<QString> get_films_less_than(int time);
    int count_genre(const QString& genre);

private:
    struct Film {
        QString title;
        QString genre;
        int duration;
        int rating;
    };

    QVector<Film> films;
    void load_data(const QString& filePath);
    void add_film(const QString& title, const QString& genre, int duration, int rating);
};

#endif // FILMDB_H
