#include <iostream>
#include "parse.h"

int main(int argc, char *argv[])
{
	using std::cout;
	using std::endl;
	const int fileCount = 2;
	const int maxArgCount = 4;
	const int defIterCount = 1;

	Config::CmdParser cla(argc, argv);
	Config::ThApplication app;

	if (cla.getArgCount() == fileCount && !cla.cmdOptionsExist("-n"))
	{
		app.readConfig(cla.getAlgFileName(), cla.getVarFileName());
		app.setIteration(defIterCount);

	}
	else if (cla.getArgCount() == maxArgCount && cla.cmdOptionsExist("-n"))
	{
		app.readConfig(cla.getAlgFileName(), cla.getVarFileName());
		app.setIteration(std::stoi(cla.getCmdOption("-n")));

	}
	else
	{
		cout << "technological_algotitm [-n NUM]"
				"code_file_name vars_file_name" << endl;
		return 0;
	}

	app.run();

	return 0;
}
