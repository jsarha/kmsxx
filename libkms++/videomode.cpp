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

Videomode::Videomode(const drmModeModeInfo* drm_mode)
{
	initialize(drm_mode);
}

void Videomode::initialize(const _drmModeModeInfo* drm_mode)
{
	assert(drm_mode);

	m_clock = drm_mode->clock;

	m_hdisplay = drm_mode->hdisplay;
	m_hsync_start = drm_mode->hsync_start;
	m_hsync_end = drm_mode->hsync_end;
	m_htotal = drm_mode->htotal;
	m_hskew = drm_mode->hskew;

	m_vdisplay = drm_mode->vdisplay;
	m_vsync_start = drm_mode->vsync_start;
	m_vsync_end = drm_mode->vsync_end;
	m_vtotal = drm_mode->vtotal;
	m_vscan = drm_mode->vscan;

	m_vrefresh = drm_mode->vrefresh;

	m_flags = drm_mode->flags;
	m_type = drm_mode->type;

	m_name = drm_mode->name;
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
