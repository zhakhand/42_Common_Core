#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data myInfo(42, "Jude");
	std::cout << "Address: " << &myInfo << "\n"
			  << "Name: " << myInfo._firstName << "\n"
			  << "ID: " << myInfo._id << "\n";
	uintptr_t serialized = Serializer::serialize(&myInfo);
	std::cout << "Serialized: " << serialized << "\n";
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Address: " << deserialized << "\n" 
			  << "Name: " << deserialized->_firstName << "\n"
			  << "ID: " << deserialized->_id << "\n";
	std::cout << (deserialized == &myInfo ? "Same object\n" : "THEY ARE NOT THE SAME!\n");
}