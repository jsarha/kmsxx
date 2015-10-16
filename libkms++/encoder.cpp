#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cassert>
#include <xf86drm.h>
#include <xf86drmMode.h>

#include "kms++.h"

using namespace std;

namespace kms
{

struct EncoderPriv
{
	drmModeEncoderPtr drm_encoder;
};

static const map<int, string> encoder_types = {
#define DEF_ENC(c) { DRM_MODE_ENCODER_##c, #c }
	DEF_ENC(NONE),
	DEF_ENC(DAC),
	DEF_ENC(TMDS),
	DEF_ENC(LVDS),
	DEF_ENC(TVDAC),
	DEF_ENC(VIRTUAL),
	DEF_ENC(DSI),
#undef DEF_ENC
};

Encoder::Encoder(Card &card, uint32_t id)
	:DrmObject(card, id, DRM_MODE_OBJECT_ENCODER)
{
	m_priv = new EncoderPriv();
	m_priv->drm_encoder = drmModeGetEncoder(this->card().fd(), this->id());
	assert(m_priv->drm_encoder);
}

Encoder::~Encoder()
{
	drmModeFreeEncoder(m_priv->drm_encoder);
	delete m_priv;
}

void Encoder::print_short() const
{
	auto e = m_priv->drm_encoder;

	printf("Encoder %d, %d\n", id(),
	       e->encoder_type);
}

Crtc* Encoder::get_crtc() const
{
	if (m_priv->drm_encoder->crtc_id)
		return card().get_crtc(m_priv->drm_encoder->crtc_id);
	else
		return 0;
}

vector<Crtc*> Encoder::get_possible_crtcs() const
{
	unsigned bits = m_priv->drm_encoder->possible_crtcs;
	vector<Crtc*> crtcs;

	for (int idx = 0; bits; idx++, bits >>= 1) {
		if ((bits & 1) == 0)
			continue;
		try {
			auto crtc = card().get_crtc_by_index(idx);
			crtcs.push_back(crtc);
		}
		catch (const invalid_argument& ia) {
			cerr << "Crtc " << to_string(idx) << " not found" <<
				endl;
		}
	}

	return crtcs;
}

const string& Encoder::get_encoder_type() const
{
	return encoder_types.at(m_priv->drm_encoder->encoder_type);
}

}
