#include "include/composition.h"

const QString Composition::m_DefaultTitle = "Unknown title";
const QString Composition::m_DefaultGenre = "Unknown genre";
const QDate Composition::m_DefaultDate {2002, 4, 5};

Composition::Composition(QString source, QString title, QString genre, QDate date)
    : m_Source( std::move(source) )
    , m_Title( std::move(title) )
    , m_Genre( std::move(genre) )
    , m_ReleaseDate( std::move(date) )
{
    validateStringType(m_Title, m_DefaultTitle);
    validateStringType(m_Genre, m_DefaultGenre);
    validateDate(m_ReleaseDate, m_DefaultDate);
}

void Composition::validateStringType(QString &toValidate, const QString &defaultValue)
{
    if (toValidate.isEmpty())
    {
        toValidate = defaultValue;
    }
}

void Composition::validateDate(QDate &toValidate, const QDate defaultValue)
{
    if (!toValidate.isValid())
    {
        toValidate = defaultValue;
    }
}

bool Composition::isCompositionValid() const
{
    return !m_Source.isEmpty();
}
