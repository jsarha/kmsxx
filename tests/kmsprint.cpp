#include <cstdio>
#include <algorithm>

#include "kms++.h"

#include "test.h"
#include "testoptions.h"

using namespace std;
using namespace kms;

/*
static const char *connection_str[] = {
	[0] = "<unknown>",
	[DRM_MODE_CONNECTED] = "Connected",
	[DRM_MODE_DISCONNECTED] = "Disconnected",
	[DRM_MODE_UNKNOWNCONNECTION] = "Unknown",
};

static const char *subpixel_str[] = {
	[0] = "<unknown>",
	[DRM_MODE_SUBPIXEL_UNKNOWN] = "unknown",
	[DRM_MODE_SUBPIXEL_HORIZONTAL_RGB] = "horizontal RGB",
	[DRM_MODE_SUBPIXEL_HORIZONTAL_BGR] = "horizontal BGR",
	[DRM_MODE_SUBPIXEL_VERTICAL_RGB] = "vertical RGB",
	[DRM_MODE_SUBPIXEL_VERTICAL_BGR] = "vertical BGR",
	[DRM_MODE_SUBPIXEL_NONE] = "none",
};

void Connector::print_details() const
{
	auto c = m_priv->drm_connector;

	printf("\tEncoder %d\n", c->encoder_id);
	printf("\tType %d\n", c->connector_type);
	printf("\tType id %d\n", c->connector_type_id);
	printf("\tConnection %d\n", c->connection);
	printf("\tSubpixel %s\n", subpixel_str[c->subpixel]);
}

void Connector::print_encoders() const
{
	auto c = m_priv->drm_connector;

	for (int i; i < c->count_encoders; i++)
		card().get_object(c->encoders[i]).print_short();
}

void Connector::print_modes() const
{
	auto c = m_priv->drm_connector;

	for (int i; i < c->count_encoders; i++)
		card().get_object(c->encoders[i]).print_short();
}
*/

int main(int argc, char **argv)
{
	Card card;
	int idx = 0;

	if (card.master() == false)
		printf("Not DRM master, modeset may fail\n");

	for (auto conn : card.get_connectors()) {
		conn->print_short();
	}

	while (auto crtc = card.get_crtc_by_index(idx++)) {
		crtc->print_short();
	}

	for (auto plane : card.get_planes()) {
		plane->print_short();
	}
}
