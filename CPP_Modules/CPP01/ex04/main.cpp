#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char *av[]) {
	try {
		if (ac != 4){
			throw std::invalid_argument("Please provide arguments: <filename> string1 string2!\n");
		}

		std::string file = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];

		if (s1.empty())
			throw std::invalid_argument("String1 can not be empty!\n");
		std::ifstream fin;
		fin.open(file.c_str());
		if (!fin.is_open()) {
			std::cout << "Error: Could not open file " << file << "\n";
			throw std::invalid_argument("");
		}

		std::string outfile = file + ".replace";
		std::ofstream fout;
		fout.open(outfile.c_str());
		if (!fout.is_open()) {
			std::cout << "Error: Could not create output file " << outfile << "\n";
			fin.close();
			throw std::invalid_argument("");
		}

		std::string line;
		while (getline(fin, line)) {
			size_t pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos) {
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
			fout << line;

			if (!fin.eof()) {
				fout << "\n";
			}
		}

		fin.close();
		fout.close();
	} catch (const std::invalid_argument &e) {
		std::cout << e.what();
	}
}