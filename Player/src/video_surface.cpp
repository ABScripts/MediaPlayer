#include "include/video_surface.h"

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
    Q_UNUSED(handleType);

    return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB565;
}

bool VideoSurface::present(const QVideoFrame &frame)
{
    Q_UNUSED(frame);

    return true;
}
