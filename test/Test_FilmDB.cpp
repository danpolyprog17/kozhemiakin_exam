#include <QtTest>
#include "../FilmDB.h"

class FilmDBTest : public QObject {
    Q_OBJECT

private slots:
    void test_get_good_films_of_genre();

};

// Тест для метода get_good_films_of_genre
void FilmDBTest::test_get_good_films_of_genre() {
    // Создаем тестовый экземпляр FilmDB с тестовыми данными
    QString filePath = "C:/exam/test/test_film_data.txt";
    FilmDB db(filePath);

    // Проверка: фильмы жанра Action с рейтингом >= 8
    QVector<QString> goodActionFilms = db.get_good_films_of_genre(8, "Action");
    QCOMPARE(goodActionFilms.size(), 2);  // Предполагаем, что 2 фильма Action с рейтингом >= 8
    QCOMPARE(goodActionFilms[0], QString("Inception"));
    QCOMPARE(goodActionFilms[1], QString("The_Dark_Knight"));

    // Проверка: фильмы жанра Drama с рейтингом >= 9
    QVector<QString> goodDramaFilms = db.get_good_films_of_genre(9, "Drama");
    QCOMPARE(goodDramaFilms.size(), 1);
    QCOMPARE(goodDramaFilms[0], QString("The_Godfather"));
}

QTEST_APPLESS_MAIN(FilmDBTest)

#include "Test_FilmDB.moc"
