#include <stdio.h>
#include <iostream>
#include <cassert>

#include "kms++.h"
#include "helpers.h"

using namespace std;

namespace kms
{
struct VideomodePriv
{
	drmModeModeInfo drm_mode;
};

Videomode::Videomode()
{
	m_priv = new VideomodePriv();
	assert(m_priv->drm_mode);
	m_name = m_priv->drm_mode.name;
}


Videomode::Videomode(const drmModeModeInfo* drm_mode)
{
	m_priv = new VideomodePriv();
	assert(m_priv->drm_mode);
	m_priv->drm_mode = *drm_mode;
	m_name = m_priv->drm_mode.name;
}

Videomode::Videomode(const Videomode& mode)
{
	m_priv = new VideomodePriv();
	assert(m_priv->drm_mode);
	*m_priv = *mode.m_priv;
	m_name = mode.m_name;
}

Videomode::~Videomode()
{
	delete m_priv;
}

Videomode& Videomode::operator=(const Videomode& other)
{
	m_priv->drm_mode = other.m_priv->drm_mode;
	m_name = other.m_name;
	return *this;
}

const drmModeModeInfo* Videomode::get_drm_mode(void) const
{
	return &m_priv->drm_mode;
}

uint32_t Videomode::get_clock() const
{
	return m_priv->drm_mode.clock;
}

uint16_t Videomode::get_hdisplay() const
{
	return m_priv->drm_mode.hdisplay;
}

uint16_t Videomode::get_hsync_start() const
{
	return m_priv->drm_mode.hsync_start;
}

uint16_t Videomode::get_hsync_end() const
{
	return m_priv->drm_mode.hsync_end;
}

uint16_t Videomode::get_htotal() const
{
	return m_priv->drm_mode.htotal;
}

uint16_t Videomode::get_hskew() const
{
	return m_priv->drm_mode.hskew;
}

uint16_t Videomode::get_vdisplay() const
{
	return m_priv->drm_mode.vdisplay;
}

uint16_t Videomode::get_vsync_start() const
{
	return m_priv->drm_mode.vsync_start;
}

uint16_t Videomode::get_vsync_end() const
{
	return m_priv->drm_mode.vsync_end;
}

uint16_t Videomode::get_vtotal() const
{
	return m_priv->drm_mode.vtotal;
}

uint16_t Videomode::get_vscan() const
{
	return m_priv->drm_mode.vscan;
}

uint32_t Videomode::get_vrefresh() const
{
	return m_priv->drm_mode.vrefresh;
}

uint32_t Videomode::get_flags() const
{
	return m_priv->drm_mode.flags;
}

uint32_t Videomode::get_type() const
{
	return m_priv->drm_mode.type;
}

}