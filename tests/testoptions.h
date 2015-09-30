#pragma once

#include <cstdio>
#include <map>

#include "kms++.h"

using namespace std;
using namespace kms;

class TestOptions
{
public:
	TestOptions(int argc, char **argv);

	virtual ~TestOptions();

	const string& modename() const { return m_modename; }

private:
	string m_modename;

};
