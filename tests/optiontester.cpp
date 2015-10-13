#include <cstdio>
#include <algorithm>

#include "cmdoptions.h"

using namespace std;

static map<string, CmdOption> options = {
	{ "test", NO_PARAM },
	{ "test2", HAS_PARAM },
};

int main(int argc, char **argv)
{
	CmdOptions opts(argc, argv, options);

	for (auto p : options)
		printf("Option %s set %d param %s\n", 
		       p.first.c_str(), opts.is_set(p.first),
		       opts.param(p.first).c_str());;

	return 0;
}
