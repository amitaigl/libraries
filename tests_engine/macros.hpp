#include <iostream>

#define TEST(b) do {bool ok = b; if(!ok) { std::cout << "FAILED ON LINE " << __LINE__ << ": \"" << #b << "\"" << std::endl; return;}} while(0)
#define TRY(x) do {try { x; std::cout << "FAILED ON LINE " << __LINE__ << ": \"" << #x << "\"" << std::endl; return; } catch(const std::exception&){}} while(0)
