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
	Videomode(const _drmModeModeInfo* drm_mode);
	Videomode(const Videomode& mode);
	~Videomode();

	Videomode& operator=(const Videomode& other);

	const _drmModeModeInfo* get_drm_mode() const;

	uint32_t get_clock() const;

	uint16_t get_hdisplay() const;
	uint16_t get_hsync_start() const;
	uint16_t get_hsync_end() const;
	uint16_t get_htotal() const;
	uint16_t get_hskew() const;

	uint16_t get_vdisplay() const;
	uint16_t get_vsync_start() const;
	uint16_t get_vsync_end() const;
	uint16_t get_vtotal() const;
	uint16_t get_vscan() const;

	uint32_t get_vrefresh() const;

	uint32_t get_flags() const;
	uint32_t get_type() const;
	const std::string& get_name() const { return m_name; }

private:
	VideomodePriv* m_priv;
	
	std::string m_name;
};
}
