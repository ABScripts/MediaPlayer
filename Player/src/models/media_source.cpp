#include "include/models/media_source.h"

MediaSourceListModel::MediaSourceListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int MediaSourceListModel::getCurrentSelectedIndex() const
{
    return m_CurrentSelectedIndex;
}

void MediaSourceListModel::setCurrentSelectedIndex(int index)
{
    if (m_CurrentSelectedIndex != index)
    {
        m_CurrentSelectedIndex = index;
        emit currentSelectedIndexChanged();
    }
}
