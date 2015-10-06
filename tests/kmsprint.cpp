#include <cstdio>
#include <algorithm>

#include "kms++.h"

#include "test.h"
#include "testoptions.h"

using namespace std;
using namespace kms;

namespace kmsprint {

void print_details(const Videomode &m, const string& ind)
{
	printf("%s%s\t%06d %04d %04d %04d %04d %d  %04d %04d %04d %04d %d  %02d 0x%04x %02d\n",
	       ind.c_str(),
	       m.get_name().c_str(),
	       m.get_clock(),
	       m.get_hdisplay(),
	       m.get_hsync_start(),
	       m.get_hsync_end(),
	       m.get_htotal(),
	       m.get_hskew(),
	       m.get_vdisplay(),
	       m.get_vsync_start(),
	       m.get_vsync_end(),
	       m.get_vtotal(),
	       m.get_vscan(),
	       m.get_vrefresh(),
	       m.get_flags(),
	       m.get_type());
}

static const char *subpixel_str[] = {
	[0] = "<unknown>",
	[SubPixel::Unknown] = "Unknown",
	[SubPixel::Horizontal_RGB] = "Horizontal RGB",
	[SubPixel::Horizontal_BGR] = "Horizontal BGR",
	[SubPixel::Vertical_RGB] = "Vertical RGB",
	[SubPixel::Vertical_BGR] = "Vertical BGR",
	[SubPixel::None] = "None",
};

void print_details(const Connector &c, const string& ind)
{
	printf("%sEncoder %s Id %d %sconnected\n", ind.c_str(),
	       c.get_fullname().c_str(), c.id(),
	       c.connected() ? "" : "dis");
	printf("%sType %d\n", ind.c_str(), c.get_connector_type());
	printf("%sSubpixel %s\n", ind.c_str(),
	       subpixel_str[(int)c.get_subpixel()]);
	string ind2 = ind + " ";
	for (auto mode : c.get_modes())
		print_details(mode, ind2);
}

}

using namespace kmsprint;

int main(int argc, char **argv)
{
	Card card;

	if (card.master() == false)
		printf("Not DRM master, modeset may fail\n");

	for (auto conn : card.get_connectors()) {
		print_details(*conn, string(""));
	}

	for (auto plane : card.get_planes()) {
		plane->print_short();
	}

	return 0;
}

