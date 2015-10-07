#pragma once

#include <vector>
#include "drmobject.h"

namespace kms
{

struct EncoderPriv;

class Encoder : public DrmObject
{
	friend class Card;
public:
	void print_short() const;

	Crtc* get_crtc() const;
	std::vector<Crtc*> get_possible_crtcs() const;

	uint32_t get_encoder_type() const;
private:
	Encoder(Card& card, uint32_t id);
	~Encoder();

	EncoderPriv* m_priv;
};
}
