#include <cstdio>
#include <algorithm>

#include "kms++.h"
#include "utils/testpat.h"

#include "test.h"
#include "testoptions.h"

using namespace std;
using namespace kms;

int main(int argc, char **argv)
{
	Card card;

	if (card.master() == false)
		printf("Not DRM master, modeset may fail\n");

	card.print_short();

}
