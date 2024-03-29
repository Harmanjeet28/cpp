//Harmanjeet Singh Hara
//Student ID#:118624220 , email: hhara@myseneca.ca

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include "Publication.h"
namespace sdds {

	//The Book class is derived from the Publication class.
	class Book : public Publication {
		//The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically. 
	
		char* m_authorName{ nullptr };

	public:
		//Construction
		void setEmpty();
		void setName(const char* name);

		Book();
		Book(const char* name);

		//The rule of three
		~Book();
		Book(const Book&);
		Book& operator=(const Book&);


		//type method
		char type() const;


		//invokes the write of its Base class.
		std::ostream& write(std::ostream& os) const;

		//Read the author name in local variables before setting the attribute to any value.
		std::istream& read(std::istream& is);

		//sets member id and current date.
		void set(int member_id);

		//return true if the author's name exists 
		operator bool();

	};






}
#endif // !SDDS_BOOK_H__
