#include "Item.h"

Item::Item(string name, string installer, string remover, string code, string desc)
	: name(name), installer(installer), remover(remover), code(code), desc(desc) { }

void Item::display(ostream& os){
	os << "Name: " << '"' << name << '"'
		<< ", Installer: " << '"' << installer << '"'
		<< ", Remover: " << '"' << remover << '"'
		<< ", Sequential Code: " << '"' << code << '"';

	if (!desc.empty())
		os << ", Description: " << '"' << desc << '"' << endl;
	else
		os << endl;
}

void Item::graph(ostream& os){
	os << '"' << name << '"' << "->" << '"' << installer << '"' << " [color=green];" << endl;
	os << '"' << name << '"' << "->" << '"' << remover << '"' << " [color=red];" << endl;
}