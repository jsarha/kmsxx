#include <cstdio>
#include <algorithm>

#include "kms++.h"

#include "test.h"
#include "testoptions.h"

using namespace std;
using namespace kms;

namespace kmsprint {

string width(int w, string str)
{
	str.resize(w, ' ');
	return str;
}

void print_mode(const Videomode &m, const string& ind)
{
	printf("%s%s %6d %4d %4d %4d %4d %d %4d %4d %4d %4d %d  %2d 0x%04x %2d\n",
	       ind.c_str(),
	       m.name().length() == 0? "" : width(11, m.name()).c_str(),
	       m.clock(),
	       m.hdisplay(),
	       m.hsync_start(),
	       m.hsync_end(),
	       m.htotal(),
	       m.hskew(),
	       m.vdisplay(),
	       m.vsync_start(),
	       m.vsync_end(),
	       m.vtotal(),
	       m.vscan(),
	       m.vrefresh(),
	       m.flags(),
	       m.type());
}

void print_crtc(const Crtc &cc, const string& ind)
{
	printf("%sCRTC Id %d BufferId %d %dx%d at %dx%d gamma_size %d\n",
	       ind.c_str(), cc.id(), cc.buffer_id(), cc.width(), 
	       cc.height(), cc.x(), cc.y(), cc.gamma_size());
	
	printf("%s  Mode ", ind.c_str());
	print_mode(cc.mode(), "");	
}

void print_encoder(const Encoder &e, const string& ind)
{
	printf("%sEncoder Id %d type %s\n", ind.c_str(),
	       e.id(), e.get_encoder_type().c_str());

	for (auto cc : e.get_possible_crtcs()) {
		print_crtc(*cc, ind + "  ");
	}
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

void print_connector(const Connector &c, const string& ind)
{
	printf("%sConnector %s Id %d %sconnected\n", ind.c_str(),
	       c.get_fullname().c_str(), c.id(),
	       c.connected() ? "" : "dis");
	if (c.get_subpixel() != SubPixel::Unknown)
		printf("%sSubpixel %s\n", ind.c_str(),
		       subpixel_str[(int)c.get_subpixel()]);
	string ind2 = ind + "  ";
	for (auto enc : c.get_encoders())
		print_encoder(*enc, ind2);
	for (auto mode : c.get_modes())
		print_mode(mode, ind2);	
}

}

using namespace kmsprint;

int main(int argc, char **argv)
{
	Card card;

	if (card.master() == false)
		printf("Not DRM master, modeset may fail\n");

	for (auto conn : card.get_connectors()) {
		print_connector(*conn, string(""));
	}

	for (auto plane : card.get_planes()) {
		plane->print_short();
	}

	return 0;
}

