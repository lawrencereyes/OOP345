#include "Product.h"

namespace w7 {
	double Product::getCharge() const
	{
		return charge;
	}

	void Product::display(std::ostream& os)
	{
		os << std::setw(10) << std::right << pID << std::setw(10) << std::right << charge;
	}
}