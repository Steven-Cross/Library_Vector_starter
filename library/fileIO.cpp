#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../includes_usr/fileIO.h"
#include "../includes_usr/constants.h"
#include "../includes_usr/datastructures.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	ifstream myfile;
	myfile.open(filename);
	books.clear();

	if (!myfile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	string line = "";
	stringstream ss(line);
	while (!myfile.eof()) {

		getline(myfile, line);
		book temp;
		temp.title               = getline(ss, line, ',');
		temp.author              = getline(ss, line, ',');
		temp.state               = getline(ss, line, ',');
		temp.loaned_to_patron_id = getline(ss, line, '\n');
		books.push_back(temp);
	}
	myfile.close();
	if (books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}

	return SUCCESS;

}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	ofstream myfile;
	myfile.open(filename);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	if (books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}

	for (int i = 0; i < books.size(); i++) {
		myfile << books[i].title << ',' << books[i].author << ',' << books[i].state << ',' <<
				books[i].loaned_to_patron_id << endl;
	}

	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	ifstream myfile;
		myfile.open(filename);
		patrons.clear();

		if (!myfile.is_open()){
			return COULD_NOT_OPEN_FILE;
		}
		string line = "";
		stringstream ss(line);
		while (!myfile.eof()) {

			getline(myfile, line);
			patron temp;
			temp.patron_id                = getline(ss, line, ',');
			temp.name                     = getline(ss, line, ',');
			temp.number_books_checked_out = getline(ss, line, '\n');
			patrons.push_back(temp);
		}
		myfile.close();
		if (patrons.empty()){
			return NO_PATRONS_IN_LIBRARY;
		}

		return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	ofstream myfile;
		myfile.open(filename);

		if (!myfile.is_open()) {
			return COULD_NOT_OPEN_FILE;
		}
		if (patrons.empty()){
			return NO_BOOKS_IN_LIBRARY;
		}

		for (int i = 0; i < patrons.size(); i++) {
			myfile << patrons[i].patron_id << ',' << patrons[i].name << ',' << patrons[i].number_books_checked_out << endl;
		}

		return SUCCESS;
}
