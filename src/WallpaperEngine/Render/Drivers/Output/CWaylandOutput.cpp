#include "common.h"
#include "CWaylandOutput.h"
#include "../CWaylandOpenGLDriver.h"

using namespace WallpaperEngine::Render::Drivers::Output;

CWaylandOutput::CWaylandOutput (CApplicationContext& context, CVideoDriver& driver, Detectors::CFullScreenDetector& detector) :
    COutput (context, detector),
    m_driver (driver)
{
    const auto PDRIVER = (CWaylandOpenGLDriver*)&driver;
    glm::ivec2 fullw = {0,0};
    for (auto& o : PDRIVER->m_outputs) {
        m_viewports[o->name] = {{0, 0, o->size.x, o->size.y}, o->name};

        fullw = fullw + glm::ivec2{o->size.x, o->size.y};
    }

    m_fullWidth = fullw.x;
    m_fullHeight = fullw.y;
}

CWaylandOutput::~CWaylandOutput ()
{
}

void CWaylandOutput::reset () {
    ;
}

bool CWaylandOutput::renderVFlip () const {
    return false;
}

bool CWaylandOutput::renderMultiple () const  {
    return false; // todo
}

bool CWaylandOutput::haveImageBuffer () const {
    return false;
}

void* CWaylandOutput::getImageBuffer () const {
    return nullptr;
}

void CWaylandOutput::updateRender () const {
    ;
}