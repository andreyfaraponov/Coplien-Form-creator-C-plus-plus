#include "../includes/TTT.hpp"

TTT::TTT() {
}
TTT::~TTT() {
}
TTT::TTT(TTT const& src) {
	*this = src;
}
TTT& TTT::operator=(TTT const& src) {
	static_cast<void>(src);
	return *this;
}
