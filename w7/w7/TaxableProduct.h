#ifndef TAXABLE_PRODUCT_H
#define TAXABLE_PRODUCT_H
#include "Product.h"
#include <iostream>
namespace w7
{

	class TaxableProduct : public Product
	{
	private:
		char taxType;
	public:
		static const float tax[2];
		TaxableProduct(long p, double c, char t) : Product(p, c), taxType(t) {}
		double getCharge() const;
		void display(std::ostream& os);
		~TaxableProduct() {};
	};
}
#endif