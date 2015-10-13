#pragma once

#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define NO_PARAM (CmdOption(false))
#define HAS_PARAM (CmdOption(true))

class CmdOption
{
public:
	CmdOption(bool has_param) :
	        m_has_param(has_param), m_is_set(false) { }
        bool has_param() const { return m_has_param; }

	void oset() { m_is_set = true; }
	void pset(const string& p) { m_param = p; oset(); }
        bool is_set() const { return m_is_set; }
        const string& param() const { return m_param; }
private:
	bool m_has_param;

	bool m_is_set;
	string m_param;	
};

class CmdOptions
{
public:
	CmdOptions(int argc, char **argv, map<string, CmdOption>& opts) :
		m_opts(opts) {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				auto ii = m_opts.find(&argv[i][1]);
				if (ii == m_opts.end())
					throw invalid_argument(
						string(&argv[i][1]) +
						": unknown option");
				if ((*ii).second.has_param()) {
					if (++i == argc)
						throw invalid_argument(
							(*ii).first +
							": parameter missing");
					(*ii).second.pset(argv[i]);
				} else {
					(*ii).second.oset();
				}
			} else {
				m_params.push_back(argv[i]);
			}
		}
	}
	bool is_set(const string& name) const {
		return m_opts.at(name).is_set();
	}
	const string& param(const string& name) const { 
		return m_opts.at(name).param();
	}
	const vector<string>& params() const { return m_params; }
private:
	map<string, CmdOption>& m_opts;
	vector<string> m_params;
};
