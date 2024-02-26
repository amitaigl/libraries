#include <iostream>

#define TEST(b) do {bool ok = b; if(!ok) std::cout << "FAILED ON LINE " << __LINE__ << ": \"" << #b << "\"" << std::endl;} while(0)
#define TRY(x) do {try { x; throw("noexception"); } catch(const std::exception& e){}} while(0)
