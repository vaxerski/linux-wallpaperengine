#include "CObject.h"

#include <utility>

using namespace WallpaperEngine;
using namespace WallpaperEngine::Render;

CObject::CObject(CScene* scene, std::string type, Core::CObject *object) :
    Helpers::CContextAware (scene),
    m_scene (scene),
    m_object (object),
    m_type (std::move (type))
{
}

CObject::~CObject ()
= default;

CScene* CObject::getScene () const
{
    return this->m_scene;
}

CContainer* CObject::getContainer () const
{
    return this->getScene ()->getContainer ();
}

int CObject::getId () const
{
    return this->m_object->getId ();
}