/*
 * parse.h
 *
 *  Created on: 21 февр. 2022 г.
 *      Author: drews
 */
#ifndef PARSE_H_
#define PARSE_H_

#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

namespace Config
{
struct AlgoStep
{
	int _fnum;
	int _lop;
	int _rop;
	int _out;

};

class CmdParser
{
private:
	std::vector<std::string> _tokens;
public:
	CmdParser(int &argc, char **argv);
	const std::string& getCmdOption(const std::string &option) const;
	bool cmdOptionsExist(const std::string &option) const;
	const std::string& getAlgFileName() const;
	const std::string& getVarFileName() const;
	int getArgCount() const;
};

class ThApplication
{
private:
	enum
	{
		_orFinNum = 1,
		_andFunNum = 2,
		_notFunNum = 3,
		_xorFunNum = 4,
		_delayFunNum = 5,
		_rstrFunNum = 6
	};
	const int _fillData = -1;

	std::string _algFileName;
	std::string _varFileName;
	std::vector<AlgoStep> _algo;
	int _iteration;
	std::vector<int> _mvar;

public:
	ThApplication() :
			_iteration(0)
	{
	}
	;
	ThApplication& readConfig(const std::string &algof, const std::string &vaf);
	ThApplication& setIteration(int c);
	ThApplication& run();

};
}

#endif /* PARSE_H_ */
