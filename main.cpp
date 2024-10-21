#include <QCoreApplication>
#include <QDebug>
#include "FilmDB.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QString filePath = "film_data.txt";  // Указываем относительный путь к файлу
    FilmDB db(filePath);

    // Проверка фильтрации
    qDebug() << "Good films of genre 'Action' with rating >= 8:";
    QVector<QString> goodActionFilms = db.get_good_films_of_genre(8, "Action");
    for (const QString& film : goodActionFilms) {
        qDebug() << film;
    }

    qDebug() << "\nFilms of genre 'Comedy' less than 120 minutes:";
    QVector<QString> comedyFilmsUnder120 = db.get_films_of_genre_less_than(120, "Comedy");
    for (const QString& film : comedyFilmsUnder120) {
        qDebug() << film;
    }

    qDebug() << "\nFilms less than 100 minutes:";
    QVector<QString> filmsUnder100 = db.get_films_less_than(100);
    for (const QString& film : filmsUnder100) {
        qDebug() << film;
    }

    qDebug() << "\nNumber of 'Drama' genre films:" << db.count_genre("Drama");

    return app.exec();
}
