#include <string.h>
#include <unistd.h>
#include <iostream>

#include "testoptions.h"

TestOptions::TestOptions(int argc, char **argv)
{
	int opt;

	while ((opt = getopt(argc, argv, "m:")) != -1) {
		switch (opt) {
		case 'm':
			m_modename = optarg;
			break;
		default:
			break;
		}
	}
}

TestOptions::~TestOptions()
{

}
