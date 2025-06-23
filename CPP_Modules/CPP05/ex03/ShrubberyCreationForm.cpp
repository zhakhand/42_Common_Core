#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this == &other) return *this;
	AForm::operator=(other);
	this->_target = other.getTarget();
	return *this; 
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getSigned())
		throw FormUnsignedException("Form is not signed!\n");
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException("Form requires higher grade to execute!\n");
	std::string outfile = this->getTarget() + "_shrubbery";
	std::ofstream fout;
	fout.open(outfile.c_str());
	if (!fout.is_open()) {
		throw GradeTooLowException("System could not create output file!\n");
	}
	system("aplay /home/dzhakhan/Downloads/digging.wav > /dev/null 2>&1");
	fout << "            .        +          .      .          .\n"
		 << "     .            _        .                    .\n"
		 << " ,              /;-._,-.____        ,-----.__\n" 
		 << "((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
		 << " `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
		 << "                      ,    `./  \\:. `.   )==-'  .\n"
		 << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
		 << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
		 << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
		 << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
		 << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
    	 << "       	     \\:  `  X` _| _,\\/'   .-'\n"
         << ".               \":._:`\\____  /:'  /      .           .\n"
         << "                    \\::.  :\\/:'  /              +\n"
         << "   .                 `.:.  /:'  }      .\n"
         << "           .           ):_(:;   \\           .\n"
         << "                      /:. _/ ,  |\n"
         << "                   . (|::.     ,`                  .\n"
         << "     .                |::.    {\\\n"
   		 << "                      |::.\\  \\ `.\n"
		 << "                      |:::(\\    |\n"
		 << "              O       |:::/{ }  |                  (o\n"
		 << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
		 << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";
		 if (!fout.eof()) 
		 	fout << "\n";
		fout.close();
		//sleep(3);
		std::cout << "Shrubbery has been planted at " << this->getTarget() << "\n";
}