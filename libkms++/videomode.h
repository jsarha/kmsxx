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

	uint32_t clock() const;

	uint16_t hdisplay() const;
	uint16_t hsync_start() const;
	uint16_t hsync_end() const;
	uint16_t htotal() const;
	uint16_t hskew() const;

	uint16_t vdisplay() const;
	uint16_t vsync_start() const;
	uint16_t vsync_end() const;
	uint16_t vtotal() const;
	uint16_t vscan() const;

	uint32_t vrefresh() const;

	uint32_t flags() const;
	uint32_t type() const;
	const std::string& name() const { return m_name; }

private:
	VideomodePriv* m_priv;

	std::string m_name;
};
}
