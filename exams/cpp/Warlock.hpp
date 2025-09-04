#include <string>
#include <iostream>

class Warlock {
	private:

		std::string name;
		std::string title;

	public:

		Warlock(std::string name, std::string title);
		// Copy
		// Copy Assignment
		~Warlock();

		std::string getName() const;
		std::string getTitle() const;

		void setTitle(const std::string &str);

		void introduce() const;
};