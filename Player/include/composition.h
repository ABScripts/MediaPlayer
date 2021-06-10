#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <QString>
#include <QDate>

class Composition {
public:
    Composition(QString source = "", QString title = "", QString genre = "", QDate date = QDate());

    const static QString m_DefaultTitle;
    const static QString m_DefaultGenre;
    const static QDate m_DefaultDate;

    QString m_Source;
    QString m_Title;
    QString m_Genre;
    QDate m_ReleaseDate;

    void validateStringType(QString &toValidate, const QString &defaultValue);
    void validateDate(QDate &toValidate, const QDate defaultValue);
    bool isCompositionValid() const;
};

#endif
