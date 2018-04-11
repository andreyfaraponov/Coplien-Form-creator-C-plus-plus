//
// Created by standrewom on 09.04.18.
//

#include "../includes/CoplienCreator.hpp"

CoplienCreator::CoplienCreator() {
	isLocal = false;
	isIostream = false;
	isFstream = false;
	isAlgorithms = false;
	isVector = false;
	realFiles = 0;
}
CoplienCreator::~CoplienCreator() {
	if (realFiles > 0)
		std::cout << "Master, all files are ready ;)" << std::endl;
	else
		std::cout << "No classes to create ;(" << std::endl;
}
CoplienCreator::CoplienCreator(CoplienCreator const& src) {
	*this = src;
}
CoplienCreator& CoplienCreator::operator=(CoplienCreator const& src) {
	isLocal = false;
	cpps = std::vector<std::string>(src.cpps);
	hpps = std::vector<std::string>(src.hpps);
	return *this;
}
void CoplienCreator::createCppFile(std::string name, std::string fpath) {
	// srcs
	checkFileForExistance(fpath);
	std::fstream file;
	file.open(fpath.c_str(), std::fstream::out | std::fstream::app);
	file << "#include \"";
	if (!isLocal)
		file << "../includes/";
	file << name << ".hpp\"" << std::endl;
	file << std::endl;
	file << name << "::" << name << "() {" << std::endl;
	file << "}" << std::endl;
	file << name << "::~" << name << "() {" << std::endl;
	file << "}" << std::endl;
	file << name << "::" << name << "(" << name << " const& src) {" << std::endl;
	file << "\t*this = src;" << std::endl;
	file << "}" << std::endl;
	file << name << "& " << name << "::operator=(" << name << " const& src) {" << std::endl;
	file << "\t// TODO" << std::endl;
	file << "\tstatic_cast<void>(src);" << std::endl;
	file << "\treturn *this;" << std::endl;
	file << "}" << std::endl;
	file.close();
}
void CoplienCreator::createHppFile(std::string name, std::string fpath) {
	// includes
	checkFileForExistance(fpath);
	std::fstream file;
	file.open(fpath.c_str(), std::fstream::out | std::fstream::app);
	if (!file.is_open()) {
		std::cout << "File error" << std::endl;
		return;
	}
	std::string hppName(name);
	for (auto &ch: hppName) {
		ch = (char)std::toupper(ch);
	}
	file << "#ifndef " << hppName << "_HPP" << std::endl;
	file << "#define " << hppName << "_HPP" << std::endl;
	if (isIostream) {
		file << "#include <iostream>" << std::endl;
	}
	if (isFstream) {
		file << "#include <fstream>" << std::endl;
	}
	if (isAlgorithms) {
		file << "#include <algorithm>" << std::endl;
	}
	if (isVector) {
		file << "#include <vector>" << std::endl;
	}
	file << std::endl;
	file << "class " << name << " {" << std::endl;
	file << "private:" << std::endl;
	file << "protected:" << std::endl;
	file << "public:" << std::endl;
	file << "\t" << name << "();" << std::endl;
	file << "\tvirtual ~" << name << "();" << std::endl;
	file << "\t" << name << "& operator=(" << name << " const& src);" << std::endl;
	file << "\t" << name << "(" << name << " const& src);" << std::endl;
	file << "};" << std::endl;
	file << std::endl;
	file << "#endif // !" << hppName << "_HPP" << std::endl;
	file.close();
}
void CoplienCreator::checkFileForExistance(std::string fullName) {
	std::fstream file(fullName.c_str());
	if (file) {
		file.close();
		file.open(fullName.c_str(), std::ios::out | std::ios::trunc);
	}
	file.close();
}
void CoplienCreator::getFlagsAndFiles(int a, char *argv[]) {
	for (int i = 1; i < a; ++i) {
		if (std::string(argv[i]).length() == 0) {
			continue;
		} else if (std::string(argv[i]) == std::string("-l")) {
			isLocal = true;
		} else if (std::string(argv[i]) == std::string("-v")) {
			programVersion();
		} else if (std::string(argv[i]) == std::string("-ios")) {
			isIostream = true;
		} else if (std::string(argv[i]) == std::string("-algo")) {
			isAlgorithms = true;
		} else if (std::string(argv[i]) == std::string("-fs")) {
			isFstream = true;
		} else if (std::string(argv[i]) == std::string("-vector")) {
			isVector = true;
		} else if (std::string(argv[i]) == std::string("-all")) {
			isIostream = true;
			isFstream = true;
			isAlgorithms = true;
			isVector = true;
		} else {
			realFiles++;
			argv[i][0] = (char)std::toupper(argv[i][0]);
			cpps.emplace_back(std::string(argv[i]));
			hpps.emplace_back(std::string(argv[i]));
		}
	}
	if (!isLocal && realFiles > 0) {
		checkFolders();
	}
}
void CoplienCreator::makeCoplienFormFiles(int a, char *argv[]) {
	getFlagsAndFiles(a, argv);
	for (size_t i = 0; i < cpps.size(); ++i) {
		if (!isLocal) {
			createHppFile(hpps[i], std::string("includes/") + hpps[i] + std::string(".hpp"));
			createCppFile(cpps[i], std::string("srcs/") + cpps[i] + std::string(".cpp"));
		} else {
			createHppFile(hpps[i], hpps[i] + std::string(".hpp"));
			createCppFile(cpps[i], cpps[i] + std::string(".cpp"));
		}
	}
}
int CoplienCreator::checkFolders() {
	int dir_err = mkdir("includes", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (dir_err == -1) {
		std::cout << "Includes folder exists or can't be created." << std::endl;
	}
	dir_err = mkdir("srcs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (dir_err == -1) {
		std::cout << "Srcs folder exists or can't be created." << std::endl;
	}
	return 0;
}
void CoplienCreator::programVersion() {
	std::cout << "ft_coplien " << VERSION << std::endl;
	std::cout << "Copyright (C) 2018 Anrew Faraponov, Inc." <<std::endl;
}
