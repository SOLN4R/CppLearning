/*
 *	Objective:
 *	Implement file reading and writing operations
 *  in C++ using classes and standard file streams (fstream).
 */

#include <iostream>
#include <fstream>
#include <sstream>

class FileManager
{
private:
	std::string file_name;
public:
	FileManager(const std::string& file_name) : file_name(file_name) {}

	std::string GetFileName() const
	{
		return file_name;
	}

	void WriteToFile(const std::string& data) const
	{
		std::ofstream file(file_name, std::ios::app);
		if (file.is_open())
		{
			file << data << std::endl;
			file.close();
		}
		else
			std::cerr << "Error: Unable to open file for writing!" << std::endl;
	}
	
	std::string ReadFromFile() const
	{
		std::ifstream file(file_name);
		if (file.is_open())
		{
			std::ostringstream buffer;
			buffer << file.rdbuf();
			if (buffer.str().empty())
			{
				std::cout << "File is empty!" << std::endl;
			}
			file.close();
			return buffer.str();
		}
		else
		{
			std::cerr << "Unable to open file!" << std::endl;
			return "";
		}
	}
};

int main()
{
	FileManager file_manager("data.txt");
	file_manager.WriteToFile("Hello, File Handling!");
	file_manager.WriteToFile("C++ is powerful.");

	std::cout << "File " << file_manager.GetFileName() << " content:" << std::endl;
	std::cout << file_manager.ReadFromFile() << std::endl;

	return 0;
}