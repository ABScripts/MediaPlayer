#include "include/controllers/media_section_controller.h"
#include "include/media_source_router.h"

#include <QDebug>

MediaSectionController::MediaSectionController(MediaSourceRouter &mediaSourceRouter)
    : m_MediaSourceRouter { mediaSourceRouter }
{

}

void MediaSectionController::changeSection(int sectionTab)
{
    m_MediaSourceRouter.changeMediaSource(static_cast<SectionTabs>(sectionTab));
    qDebug() << "Section changed to " << sectionTab;
    //m_MediaSourceRouter.changeSection(sectionTab);
}
