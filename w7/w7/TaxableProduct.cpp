#include "TaxableProduct.h"
namespace w7 {
	const float TaxableProduct::tax[2] = { 0.13, 0.08 };

	double TaxableProduct::getCharge() const
	{
		double baseCharge = Product::getCharge();
		float t = 1;
		if (taxType == 'H')
			t += tax[0];
		else
			t += tax[1];
		return t*baseCharge;

	}

	void TaxableProduct::display(std::ostream& os)
	{
		Product::display(os);

		os << " ";
		if (taxType == 'H')
			os << "HST";
		else
			os << "PST";
	}
}