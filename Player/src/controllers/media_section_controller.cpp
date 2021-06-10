#include "include/controllers/media_section_controller.h"
#include "include/media_source_router.h"

MediaSectionController::MediaSectionController(MediaSourceRouter &mediaSourceRouter)
    : m_MediaSourceRouter { mediaSourceRouter }
{

}

void MediaSectionController::changeSection(int sectionTab)
{
    m_MediaSourceRouter.changeMediaSource(static_cast<SectionTabs>(sectionTab));
}
