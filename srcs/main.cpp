#include "../includes/CoplienCreator.hpp"

int main(int a, char *argv[]) {
	CoplienCreator creator;
	if (a == 1) {
		std::cout << "ft_coplien: missing file names" << std::endl;
		std::cout << "usage: ft_coplien "
		<< "[-l -ios -fs -algo -vector -all ] name1, name2,... nameN" << std::endl;
		return 0;
	}
	else
		creator.makeCoplienFormFiles(a, argv);
	return 0;
}