#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <map>

namespace fs = std::filesystem;
using namespace std;

int main() {

	fs::path filePath = "H:\\crypt\\txt.docx";
	uint64_t fileSize = 0;
	map <int, uint64_t> freq;
	int shift = 128; // to convert from char to uint and back

	if (fs::exists(filePath))
	{
		fileSize = fs::file_size(filePath);
		std::cout << "File size: " << fs::file_size(filePath) << " bytes\n";

		ifstream stream(filePath, std::ifstream::binary);
		vector<char> buffer(fileSize);
		stream.read(buffer.data(), fileSize);

		for (auto c : buffer)
		{
			if (freq.count(c + shift) == 0)
			{
				freq[c + shift] = 1;
			}
			else
			{
				++freq[c + shift];
			}
		}

		for (auto [key, val] : freq)
		{
			cout << key << ": " << val << "\n";
			for (auto i = 0; i < val; ++i)
			{
				cout << '=';
			}
			cout << "\n";
		}

	}
	else
	{
		std::cout << "File does not exist";
	}


	return 0;

}

