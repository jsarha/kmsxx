#pragma once

#include <vector>

#include "drmobject.h"


struct _drmModeModeInfo;

namespace kms
{
struct VideomodePriv;

class Videomode
{
public:
	Videomode();
	Videomode(const Videomode& mode);
	~Videomode();

	Videomode& operator=(const Videomode& other);

	const _drmModeModeInfo* get_drm_mode() const;

	uint32_t clock() const { return m_clock; }

	uint16_t hdisplay() const { return m_hdisplay; }
	uint16_t hsync_start() const { return m_hsync_start; }
	uint16_t hsync_end() const { return m_hsync_end; }
	uint16_t htotal() const { return m_htotal; }
	uint16_t hskew() const { return m_hskew; }

	uint16_t vdisplay() const { return m_vdisplay; }
	uint16_t vsync_start() const { return m_vsync_start; }
	uint16_t vsync_end() const { return m_vsync_end; }
	uint16_t vtotal() const { return m_vtotal; }
	uint16_t vscan() const { return m_vscan; }

	uint32_t vrefresh() const { return m_vrefresh; }

	uint32_t flags() const { return m_flags; }
	uint32_t type() const { return m_type; }

	const std::string& get_name() const { return m_name; }

protected:
	Videomode(const _drmModeModeInfo* drm_mode);

private:
	initialize(const _drmModeModeInfo* drm_mode);
	
	uint32_t m_clock;

	uint16_t m_hdisplay;
	uint16_t m_hsync_start;
	uint16_t m_hsync_end;
	uint16_t m_htotal;
	uint16_t m_hskew;

	uint16_t m_vdisplay;
	uint16_t m_vsync_start;
	uint16_t m_vsync_end;
	uint16_t m_vtotal;
	uint16_t m_vscan;

	uint32_t m_vrefresh;

	uint32_t m_flags;
	uint32_t m_type;

	std::string m_name;
};
}
