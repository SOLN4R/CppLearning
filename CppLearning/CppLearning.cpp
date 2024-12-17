/*
 *	Objective:
 *	Implement exception handling in file operations to make the program
 *	more robust and error-resistant.
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
		if (!file.is_open()) throw std::runtime_error("Failed to open file: " + file_name);
		file << data << std::endl;
		std::cout << "Data successfully written to " << file_name << std::endl;
		file.close();
	}

	std::string ReadFromFile() const
	{
		std::ifstream file(file_name);
		if (!file.is_open()) throw std::runtime_error("Failed to open file: " + file_name);
		std::ostringstream buffer;
		buffer << file.rdbuf();
		if (buffer.str().empty()) throw std::logic_error("File is empty!");
		file.close();
		return buffer.str();
	}
};

int main()
{
	try
	{
		FileManager file_manager("data.txt");
		file_manager.WriteToFile("Hello, File Handling!");
		file_manager.WriteToFile("C++ is powerful.");

		std::cout << "File " << file_manager.GetFileName() << " content:" << std::endl;
		std::cout << file_manager.ReadFromFile() << std::endl;

		// Modeling an exception ----------------------
		FileManager test("exception.txt");
		std::cout << test.ReadFromFile() << std::endl;
		// --------------------------------------------
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Runtime error: " << e.what() << std::endl;
	}
	catch (const std::logic_error& e) {
		std::cerr << "Logic error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "An unknown error occurred." << std::endl;
	}
	return 0;
}