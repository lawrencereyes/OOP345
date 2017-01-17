#pragma once
#include <vector>
#include <string>
#include "Product.h"
#include "TaxableProduct.h"
#include <iomanip>

namespace w7
{
	class Sale
	{
	private:
		std::vector<iProduct*> Products;
	public:
		Sale(const char* filename);
		void display(std::ostream& os) const;
		~Sale();
	};
}