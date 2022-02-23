/*
 * parse.cpp
 *
 *  Created on: 21 февр. 2022 г.
 *      Author: drews
 */
#include "parse.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "compute.h"

namespace Config
{

CmdParser::CmdParser(int &argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		_tokens.push_back(std::string(argv[i]));
	}
}

const std::string& CmdParser::getCmdOption(const std::string &option) const
{
	std::vector<std::string>::const_iterator itr;

	itr = std::find(_tokens.begin(), _tokens.end(), option);
	if (itr != _tokens.end() && ++itr != _tokens.end())
	{
		return *itr;
	}
	static const std::string empty_string(" ");
	return empty_string;
}

const std::string& CmdParser::getAlgFileName() const
{
	std::vector<std::string>::const_iterator itr;
	if (getArgCount() > 1)
	{
		itr = _tokens.end();
		itr = itr - 2;
		return *itr;
	}
	static const std::string empty_string(" ");
	return empty_string;

}

const std::string& CmdParser::getVarFileName() const
{
	std::vector<std::string>::const_iterator itr;
	if (getArgCount() > 0)
	{
		itr = _tokens.end();
		itr = itr - 1;
		return *itr;
	}
	static const std::string empty_string(" ");
	return empty_string;
}

int CmdParser::getArgCount() const
{
	return _tokens.size();
}

bool CmdParser::cmdOptionsExist(const std::string &option) const
{
	return std::find(_tokens.begin(), _tokens.end(), option) != _tokens.end();
}

ThApplication& ThApplication::readConfig(const std::string &algof,
		const std::string &vaf)
{
	std::ifstream conf;
	AlgoStep sttmp;

	conf.open(algof);

	if (conf.is_open())
	{
		while (!conf.eof())
		{
			conf >> sttmp._fnum;
			conf >> sttmp._lop;
			if (sttmp._fnum == _notFunNum || sttmp._fnum == _delayFunNum)
			{
				sttmp._rop = _fillData;
			}
			else
			{
				conf >> sttmp._rop;
			}
			conf >> sttmp._out;
			_algo.push_back(sttmp);
		}
		conf.close();
	}
	else
	{
		std::cout << "File open error.";
	}

	conf.open(vaf);

	if (conf.is_open())
	{
		std::copy(std::istream_iterator<int>(conf),
				std::istream_iterator<int>(), std::back_inserter(_mvar));
		conf.close();
	}
	else
	{
		std::cout << "File open error.";
	}

	return *this;
}

ThApplication& ThApplication::setIteration(int c)
{
	_iteration = c;
	return *this;
}

ThApplication& ThApplication::ThApplication::run()
{
	for (int i = 0; i < _iteration; i++)
	{
		for (int j = 0; j < _algo.size(); j++)
		{
			switch (_algo[j]._fnum)
			{
			case _orFinNum:
				_mvar[_algo[j]._out] = orFunc(_mvar[_algo[j]._lop],
						_mvar[_algo[j]._rop]);
				break;
			case _andFunNum:
				_mvar[_algo[j]._out] = andFunc(_mvar[_algo[j]._lop],
						_mvar[_algo[j]._rop]);
				break;
			case _notFunNum:
				_mvar[_algo[j]._out] = notFunc(_mvar[_algo[j]._lop]);
				break;
			case _xorFunNum:
				_mvar[_algo[j]._out] = xorFunc(_mvar[_algo[j]._lop],
						_mvar[_algo[j]._rop]);
				break;
			case _delayFunNum:
				_mvar[_algo[j]._out] = delayLine(_mvar[_algo[j]._lop]);
				break;
			case _rstrFunNum:
				_mvar[_algo[j]._out] = rsTrigger(_mvar[_algo[j]._lop],
						_mvar[_algo[j]._rop]);
				break;
			default:
				break;
			}
		}

		std::cout << "Iteration " << i << ": ";
		for (int k = 0; k < _mvar.size(); k++)
		{
			std::cout << _mvar[k] << " ";
		}
		std::cout << std::endl;
	}
	return *this;
}

}

