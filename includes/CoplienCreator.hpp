//
// Created by standrewom on 09.04.18.
//

#ifndef COPLIENFORM_COPLIENCREATOR_HPP
#define COPLIENFORM_COPLIENCREATOR_HPP

#define VERSION "0.01"

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <string>
#include <sys/stat.h>

class CoplienCreator {
private:
	bool isLocal;
	bool isIostream;
	bool isFstream;
	bool isAlgorithms;
	bool isVector;
protected:
	std::vector<std::string> cpps;
	std::vector<std::string> hpps;
	int realFiles;

	void createCppFile(std::string,std::string);
	void createHppFile(std::string,std::string);
	void checkFileForExistance(std::string fullName);
	void getFlagsAndFiles(int, char*[]);
	int checkFolders();
public:
	CoplienCreator();
	virtual ~CoplienCreator();
	CoplienCreator(CoplienCreator const&);
	CoplienCreator& operator=(CoplienCreator const&);
	void makeCoplienFormFiles(int, char*[]);
	static void programVersion();
};


#endif //COPLIENFORM_COPLIENCREATOR_HPP
