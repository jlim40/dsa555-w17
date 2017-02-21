//this code comes from:
//http://en.cppreference.com/w/cpp/string/basic_string/hash
#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>
 
int main(int argc, char* argv[])
{
    std::string s(argv[1]);
    
    std::hash<std::string> hash_fn;
	uint32_t tableSize=atoi(argv[2]); 
    size_t hash = hash_fn(s);
 
    std::cout << hash << '\n';
    std::cout << "hash in table: " << hash%tableSize << '\n';
}